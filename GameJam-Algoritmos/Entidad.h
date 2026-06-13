#pragma once

using namespace System::Drawing;
using namespace System;

class Entidad {
protected:
	float multiplicador;
	int xO, yO;
	int x, y;
	int dx, dy;
	int dimensiones;
public:
	Entidad(int px, int py, int dim) {
		x = px; y = py;
		xO = x; yO = y;
		dimensiones = dim;
		multiplicador = 1;
	}

	void aleatorizarVelocidad() {
		Random^ rand1 = gcnew Random();
		dx = rand1->Next(1, 10);
		Random^ rand2 = gcnew Random();
		dy = rand2->Next(1, 10);
	}

	virtual void mostrar(Graphics^ gr) = 0;

	void setX(int p) { x = p; }
	void setY(int p) { y = p; }
	void setDx(int p) { dx = p; }
	void setDy(int p) { dy = p; }

	int getX() { return x; }
	int getY() { return y; }
	/*int getVelocidad() { return velocidad; }
	int getVelocidad() { return velocidad; }*/
};