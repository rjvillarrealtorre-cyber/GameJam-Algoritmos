#pragma once
#include "Juego.h"

namespace GameJamAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de VenPrin
	/// </summary>
	public ref class VenPrin : public System::Windows::Forms::Form
	{
	public:
		VenPrin(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			gr = CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(gr, ClientRectangle);
			juego = gcnew Juego();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VenPrin()
		{
			if (components)
			{
				delete components;
			}
			delete gr;
			delete buffer;
			delete juego;
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ gr;
		BufferedGraphics^ buffer;
		Juego^ juego;

	private: System::Windows::Forms::Timer^ timer1;
		   
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 75;
			this->timer1->Tick += gcnew System::EventHandler(this, &VenPrin::timer1_Tick);
			// 
			// VenPrin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 576);
			this->Name = L"VenPrin";
			this->Text = L"VenPrin";
			this->Load += gcnew System::EventHandler(this, &VenPrin::VenPrin_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &VenPrin::VenPrin_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &VenPrin::VenPrin_KeyUp);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &VenPrin::VenPrin_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void VenPrin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		juego->manejarBuclePrincipal(buffer->Graphics);
		
		buffer->Render();
	}
	private: System::Void VenPrin_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Point p(e->X, e->Y);

		Rectangle subsDotFive(748, 480, 820 - 748, 510 - 480);
		Rectangle subsOne(748, 520, 820 - 748, 554 - 520);
		Rectangle addDotFive(930, 480, 1000 - 930, 510 - 480);
		Rectangle addOne(930, 520, 1000 - 930, 560 - 520);

		if (subsDotFive.Contains(p)) {
			juego->manejarVelocidades(-0.5);
		}
		else if (subsOne.Contains(p)) {
			juego->manejarVelocidades(-1);
		}
		else if (addDotFive.Contains(p)) {
			juego->manejarVelocidades(+0.5);
		}
		else if (addOne.Contains(p)) {
			juego->manejarVelocidades(+1);
		}
	}
	private: System::Void VenPrin_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Right:
			juego->getNave()->setTDerecha(true);
			break;
		case Keys::Left:
			juego->getNave()->setTIzquierda(true);
			break;
		case Keys::Up:
			juego->getNave()->setTArriba(true);
			break;
		case Keys::Down:
			juego->getNave()->setTAbajo(true);
			break;
		case Keys::Escape:
			juego->setTeclaEsc(true);
			break;
		}
	}
	private: System::Void VenPrin_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Right:
			juego->getNave()->setTDerecha(false);
			break;
		case Keys::Left:
			juego->getNave()->setTIzquierda(false);
			break;
		case Keys::Up:
			juego->getNave()->setTArriba(false);
			break;
		case Keys::Down:
			juego->getNave()->setTAbajo(false);
			break;
		case Keys::Escape:
			juego->setTeclaEsc(false);
			break;
		}
	}
};
}
