#pragma once
#include "Nave.h"
#include "Nivel.h"
#include "Fuente.h"
#include "PanelControl.h"

ref class Juego {
private:
	PanelControl^ pc;
	Bitmap^ manejoVel;
	Fuente^ fuente;
	Nave* nave;
	array<Nivel^>^ niveles;
	int nivelActual;

	float multiplicadorGlobal;
public:
	Juego() {
		fuente = gcnew Fuente();
		manejoVel = gcnew Bitmap("recursos\\manejoVelocidad.png");
		niveles = gcnew array<Nivel^>(1);
		niveles[0] = gcnew Nivel(gcnew Bitmap("recursos\\fondonvl1.jpg"));
		multiplicadorGlobal = 1;
		pc = gcnew PanelControl();

		nave = new Nave(30, 490, 30);
	}

	~Juego() {
		delete nave;
		for each (Nivel ^ n in niveles) delete n;
		delete niveles;
		delete fuente;
		delete pc;
	}

	void dibujarMV(Graphics^ gr) {
		gr->DrawImage(manejoVel, 740, 430, 286 * 0.9, 141 * 0.9);
	}

	void manejarVelocidades(float mod) {
		multiplicadorGlobal += mod;
		if (multiplicadorGlobal <= 0.5) multiplicadorGlobal = 0.5;
		nave->cambioVelocidad(multiplicadorGlobal);
	}

	void dibujarMultiplicador(Graphics^ gr) {
		int anchoTexto = 10;
		if (multiplicadorGlobal != Math::Floor(multiplicadorGlobal)
			|| multiplicadorGlobal >= 10)
			anchoTexto = 25;
		else if (multiplicadorGlobal >= 10 && 
			multiplicadorGlobal != Math::Floor(multiplicadorGlobal))
			anchoTexto = 35;

		String^ tt = multiplicadorGlobal + "";
		short centrar = (70 - anchoTexto) / 2;
		gr->DrawString(tt, fuente->getFuenteFinal(), Brushes::Black, 
			835 + centrar - 6, 500);
	}

	void manejarBuclePrincipal(Graphics^ gr) {
		//Borrar (final)
		gr->DrawImage(niveles[nivelActual]->getFondo(), 0, 0, 1024, 576);

		//Nave
		nave->mover();
		nave->mostrar(gr);

		//Panel
		pc->mostrarPanel(gr, nave, fuente->getFuenteFinal(), niveles[nivelActual]->getContador());

		//Otros
		dibujarMV(gr);
		dibujarMultiplicador(gr);

		niveles[nivelActual]->aumentarContador();
	}

	Nave* getNave() { return nave; }
};