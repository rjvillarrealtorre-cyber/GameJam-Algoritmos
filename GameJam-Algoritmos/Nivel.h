#pragma once

using namespace System;
using namespace System::Drawing;

ref class Nivel {
private:
	Bitmap^ fondo;
public:
	Nivel(Bitmap^ f) {
		fondo = f;
	}

	~Nivel() {
		delete fondo;
	}

	Bitmap^ getFondo() { return fondo; }
};