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
	Nave^ nave;
	array<Nivel^>^ niveles;
	int nivelActual;

	float multiplicadorGlobal;
public:
	Juego() {
		nivelActual = 0;
		fuente = gcnew Fuente();
		manejoVel = gcnew Bitmap("recursos\\manejoVelocidad.png");
		multiplicadorGlobal = 1;
		pc = gcnew PanelControl();

		nave = gcnew Nave(30, 490, 30);

		// ---------- Inicializar nivel ---------
		//Nivel 1
		niveles = gcnew array<Nivel^>(1);
		niveles[0] = gcnew Nivel(gcnew Bitmap("recursos\\fondonvl1.jpg"));
		niveles[0]->getSistemaSolar()->agregarPlaneta(gcnew Planeta(0, 0, 21,  70, 4.0f, 5, Brushes::Blue, COMUN));
		niveles[0]->getSistemaSolar()->agregarPlaneta(gcnew Planeta(0, 0, 27, 115, 3.0f, 4, Brushes::Khaki, COMUN));
		niveles[0]->getSistemaSolar()->agregarPlaneta(gcnew Planeta(0, 0, 35, 160, 2.3f, 3, Brushes::DeepSkyBlue, TIERRA));
		niveles[0]->getSistemaSolar()->agregarPlaneta(gcnew Planeta(0, 0, 31, 205, 1.8f, 2, Brushes::IndianRed, COMUN));
		niveles[0]->getSistemaSolar()->agregarPlaneta(gcnew Planeta(0, 0, 58, 260, 1.2f, 1, Brushes::Beige, SATURNO));
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

		//Nave
		nave->cambioVelocidad(multiplicadorGlobal);
		//CuerposC (asterioides y cometas)
		for each (Entidad ^ cc in niveles[nivelActual]->getCC())
			cc->cambioVelocidad(multiplicadorGlobal);
		//Planetas
		for each (Planeta ^ p in niveles[nivelActual]->getSistemaSolar()->getPlanetas())
			p->cambioVelocidad(multiplicadorGlobal);
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

	void manejarColisiones() {
		for each(Entidad ^ cc in niveles[nivelActual]->getCC()) {
			if (!verificarColisiones(nave, cc)) continue;

			nave->setVida(nave->getVida() - 10);
		}

		for (int i = niveles[nivelActual]->getCC()->Count - 1; i >= 0; i--) {
			if (!verificarColisiones(nave, niveles[nivelActual]->getCC()[i])) return;

			nave->setVida(nave->getVida() - 10);
			delete niveles[nivelActual]->getCC()[i];
			niveles[nivelActual]->getCC()->RemoveAt(i);
		}
	}

	void manejarBuclePrincipal(Graphics^ gr) {
		//Borrar (final)
		gr->DrawImage(niveles[nivelActual]->getFondo(), 0, 0, 1024, 576);

		//Nave
		nave->mover();
		nave->mostrar(gr);

		//Entidades
		niveles[nivelActual]->manejarEntidades(gr, multiplicadorGlobal);

		//Panel
		pc->mostrarPanel(gr, nave, fuente->getFuenteFinal(), niveles[nivelActual]->getContador());

		//Otros
		dibujarMV(gr);
		dibujarMultiplicador(gr);
		manejarColisiones();

		//Contadores
		niveles[nivelActual]->aumentarContador();
		niveles[nivelActual]->aumentarContadorAsteroide();
		niveles[nivelActual]->aumentarContadorCometa();
	}

	Nave^ getNave() { return nave; }
};