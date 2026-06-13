#pragma once
#include "Nave.h"
#include "Nivel.h"

ref class Juego {
private:
	Nave* nave;
	array<Nivel^>^ niveles;
	int nivelActual;
public:
	Juego() {
		niveles = gcnew array<Nivel^>(1);
		niveles[0] = gcnew Nivel(gcnew Bitmap("recursos\\fondonvl1.jpg"));

		nave = new Nave(30, 490, 30);
	}

	~Juego() {
		delete nave;
		for each (Nivel ^ n in niveles) delete n;
		delete niveles;
	}

	void manejarBuclePrincipal(Graphics^ gr) {
		//Borrar (final)
		gr->DrawImage(niveles[nivelActual]->getFondo(), 0, 0, 1024, 576);

		//Nave
		nave->mover();
		nave->mostrar(gr);
	}
};