#pragma once
#include "Entidad.h"

using namespace System;
using namespace System::Drawing;

class Nave : public Entidad {
private:
	float angulo;
public:
	Nave(int px, int py, int dim) : Entidad(px, py, dim) {
		aleatorizarVelocidad();
		angulo = 0;
	}

	void mostrar(Graphics^ gr) override {
		//Base
		// dimensiones = 4k
		array<Point>^ puntosRectangulo = gcnew array<Point>(4);
		puntosRectangulo[0] = Point(x + 2 * dimensiones / 4, y + dimensiones / 2);
		puntosRectangulo[1] = Point(x + 18 * dimensiones / 4, y + dimensiones / 2);
		puntosRectangulo[2] = Point(x + 18 * dimensiones / 4, y + 7 * dimensiones / 4);
		puntosRectangulo[3] = Point(x + 2 * dimensiones / 4, y + 7 * dimensiones / 4);		
		gr->FillPolygon(Brushes::LightGray, puntosRectangulo);

		//Trail de energía
		int anchoTrail = dimensiones;
		int altoTrail = dimensiones * 2;
		gr->FillEllipse(Brushes::DeepSkyBlue, x - anchoTrail / 2, y + dimensiones / 8, anchoTrail, altoTrail);

		//Cola
		array<Point>^ puntosCola = gcnew array<Point>(4);
		puntosCola[0] = Point(x, y + 7 * dimensiones / 8);
		puntosCola[1] = Point(x + dimensiones / 2, y + 7 * dimensiones / 8);
		puntosCola[2] = Point(x + dimensiones / 2, y + 11 * dimensiones / 8);
		puntosCola[3] = Point(x, y + 11 * dimensiones / 8);
		gr->FillPolygon(Brushes::Gray, puntosCola);

		//Alas
		array<Point>^ puntosAlaSuperior = gcnew array<Point>(4);
		int offsetAla = dimensiones;
		puntosAlaSuperior[0] = Point(x + offsetAla, y + dimensiones / 2);
		puntosAlaSuperior[1] = Point(x + offsetAla + dimensiones * 2, y + dimensiones / 2);
		puntosAlaSuperior[2] = Point(x + offsetAla + 6 * dimensiones / 4, y);
		puntosAlaSuperior[3] = Point(x + offsetAla + dimensiones * 2 / 4, y);
		gr->FillPolygon(Brushes::DarkGray, puntosAlaSuperior);

		array<Point>^ puntosAlaInferior = gcnew array<Point>(4);
		puntosAlaInferior[0] = Point(x + offsetAla, y + 7 * dimensiones / 4);
		puntosAlaInferior[1] = Point(x + offsetAla + dimensiones * 2, y + 7 * dimensiones / 4);
		puntosAlaInferior[2] = Point(x + offsetAla + 6 * dimensiones / 4, y + 9 * dimensiones / 4);
		puntosAlaInferior[3] = Point(x + offsetAla + dimensiones * 2 / 4, y + 9 * dimensiones / 4);
		gr->FillPolygon(Brushes::DarkGray, puntosAlaInferior);

		// Cabeza
		array<Point>^ puntosCabeza = gcnew array<Point>(3);
		puntosCabeza[0] = Point(x + 18 * dimensiones / 4, y + dimensiones / 2);
		puntosCabeza[1] = Point(x + 18 * dimensiones / 4, y + 7 * dimensiones / 4);
		puntosCabeza[2] = Point(x + 24 * dimensiones / 4, y + 9 * dimensiones / 8);
		gr->FillPolygon(Brushes::DarkGray, puntosCabeza);
	}

	bool determinarVictoriaDerrota() {
		if (x + 22 * dimensiones / 4 >= 1000 && y < 50) return true;
		return false;
	}

	void mover() {
		//if (determinarVictoriaDerrota()) return;
		//General
		x += dx;
		y -= dy;
		//Determinar si la nave regresa
		if (x > 1024 || x < 0 || y > 576 || y + 10 * dimensiones / 4 < 0) {
			x = xO;
			y = yO;
			aleatorizarVelocidad();
		}
	}
};