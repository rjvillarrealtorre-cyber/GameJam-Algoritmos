#pragma once
#include "Planeta.h"
#include <math.h>

using namespace System::Collections::Generic;

ref class SistemaSolar {
private:
	List<Planeta^>^ planetas;
	int solX;
	int solY;
public:
	SistemaSolar(int xSol, int ySol) {
		solX = xSol;
		solY = ySol;
		planetas = gcnew List<Planeta^>();
	}

	~SistemaSolar() {
		for each (Planeta ^ p in planetas) delete p;
	}

	void agregarPlaneta(Planeta^ planeta) {
		planetas->Add(planeta);
	}

	void mover() {
		for each (Planeta ^ p in planetas) {
			p->setAnguloOrbita(p->getAnguloOrbita() + p->getVelocidadOrbita());

			if (p->getAnguloOrbita() >= 360) p->setAnguloOrbita(0);

			float rad = p->getAnguloOrbita() * 3.1416f / 180;
			int x = solX + p->getRadioOrbita() * cos(rad);
			int y = solY + p->getRadioOrbita() * sin(rad);

			p->setX(x);
			p->setY(y);
			p->rotar();
		}
	}

	void mostrar(Graphics^ gr) {

		// Órbitas
		for each (Planeta ^ p in planetas) {

			gr->DrawEllipse(Pens::DimGray, solX - p->getRadioOrbita(), 
				solY - p->getRadioOrbita(), p->getRadioOrbita() * 2, 
				p->getRadioOrbita() * 2 );
		}

		// Sol
		gr->FillEllipse(Brushes::Gold, solX - 25, solY - 25, 50, 50 );

		// Planetas
		for each (Planeta ^ p in planetas)
			p->mostrar(gr);
	}

	void manejarSistemaSolar(Graphics^ gr, int multiplicador) {
		mover();
		mostrar(gr);
	}

	List<Planeta^>^ getPlanetas() { return planetas; }
};