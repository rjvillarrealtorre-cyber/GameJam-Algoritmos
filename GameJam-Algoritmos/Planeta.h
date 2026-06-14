#pragma once
#include "Entidad.h"
#include <math.h>

enum TipoPlaneta {
	TIERRA,
	SATURNO,
	COMUN
};

ref class Planeta : public Entidad {
private:
	float anguloRotacion;
	float velocidadRotacion;

	int radioOrbita;
	float anguloOrbita;
	float velocidadOrbita;
	float velocidadOrbitaOriginal;

	int tipo;
	Brush^ color;
	String^ nombre;
public:
	Planeta(String^ n, int px, int py, int dim, int ro, 
		float ao, float vo, Brush^ color, TipoPlaneta t) : Entidad(px, py, dim) {
		//---
		nombre = n;
		this->color = color;
		this->tipo = t;
		radioOrbita = ro;
		anguloOrbita = ao;
		velocidadOrbita = vo;
		velocidadOrbitaOriginal = vo;

		anguloRotacion = 0;
		velocidadRotacion = 5;
		ancho = dimensiones * 2;
		alto = dimensiones * 2;
	}

	void rotar() {
		anguloRotacion += velocidadRotacion;

		if (anguloRotacion >= 360)
			anguloRotacion = 0;
	}

	void cambioVelocidad(float mul) override {
		multiplicador = mul;
		velocidadOrbita = velocidadOrbitaOriginal * multiplicador;
	}
	 
	void mostrarNombre(Graphics^ gr, Font^ fuente) {
		gr->DrawString(nombre, fuente, Brushes::White, x - dimensiones, y + dimensiones / 2);
	}

	void mostrar(Graphics^ gr) override {
		gr->FillEllipse(color, x - dimensiones / 2, y - dimensiones / 2, dimensiones, dimensiones);
		// Tierra
		if (tipo == TIERRA) {
			gr->FillEllipse(Brushes::ForestGreen, x - 12, y - 8, 14, 10);
			gr->FillEllipse(Brushes::ForestGreen, x + 3, y - 2, 12, 8);
			gr->FillEllipse(Brushes::LimeGreen, x - 5, y + 8, 10, 7);
			gr->FillEllipse(Brushes::Green, x + 8, y + 5, 8, 6 );
		}

		// Saturno
		if (tipo == SATURNO) {
			gr->DrawEllipse(gcnew Pen(Color::LightGray, 3), x - dimensiones, y - 10, dimensiones * 2, 20 );
			gr->DrawEllipse(gcnew Pen(Color::Silver, 2), x - dimensiones - 8, y - 14, dimensiones * 2 + 16, 28 );
		}

		float radRot = anguloRotacion * 3.1416f / 180;

		int x2 = x + (dimensiones / 2) * cos(radRot);

		int y2 = y + (dimensiones / 2) * sin(radRot);

		gr->DrawLine(Pens::White, x, y, x2, y2);
	}

	float getAnguloRotacion() { return anguloRotacion; }
	float getVelocidadRotacion() {return velocidadRotacion;}

	int getRadioOrbita() { return radioOrbita;}
	float getAnguloOrbita() { return anguloOrbita;}
	float getVelocidadOrbita() { return velocidadOrbita;}

	void setAnguloOrbita(float p) { anguloOrbita = p; }
	void setVelocidadOrbita(float p) { velocidadOrbita = p; }
};