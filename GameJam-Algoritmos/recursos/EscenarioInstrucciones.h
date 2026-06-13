#pragma once

namespace Project86 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class EscenarioInstrucciones : public System::Windows::Forms::Form
	{
	public:
		EscenarioInstrucciones(void)
		{
			InitializeComponent();
			crearInstrucciones();
		}

	protected:
		~EscenarioInstrucciones()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::PictureBox^ pictureBox1;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources =
				(gcnew System::ComponentModel::ComponentResourceManager(EscenarioInstrucciones::typeid));

			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();

			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Image =
				(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1280, 720);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;

			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"EscenarioInstrucciones";
			this->Text = L"Instrucciones";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion

	private:

		Label^ crearLabel(String^ texto, int x, int y, int ancho, int alto, int tam, Color color, bool negrita)
		{
			Label^ lbl = gcnew Label();

			lbl->Text = texto;
			lbl->Location = Point(x, y);
			lbl->Size = Drawing::Size(ancho, alto);
			lbl->BackColor = Color::Transparent;
			lbl->ForeColor = color;
			lbl->TextAlign = ContentAlignment::MiddleCenter;
			lbl->AutoSize = false;

			if (negrita)
				lbl->Font = gcnew Drawing::Font("Segoe UI", tam, FontStyle::Bold);
			else
				lbl->Font = gcnew Drawing::Font("Segoe UI", tam, FontStyle::Regular);

			return lbl;
		}

		void crearInstrucciones()
		{
			Color cyan = Color::FromArgb(0, 245, 255);
			Color morado = Color::FromArgb(160, 100, 255);
			Color blanco = Color::FromArgb(230, 245, 255);
			Color naranja = Color::FromArgb(255, 160, 40);
			Color verde = Color::FromArgb(80, 255, 180);
			Color azulOscuro = Color::FromArgb(5, 10, 25);

			Label^ titulo = crearLabel("INSTRUCCIONES", 0, 45, 1280, 70, 36, cyan, true);
			pictureBox1->Controls->Add(titulo);

			Label^ juego = crearLabel("POLINAVIS - VIAJE INTERESTELAR", 0, 110, 1280, 45, 18, Color::FromArgb(140, 110, 255), true);
			pictureBox1->Controls->Add(juego);

			Label^ objetivo = crearLabel(
				"OBJETIVO\n\n"
				"Lleva la nave desde el punto de inicio hasta el destino.\n"
				"Evita cometas, asteroides y cuerpos peligrosos.\n"
				"Completa ambos niveles sin perder todas tus vidas.",
				140, 190, 1000, 130, 16, blanco, false
			);
			pictureBox1->Controls->Add(objetivo);

			Label^ controles = crearLabel(
				"CONTROLES\n\n"
				"Flechas direccionales: Para mover la nave\n"
				"W: ARRIBA | S: ATRAS | A: IZQUIERDA | D: DERECHA\n"
				"Volver al menu: regresar a la pantalla principal",
				140, 340, 1000, 120, 16, verde, false
			);
			pictureBox1->Controls->Add(controles);

			Label^ niveles = crearLabel(
				"NIVELES\n\n"
				"Nivel 1: Sistema Solar con planetas, rotacion y traslacion.\n"
				"Nivel 2: Nebulosa del Khaos con figuras geometricas y movimientos aleatorios.",
				140, 480, 1000, 110, 16, naranja, false
			);
			pictureBox1->Controls->Add(niveles);

			Button^ btnVolver = gcnew Button();
			btnVolver->Text = "VOLVER AL MENU";
			btnVolver->Size = Drawing::Size(210, 50);
			btnVolver->Location = Point(535, 625);
			btnVolver->BackColor = azulOscuro;
			btnVolver->ForeColor = cyan;
			btnVolver->FlatStyle = FlatStyle::Flat;
			btnVolver->FlatAppearance->BorderColor = cyan;
			btnVolver->FlatAppearance->BorderSize = 2;
			btnVolver->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);

			btnVolver->Click += gcnew EventHandler(this, &EscenarioInstrucciones::btnVolver_Click);
			btnVolver->MouseEnter += gcnew EventHandler(this, &EscenarioInstrucciones::btnVolver_MouseEnter);
			btnVolver->MouseLeave += gcnew EventHandler(this, &EscenarioInstrucciones::btnVolver_MouseLeave);

			pictureBox1->Controls->Add(btnVolver);
			btnVolver->BringToFront();
		}

		void btnVolver_Click(Object^ sender, EventArgs^ e)
		{
			
			this->Close();
		}

		void btnVolver_MouseEnter(Object^ sender, EventArgs^ e)
		{
			Button^ boton = (Button^)sender;
			boton->BackColor = Color::FromArgb(0, 255, 120);
			boton->ForeColor = Color::Black;
			boton->FlatAppearance->BorderColor = Color::FromArgb(120, 255, 180);
		}

		void btnVolver_MouseLeave(Object^ sender, EventArgs^ e)
		{
			Button^ boton = (Button^)sender;
			boton->BackColor = Color::FromArgb(5, 10, 25);
			boton->ForeColor = Color::FromArgb(0, 245, 255);
			boton->FlatAppearance->BorderColor = Color::FromArgb(0, 245, 255);
		}
	};
}
