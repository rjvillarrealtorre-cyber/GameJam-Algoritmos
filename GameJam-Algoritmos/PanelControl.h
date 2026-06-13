#pragma once
#include "Utilidades.h"

using namespace System::Drawing;

ref class PanelControl {
private:
	Bitmap^ hud;
public:
	PanelControl() {
		hud = gcnew Bitmap("recursos\\hud.jpg");
	}

	~PanelControl() {
		delete hud;
	}

	void mostrarPanel(Graphics^ gr, Nave^ nave, Font^ fuente, int contadorNivel) {
		gr->DrawImage(hud, 0, 0, 175, 130);
		int espaciado = 25;

		int segundos = static_cast<int>((CONVERSOR_SEG * contadorNivel)) % 60;
		int minutos = (CONVERSOR_SEG * contadorNivel) / 60;
		String^ segMostrar = segundos < 10 ? "0" + segundos : "" + segundos;
		String^ minMostrar = minutos < 10 ? "0" + minutos : "" + minutos;

		String^ Tiempo = "Tiempo: " + minMostrar + ":" + segMostrar;
		gr->DrawString(Tiempo, fuente, Brushes::PaleGreen, 15, 15 + espaciado * 0);

		String^ numCol = "# Colisines: " + nave->getColisiones();
		gr->DrawString(numCol, fuente, Brushes::PaleGreen, 15, 15 + espaciado * 1);

		String^ en = "Energia: " + nave->getEnergia();
		gr->DrawString(en, fuente, Brushes::PaleGreen, 15, 15 + espaciado * 2);

		String^ v = "Vida: " + nave->getVida();
		gr->DrawString(v, fuente, Brushes::PaleGreen, 15, 15 + espaciado * 3);
	}
};