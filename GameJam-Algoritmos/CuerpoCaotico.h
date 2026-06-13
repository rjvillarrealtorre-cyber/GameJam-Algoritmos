#pragma once
#include "Entidad.h"

using namespace System::Drawing;

ref class CuerpoCaotico : public Entidad {
protected:
	int colorR;
	int colorG;
	int colorB;

	int tipoForma; // 0 Rectángulo, 1 Triángulo, 2 Romboide

public:

	CuerpoCaotico(
		int px,
		int py,
		int dim,
		int multi
	) : Entidad(px, py, dim, multi)
	{
		Random^ r =
			gcnew Random(Guid::NewGuid().GetHashCode());

		// Velocidades aleatorias
		dxO = r->Next(3, 13);
		dyO = r->Next(3, 13);

		if (r->Next(0, 2) == 0) dxO *= -1;
		if (r->Next(0, 2) == 0) dyO *= -1;

		dx = dxO * multiplicador;
		dy = dyO * multiplicador;

		// Tamaño real para colisiones
		ancho = dimensiones;
		alto = dimensiones;

		// Color aleatorio
		colorR = r->Next(120, 256);
		colorG = r->Next(0, 90);
		colorB = r->Next(160, 256);

		// Forma aleatoria
		tipoForma = r->Next(0, 3);
	}

	virtual void mover() override {
		x += dx;
		y += dy;

		if (x > 1024) {
			x = 1;
		}
		else if (x + ancho < 0) {
			x = 1020;
		}

		if (y > 576) {
			y = 1;
		}
		else if (y + alto < 0) {
			y = 570;
		}
	}

	virtual void mostrar(Graphics^ gr) override = 0;

	Color getColor() {
		return Color::FromArgb(
			colorR,
			colorG,
			colorB
		);
	}

	int getTipoForma() {
		return tipoForma;
	}

	bool esCuerpoCaotico() override { return true; }
};