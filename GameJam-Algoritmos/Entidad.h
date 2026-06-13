#pragma once

using namespace System::Drawing;
using namespace System;

class Entidad {
protected:
	int x, y;
	int dx, dy;
	int dimensiones;
public:
	Entidad(int px, int py, int dX, int dY, int dim) {
		x = px; y = py;
		dx = dX; dy = dY;
		dimensiones = dim;
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