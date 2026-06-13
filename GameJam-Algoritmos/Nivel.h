#pragma once
#include "Utilidades.h"
#include "Asteroide.h"
#include "Cometa.h"
#include "SistemaSolar.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class Nivel {
private:
	Bitmap^ fondo;
	SistemaSolar^ ss;
	List<Entidad^>^ cuerposC;

	int contador;
	int contadorAsteroide;
	int intervaloAparicionAsteroide;
	int contadorCometa;
	int intervaloAparicionCometa;
public:
	Nivel(Bitmap^ f) {
		cuerposC = gcnew List<Entidad^>;
		ss = gcnew SistemaSolar(500, 290);
		contador = 0;
		contadorAsteroide = 0;
		intervaloAparicionAsteroide = 5 * CONVERSOR_CONT;
		contadorCometa = 0;
		intervaloAparicionCometa = 4 * CONVERSOR_CONT;
		fondo = f;
	}

	~Nivel() {
		for each (Entidad ^ cc in cuerposC) delete cc;
		delete fondo;
	}

	void manejarCC(Graphics^ gr, int multiplicadorGlobal) {
		//Agregar asteroides
		if (contadorAsteroide >= intervaloAparicionAsteroide) {
			Random^ rx = gcnew Random();
			Random^ ry = gcnew Random();
			cuerposC->Add(gcnew Asteroide(rx->Next(1000, 1025), ry->Next(1, 576), 20, multiplicadorGlobal));
			contadorAsteroide = 0;
		}
		//Agregar cometas
		if (contadorCometa >= intervaloAparicionCometa) {
			Random^ rx = gcnew Random();
			Random^ ry = gcnew Random();
			cuerposC->Add(gcnew Cometa(rx->Next(1000, 1025), ry->Next(1, 576), 20, multiplicadorGlobal));
			contadorCometa = 0;
		}

		//Eliminar cuerpos celetes
		for (int i = cuerposC->Count - 1; i >= 0; i--) {
			if (cuerposC[i]->getX() < 0 || cuerposC[i]->getY() > 576) {
				delete cuerposC[i];
				cuerposC->RemoveAt(i);
			}
		}

		//Mover cuerpos celetes
		for each (Entidad^ cc in cuerposC) {
			cc->mover();
			cc->mostrar(gr);
		}
	}

	void manejarEntidades(Graphics^ gr, int multiplicadorGlobal) {
		manejarCC(gr, multiplicadorGlobal);
		ss->manejarSistemaSolar(gr, multiplicadorGlobal);
	}

	void aumentarContadorAsteroide() { contadorAsteroide++; }
	void aumentarContadorCometa() { contadorCometa++; }
	void aumentarContador() { contador++; }
	int getContador() { return contador; }
	int getContadorAsteroide() { return contadorAsteroide; }

	Bitmap^ getFondo() { return fondo; }
	List<Entidad^>^ getCC() { return cuerposC; }
	SistemaSolar^ getSistemaSolar() { return ss; }
};