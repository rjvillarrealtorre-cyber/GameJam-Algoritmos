#pragma once

using namespace System::Drawing;
using namespace System::Drawing::Text;

// Generado con IA
ref class Fuente {
private:
	PrivateFontCollection^ fonts;
	FontFamily^ family;
	Font^ fuenteFinal;
public:
	Fuente() {
		fonts = gcnew PrivateFontCollection();
		fonts->AddFontFile("recursos\\PixelOperator.ttf");
		family = fonts->Families[0];
		fuenteFinal = gcnew Font(family, 18);
	}

	~Fuente() {
		delete fonts;
		delete family;
		delete fuenteFinal;
	}

	Font^ getFuenteFinal() { return fuenteFinal; }
};