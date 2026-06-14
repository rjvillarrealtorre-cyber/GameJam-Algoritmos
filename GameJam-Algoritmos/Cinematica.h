#pragma once

using namespace System::Drawing;
using namespace System;
using namespace System::Collections::Generic;

ref class Cinematica {
private:
	Bitmap^ fondo;
	List<String^>^ texto;
	bool enCinematica;
	bool finalizada;
public:
	Cinematica(Bitmap^ f) {
		fondo = f;
		texto = gcnew List<String^>();
		enCinematica = finalizada = false;
	}

	~Cinematica() {
		for each (String ^ s in texto) delete s;
		delete texto;
	}

	void agregarLinea(String^ l) {
		texto->Add(l);
	}

	void mostrarCinematica(Graphics^ gr, Font^ fuente, bool teclaEsc) {
		gr->Clear(Color::Black);
		gr->DrawImage(fondo, 0, 0, 1024, 576);

		int centrarX = (1024 - texto[0]->Length * 11) / 2;
		int centrarY = (576 - texto->Count * 18) / 2;
		int alturaString = 18;
		for (int i = 0; i < texto->Count; i++) {
			gr->DrawString(texto[i], fuente, Brushes::PaleGreen, centrarX, centrarY + alturaString * i);
		}

		if (teclaEsc) finalizada = true;
	}

	void setEnCinematica(bool p) { enCinematica = p; }
	bool getEnCinematica() { return enCinematica; }
	bool getFinalizada() { return finalizada; }

};