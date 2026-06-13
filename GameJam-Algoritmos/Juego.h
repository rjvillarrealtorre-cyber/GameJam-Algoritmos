#pragma once
#include "Nave.h"
#include "Nivel.h"
#include "Fuente.h"

ref class Juego {
private:
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

		nave = new Nave(30, 490, 30);
	}

	~Juego() {
		delete nave;
		for each (Nivel ^ n in niveles) delete n;
		delete niveles;
		delete fuente;
	}

	void dibujarMV(Graphics^ gr) {
		gr->DrawImage(manejoVel, 740, 430, 286 * 0.9, 141 * 0.9);
	}

	void manejarVelocidades(float mod) {
		multiplicadorGlobal += mod;
		if (multiplicadorGlobal <= 0.5) multiplicadorGlobal = 0.5;
		nave->cambioVelocidad(multiplicadorGlobal);
	}

	void manejarBuclePrincipal(Graphics^ gr) {
		//Borrar (final)
		gr->DrawImage(niveles[nivelActual]->getFondo(), 0, 0, 1024, 576);

		//Nave
		nave->mover();
		nave->mostrar(gr);

		//Otros
		dibujarMV(gr);
		String^ tt = multiplicadorGlobal + "";
		gr->DrawString(tt, fuente->getFuenteFinal(), Brushes::Black, 860.0f, 500.0f);
	}
};