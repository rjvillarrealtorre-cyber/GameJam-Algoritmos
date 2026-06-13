#pragma once
#include "Entidad.h"

ref class Asteroide : public Entidad {
private:
public:
	Asteroide(int px, int py, int dim, int multi) : Entidad(px, py, dim, multi) {
		aleatorizarVelocidad();
		if (py > 300) dy *= -1;
	}

	bool desaparecera() {
		if (x < 0 || y < 0) return true;
		return false;
	}

	void mover() override {
		x -= dx;
		y += dy;
	}

	void mostrar(Graphics^ gr) override {
		//Cuerpo
		array<Point>^ puntosAsteroide = gcnew array<Point>(10);
		puntosAsteroide[0] = Point(x + dimensiones / 2, y);
		puntosAsteroide[1] = Point(x + 5 * dimensiones / 4, y + dimensiones / 4);
		puntosAsteroide[2] = Point(x + 3 * dimensiones / 2, y + dimensiones);
		puntosAsteroide[3] = Point(x + 5 * dimensiones / 4, y + 7 * dimensiones / 4);
		puntosAsteroide[4] = Point(x + dimensiones, y + 2 * dimensiones);
		puntosAsteroide[5] = Point(x + dimensiones / 4, y + 7 * dimensiones / 4);
		puntosAsteroide[6] = Point(x - dimensiones / 4, y + 3 * dimensiones / 2);
		puntosAsteroide[7] = Point(x - dimensiones / 2, y + dimensiones);
		puntosAsteroide[8] = Point(x - dimensiones / 4, y + dimensiones / 2);
		puntosAsteroide[9] = Point(x + dimensiones / 8, y + dimensiones / 8);

		gr->FillPolygon(Brushes::Silver, puntosAsteroide);

		// Cráteres
		gr->FillEllipse(Brushes::DimGray, x + dimensiones / 4,
			y + dimensiones / 2, dimensiones / 3, dimensiones / 3);

		gr->FillEllipse(Brushes::DimGray, x + 3 * dimensiones / 4,
			y + dimensiones,dimensiones / 4, dimensiones / 4);

		gr->FillEllipse(Brushes::DimGray, x, y + 5 * dimensiones / 4,
			dimensiones / 5, dimensiones / 5);
	}
};