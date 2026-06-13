#pragma once
#include "Nave.h"

class Juego {
private:
	Nave* nave;
public:
	Juego() {
		nave = new Nave(30, 490, 7, 10, 30);
	}

	~Juego() {
		delete nave;
	}

	void manejarBuclePrincipal(Graphics^ gr) {
		//Borrar (temporal)
		gr->Clear(Color::Black);

		//Nave
		nave->mostrar(gr);
	}
};