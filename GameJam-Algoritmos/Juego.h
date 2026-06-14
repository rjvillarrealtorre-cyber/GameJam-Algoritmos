#pragma once
#include "Nave.h"
#include "Nivel.h"
#include "Fuente.h"
#include "PanelControl.h"


ref class Juego {
private:
	PanelControl^ pc;
	Bitmap^ manejoVel;
	Fuente^ fuente;
	Nave^ nave;
	array<Nivel^>^ niveles;
	int nivelActual;

	bool teclaEsc;
	bool puedeCambiarNivel;
	bool adicionFinal;

	float multiplicadorGlobal;
public:
	void buildNivel1() {
		niveles[0] = gcnew Nivel(gcnew Bitmap("recursos\\fondonvl1.jpg"), gcnew Bitmap("recursos\\tableta.jpg"), false);
		niveles[0]->getSistemaSolar()->agregarPlaneta(gcnew Planeta("Mercurio", 0, 0, 21, 70, 4.0f, 5, Brushes::Blue, COMUN));
		niveles[0]->getSistemaSolar()->agregarPlaneta(gcnew Planeta("Venus", 0, 0, 27, 115, 3.0f, 4, Brushes::Khaki, COMUN));
		niveles[0]->getSistemaSolar()->agregarPlaneta(gcnew Planeta("Tierra", 0, 0, 35, 160, 2.3f, 3, Brushes::DeepSkyBlue, TIERRA));
		niveles[0]->getSistemaSolar()->agregarPlaneta(gcnew Planeta("Marte", 0, 0, 31, 205, 1.8f, 2, Brushes::IndianRed, COMUN));
		niveles[0]->getSistemaSolar()->agregarPlaneta(gcnew Planeta("Saturno", 0, 0, 58, 260, 1.2f, 1, Brushes::Beige, SATURNO));

		niveles[0]->getCinematica()->agregarLinea("¡NIVEL 1 COMPLETO! Recarguemos combustible...");
		niveles[0]->getCinematica()->agregarLinea("¡Espera! ¿Qué es eso que se acerca?");
		niveles[0]->getCinematica()->agregarLinea("Es un... ¿Es lo que pienso que es? Un...");
		niveles[0]->getCinematica()->agregarLinea("¡Un agujero negro!");
		niveles[0]->getCinematica()->agregarLinea("CONTINUARÁ...");
		niveles[0]->getCinematica()->agregarLinea("");
		niveles[0]->getCinematica()->agregarLinea("[PRESIONE ESC PARA CONTINUAR]");

	}

	void buildNivel2() {
		niveles[1] = gcnew Nivel(gcnew Bitmap("recursos\\fondonvl2.jpg"), gcnew Bitmap("recursos\\tableta.jpg"), true);

		niveles[1]->getCinematica()->agregarLinea("¡NIVEL 2 COMPLETADO! ¡Hemos logrado escapar");
		niveles[1]->getCinematica()->agregarLinea("de la Galaxia Nebulosa del Khaos! ¡Y por");
		niveles[1]->getCinematica()->agregarLinea("los pelos! ¡Te mereces una ovación!");
		niveles[1]->getCinematica()->agregarLinea("¡Hurra!");
		niveles[1]->getCinematica()->agregarLinea("");

		// inicia con 8 figuritas
		for (int i = 0; i < 8; i++) {
			Random^ rx = gcnew Random();
			Random^ ry = gcnew Random();
			Random^ rd = gcnew Random();
			niveles[1]->getCC()->Add(gcnew CuerpoCaoticoSimple(rx->Next(1, 1024), ry->Next(1, 576), rd->Next(40, 70), 1));
		}
	}

	Juego(int na) {
		nivelActual = na;
		teclaEsc = false;
		puedeCambiarNivel = false;
		adicionFinal = false;
		fuente = gcnew Fuente();
		manejoVel = gcnew Bitmap("recursos\\manejoVelocidad.png");
		multiplicadorGlobal = 1;
		pc = gcnew PanelControl();

		nave = gcnew Nave(30, 490, 30);

		// ---------- Inicializar nivel ---------
		niveles = gcnew array<Nivel^>(2);
		//Nivel 1
		buildNivel1();
		//Nivel 2
		buildNivel2();
	}

	~Juego() {
		delete nave;
		for each (Nivel ^ n in niveles) delete n;
		delete niveles;
		delete fuente;
		delete pc;
	}

	bool determinarVictoriaDerrota() {
		if (nave->getX() + 22 * nave->getDimensiones() / 4 >= 1000 && nave->getY() < 50) return true;
		return false;
	}

	void dibujarMV(Graphics^ gr) {
		gr->DrawImage(manejoVel, 740, 430, 286 * 0.9, 141 * 0.9);
	}

	void manejarVelocidades(float mod) {
		multiplicadorGlobal += mod;
		if (multiplicadorGlobal <= 0.5) multiplicadorGlobal = 0.5;

		//Nave
		nave->cambioVelocidad(multiplicadorGlobal);
		//CuerposC (asterioides y cometas)
		for each (Entidad ^ cc in niveles[nivelActual]->getCC())
			cc->cambioVelocidad(multiplicadorGlobal);
		//Planetas
		for each (Planeta ^ p in niveles[nivelActual]->getSistemaSolar()->getPlanetas())
			p->cambioVelocidad(multiplicadorGlobal);
	}

	void manejarCambioNivel(Graphics^ gr, Font^ fuente) {
		if (!niveles[nivelActual]->getCinematica()->getEnCinematica()) return;

		if (nivelActual == 1 && !adicionFinal) {
			int contadorTotal = niveles[0]->getContador() + niveles[1]->getContador();
			int segundos = static_cast<int>((CONVERSOR_SEG * contadorTotal)) % 60;
			int minutos = (CONVERSOR_SEG * contadorTotal) / 60;
			String^ segMostrar = segundos < 10 ? "0" + segundos : "" + segundos;
			String^ minMostrar = minutos < 10 ? "0" + minutos : "" + minutos;

			String^ Tiempo = "Tiempo Total: " + minMostrar + ":" + segMostrar;
			niveles[1]->getCinematica()->agregarLinea(Tiempo);

			adicionFinal = true;
		}

		niveles[nivelActual]->getCinematica()->mostrarCinematica(gr, fuente, teclaEsc);
		puedeCambiarNivel = niveles[nivelActual]->getCinematica()->getFinalizada();

		if (!puedeCambiarNivel) return;

		nave->setVida(100); nave->setEnergia(100);
		if (nivelActual == 0) {
			nivelActual++;
			nave->setX(30);
			nave->setY(490);
			manejarVelocidades(0);

			puedeCambiarNivel = false;
		}
	}

	void manejarVentanaDerrota(Graphics^ gr, Font^ fuente) {
		if (!niveles[nivelActual]->getVenDerrota()->getEnCinematica()) return;

		niveles[nivelActual]->getVenDerrota()->mostrarCinematica(gr, fuente, teclaEsc);
		puedeCambiarNivel = niveles[nivelActual]->getVenDerrota()->getFinalizada();

		if (!puedeCambiarNivel) return;

		nave->setVida(100); nave->setEnergia(100);
		niveles[nivelActual]->~Nivel();
		delete niveles[nivelActual];
		if (nivelActual == 0) buildNivel1();
		else if (nivelActual == 1) buildNivel2();

		puedeCambiarNivel = false;
	}

	void dibujarMultiplicador(Graphics^ gr) {
		int anchoTexto = 10;
		if (multiplicadorGlobal != Math::Floor(multiplicadorGlobal)
			|| multiplicadorGlobal >= 10)
			anchoTexto = 25;
		else if (multiplicadorGlobal >= 10 && 
			multiplicadorGlobal != Math::Floor(multiplicadorGlobal))
			anchoTexto = 35;

		String^ tt = multiplicadorGlobal + "";
		short centrar = (70 - anchoTexto) / 2;
		gr->DrawString(tt, fuente->getFuenteFinal(), Brushes::Black, 
			835 + centrar - 6, 500);
	}

	void manejarColisiones() {
		for each(Entidad ^ cc in niveles[nivelActual]->getCC()) {
			if (cc->esCuerpoCaotico()) continue;
			if (!verificarColisiones(nave, cc)) continue;
			if (nave->getInvulnerable()) continue;

			nave->setInvulnerable(true);
			nave->setVida(nave->getVida() - 10);
			nave->setEnergia(nave->getEnergia() - 10);
			nave->aumentarColisiones();
			nave->setX(30);
			nave->setY(490);
			break;
		}

		for (int i = niveles[nivelActual]->getCC()->Count - 1; i >= 0; i--) {
			if (!verificarColisiones(nave, niveles[nivelActual]->getCC()[i])) return;

			nave->setVida(nave->getVida() - 10);
			delete niveles[nivelActual]->getCC()[i];
			niveles[nivelActual]->getCC()->RemoveAt(i);
		}
	}

	void manejarBuclePrincipal(Graphics^ gr) {
		//Cinematica
		manejarVentanaDerrota(gr, fuente->getFuenteFinal());
		if (niveles[nivelActual]->getVenDerrota()->getEnCinematica()) return;
		manejarCambioNivel(gr, fuente->getFuenteFinal());
		if (niveles[nivelActual]->getCinematica()->getEnCinematica()) return;

		//Borrar (final)
		gr->DrawImage(niveles[nivelActual]->getFondo(), 0, 0, 1024, 576);

		//Nave
		nave->mover();
		nave->mostrar(gr);
		
		//Derrota
		if (nave->getVida() <= 0 || nave->getEnergia() <= 0) 
			niveles[nivelActual]->getVenDerrota()->setEnCinematica(true);

		//Entidades
		niveles[nivelActual]->manejarEntidades(gr, fuente->getFuenteFinal(), multiplicadorGlobal);

		//Panel
		pc->mostrarPanel(gr, nave, fuente->getFuenteFinal(), niveles[nivelActual]->getContador());

		//Otros
		dibujarMV(gr);
		dibujarMultiplicador(gr);
		manejarColisiones();

		//Contadores
		niveles[nivelActual]->aumentarContador();
		niveles[nivelActual]->aumentarContadorAsteroide();
		niveles[nivelActual]->aumentarContadorCometa();
		if (nave->getInvulnerable()) {
			nave->aumentarContadorInvulnerabilidad();
			if (nave->getContadorInvulnerabilidad() >= 1 * CONVERSOR_CONT) {
				nave->setInvulnerable(false);
				nave->resetContadorInvulnerabilidad();
			}
		}

		//Condiciones
		if (determinarVictoriaDerrota()) {
			niveles[nivelActual]->getCinematica()->setEnCinematica(true);
		}
	}

	Nave^ getNave() { return nave; }
	void setTeclaEsc(bool p) { teclaEsc = p; }
};