#pragma once
#include "CuerpoCaotico.h"

enum TipoForma {
	TRIANGULO,
	RECTANGULO,
	ROMBOIDE
};

ref class CuerpoCaoticoSimple : public CuerpoCaotico {
public:

	CuerpoCaoticoSimple(
		int px,
		int py,
		int dim,
		int multi
	) : CuerpoCaotico(px, py, dim, multi)
	{
	}

	void mostrar(Graphics^ gr) override {

		SolidBrush^ brocha =
			gcnew SolidBrush(getColor());

		switch (tipoForma) {

		case TRIANGULO: {
			gr->FillRectangle(
				brocha,
				x,
				y,
				dimensiones,
				dimensiones
			);
			break;
		}
		case RECTANGULO: {
			array<Point>^ tri =
				gcnew array<Point>(3);

			tri[0] =
				Point(x + dimensiones / 2, y);

			tri[1] =
				Point(x, y + dimensiones);

			tri[2] =
				Point(x + dimensiones,
					y + dimensiones);

			gr->FillPolygon(
				brocha,
				tri
			);
			break;
		}
		case ROMBOIDE: {
			array<Point>^ rom =
				gcnew array<Point>(4);

			rom[0] =
				Point(x + dimensiones / 4, y);

			rom[1] =
				Point(x + dimensiones, y);

			rom[2] =
				Point(x + 3 * dimensiones / 4,
					y + dimensiones);

			rom[3] =
				Point(x,
					y + dimensiones);

			gr->FillPolygon(
				brocha,
				rom
			);
			break;
		}

		}

		delete brocha;
	}
};