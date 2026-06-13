#pragma once
#include "Entidad.h"

ref class Cometa : public Entidad {
private:
public:
	Cometa(int px, int py, int dim, int multi) : Entidad(px, py, dim, multi) {
		aleatorizarVelocidad();

		if (py > 300) y *= -1;
	}

	bool desaparecera() {
		if (x < -3 * dimensiones || y < -3 * dimensiones ||
			y > 576 + 3 * dimensiones) return true;
		return false;
	}

	void mover() override {
		x -= dx;
		y += dy;
	}

	void mostrar(Graphics^ gr) override {
		// Cola
		array<Point>^ cola = gcnew array<Point>(6);
		cola[0] = Point(x + dimensiones / 2, y + dimensiones / 2);
		cola[1] = Point(x + 2 * dimensiones, y);
		cola[2] = Point(x + 4 * dimensiones, y - dimensiones / 2);
		cola[3] = Point(x + 5 * dimensiones, y + dimensiones / 2);
		cola[4] = Point(x + 4 * dimensiones, y + 3 * dimensiones / 2);
		cola[5] = Point(x + 2 * dimensiones, y + dimensiones);
		gr->FillPolygon(Brushes::LightCyan, cola);

		// Cola interior
		array<Point>^ colaInterior = gcnew array<Point>(4);
		colaInterior[0] = Point(x + dimensiones / 2, y + dimensiones / 2);
		colaInterior[1] = Point(x + 3 * dimensiones, y + dimensiones / 4);
		colaInterior[2] = Point(x + 4 * dimensiones, y + dimensiones / 2);
		colaInterior[3] = Point(x + 3 * dimensiones, y + 3 * dimensiones / 4);
		gr->FillPolygon(Brushes::White, colaInterior);

		// Núcleo
		gr->FillEllipse(Brushes::LightSteelBlue, x, y, dimensiones, dimensiones );
		// Centro
		gr->FillEllipse(Brushes::White, x + dimensiones / 4, y + dimensiones / 4, dimensiones / 2, dimensiones / 2 );

		// Detalles
		gr->FillEllipse(Brushes::AliceBlue, x - dimensiones / 8, y + dimensiones / 3, dimensiones / 3, dimensiones / 3 );
		gr->FillEllipse(Brushes::AliceBlue, x + 5 * dimensiones / 8, y + dimensiones / 8, dimensiones / 4, dimensiones / 4 );
	}
};