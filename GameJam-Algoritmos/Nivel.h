#pragma once
#include "Utilidades.h"
#include "Asteroide.h"
#include "Cometa.h"
#include "SistemaSolar.h"
#include "CuerpoCaoticoSimple.h"
#include "Cinematica.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class Nivel {
private:
	Bitmap^ fondo;
	SistemaSolar^ ss;
	List<Entidad^>^ cuerposC;
	Cinematica^ cinFinal;
	Cinematica^ venDerrota;
	bool caotico;

	int contador;
	int contadorAsteroide;
	int intervaloAparicionAsteroide;
	int contadorCometa;
	int intervaloAparicionCometa;
public:
	Nivel(Bitmap^ f, Bitmap^ fonCin, bool caotico) {
		this->caotico = caotico;
		cuerposC = gcnew List<Entidad^>;
		ss = gcnew SistemaSolar(500, 290);
		cinFinal = gcnew Cinematica(fonCin);
		contador = 0;
		contadorAsteroide = 0;
		intervaloAparicionAsteroide = caotico ? 2 * CONVERSOR_CONT :  5 * CONVERSOR_CONT;
		contadorCometa = 0;
		intervaloAparicionCometa = caotico ? 1 * CONVERSOR_CONT : 4 * CONVERSOR_CONT;
		fondo = f;

		venDerrota = gcnew Cinematica(gcnew Bitmap("recursos\\tableta.jpg"));
		venDerrota->agregarLinea("¡Uh, oh! La nave colapsó, al quedarse sin vida");
		venDerrota->agregarLinea("ni energía. ¡Pero no te desanimes! Puedes");
		venDerrota->agregarLinea("intentar de nuevo...");
		venDerrota->agregarLinea(" ");
		venDerrota->agregarLinea("[PRESIONA ESC PARA REINTENTAR]");
	}

	~Nivel() {
		for each (Entidad ^ cc in cuerposC) delete cc;
		delete cinFinal;
		delete fondo;
		delete venDerrota;
	}

	void manejarCC(Graphics^ gr, int multiplicadorGlobal) {
		//Agregar asteroides
		if (contadorAsteroide >= intervaloAparicionAsteroide) {
			Random^ rx = gcnew Random();
			Random^ ry = gcnew Random();
			int px = caotico ? rx->Next(1, 1025) : rx->Next(1000, 1025);
			int py = ry->Next(1, 576);
			cuerposC->Add(gcnew Asteroide(px, py, 20, multiplicadorGlobal));
			contadorAsteroide = 0;
		}
		//Agregar cometas
		if (contadorCometa >= intervaloAparicionCometa) {
			Random^ rx = gcnew Random();
			Random^ ry = gcnew Random();
			int px = caotico ? rx->Next(1, 1025) : rx->Next(1000, 1025);
			int py = ry->Next(1, 576);
			cuerposC->Add(gcnew Cometa(px, py, 20, multiplicadorGlobal));
			contadorCometa = 0;
		}

		//Eliminar cuerpos celetes
		for (int i = cuerposC->Count - 1; i >= 0; i--) {
			if (cuerposC[i]->esCuerpoCaotico()) continue;

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

	void manejarEntidades(Graphics^ gr, Font^ fuente, int multiplicadorGlobal) {
		manejarCC(gr, multiplicadorGlobal);
		ss->manejarSistemaSolar(gr, fuente, multiplicadorGlobal, caotico);
	}

	void aumentarContadorAsteroide() { contadorAsteroide++; }
	void aumentarContadorCometa() { contadorCometa++; }
	void aumentarContador() { contador++; }
	int getContador() { return contador; }
	int getContadorAsteroide() { return contadorAsteroide; }
	void setCaotico(bool p) { caotico = p; }
	bool getCaotico() { return caotico; }

	Bitmap^ getFondo() { return fondo; }
	List<Entidad^>^ getCC() { return cuerposC; }
	SistemaSolar^ getSistemaSolar() { return ss; }
	Cinematica^ getCinematica() { return cinFinal; }
	Cinematica^ getVenDerrota() { return venDerrota; }
};