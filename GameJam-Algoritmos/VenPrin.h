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
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void VenPrin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		juego->manejarBuclePrincipal(buffer->Graphics);
		
		buffer->Render();
	}
	};
}
