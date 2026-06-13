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
public:
	Planeta(int px, int py, int dim, int ro, float ao, float vo,
		Brush^ color, TipoPlaneta t) : Entidad(px, py, dim)
	{
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

	void mostrar(Graphics^ g) override {
		g->FillEllipse(color, x - dimensiones / 2, y - dimensiones / 2, dimensiones, dimensiones);
		// Tierra
		if (tipo == TIERRA) {
			g->FillEllipse(Brushes::ForestGreen, x - 12, y - 8, 14, 10);
			g->FillEllipse(Brushes::ForestGreen, x + 3, y - 2, 12, 8);
			g->FillEllipse(Brushes::LimeGreen, x - 5, y + 8, 10, 7);
			g->FillEllipse(Brushes::Green, x + 8, y + 5, 8, 6 );
		}

		// Saturno
		if (tipo == SATURNO) {
			g->DrawEllipse(gcnew Pen(Color::LightGray, 3), x - dimensiones, y - 10, dimensiones * 2, 20 );
			g->DrawEllipse(gcnew Pen(Color::Silver, 2), x - dimensiones - 8, y - 14, dimensiones * 2 + 16, 28 );
		}

		float radRot = anguloRotacion * 3.1416f / 180;

		int x2 = x + (dimensiones / 2) * cos(radRot);

		int y2 = y + (dimensiones / 2) * sin(radRot);

		g->DrawLine(Pens::White, x, y, x2, y2);
	}

	float getAnguloRotacion() { return anguloRotacion; }
	float getVelocidadRotacion() {return velocidadRotacion;}

	int getRadioOrbita() { return radioOrbita;}
	float getAnguloOrbita() { return anguloOrbita;}
	float getVelocidadOrbita() { return velocidadOrbita;}

	void setAnguloOrbita(float p) { anguloOrbita = p; }
	void setVelocidadOrbita(float p) { velocidadOrbita = p; }
};