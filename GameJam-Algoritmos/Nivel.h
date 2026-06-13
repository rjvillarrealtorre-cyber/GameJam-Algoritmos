#pragma once

using namespace System;
using namespace System::Drawing;

ref class Nivel {
private:
	Bitmap^ fondo;
	int contador;
	int contadorAsteroide;
public:
	Nivel(Bitmap^ f) {
		fondo = f;
	}

	~Nivel() {
		delete fondo;
	}

	void aumentarContador() { contador++; }
	int getContador() { return contador; }

	Bitmap^ getFondo() { return fondo; }
};