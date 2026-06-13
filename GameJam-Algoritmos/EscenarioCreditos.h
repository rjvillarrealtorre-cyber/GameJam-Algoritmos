#pragma once

namespace Project86 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	public ref class EscenarioCreditos : public System::Windows::Forms::Form
	{
	public:
		EscenarioCreditos(void)
		{
			InitializeComponent();

			pictureBox1->Paint += gcnew PaintEventHandler(this, &EscenarioCreditos::dibujarNeon);

			crearCreditos();
			pictureBox1->Invalidate();
		}

	protected:
		~EscenarioCreditos()
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
				(gcnew System::ComponentModel::ComponentResourceManager(EscenarioCreditos::typeid));

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
			this->Name = L"EscenarioCreditos";
			this->Text = L"Creditos";
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

		void dibujarNeon(Object^ sender, PaintEventArgs^ e)
		{
			Graphics^ g = e->Graphics;
			g->SmoothingMode = SmoothingMode::AntiAlias;

			Pen^ cyan = gcnew Pen(Color::FromArgb(0, 245, 255), 2);
			Pen^ morado = gcnew Pen(Color::FromArgb(190, 80, 255), 2);

			g->DrawLine(cyan, 355, 70, 430, 70);
			g->DrawLine(cyan, 850, 70, 925, 70);
			g->DrawLine(cyan, 430, 70, 445, 58);
			g->DrawLine(cyan, 850, 70, 835, 58);

			g->DrawLine(cyan, 380, 220, 500, 220);
			g->DrawLine(cyan, 780, 220, 900, 220);

			array<int>^ y = { 285, 340, 395, 450 };

			for each (int pos in y)
			{
				g->DrawLine(cyan, 495, pos, 535, pos);
				g->DrawLine(cyan, 495, pos, 515, pos + 12);
				g->FillEllipse(Brushes::Cyan, 490, pos - 4, 8, 8);

				g->DrawLine(cyan, 745, pos, 785, pos);
				g->DrawLine(cyan, 785, pos, 765, pos + 12);
				g->FillEllipse(Brushes::Cyan, 782, pos - 4, 8, 8);
			}

			g->DrawLine(morado, 355, 535, 450, 535);
			g->DrawLine(morado, 830, 535, 925, 535);

			g->DrawLine(morado, 420, 575, 510, 575);
			g->DrawLine(morado, 770, 575, 860, 575);
			g->FillEllipse(Brushes::Violet, 415, 571, 8, 8);
			g->FillEllipse(Brushes::Violet, 855, 571, 8, 8);

			delete cyan;
			delete morado;
		}

		void crearCreditos()
		{
			Color azulNeon = Color::FromArgb(0, 245, 255);
			Color naranjaNeon = Color::FromArgb(255, 160, 40);
			Color blancoFrio = Color::FromArgb(230, 245, 255);
			Color moradoNeon = Color::FromArgb(190, 80, 255);
			Color azulOscuro = Color::FromArgb(5, 10, 25);

			Label^ titulo = crearLabel("CREDITOS", 0, 35, 1280, 75, 38, azulNeon, true);
			pictureBox1->Controls->Add(titulo);

			Label^ juego = crearLabel("POLINAVIS - VIAJE INTERESTELAR", 0, 105, 1280, 45, 18, Color::FromArgb(110, 140, 255), true);
			pictureBox1->Controls->Add(juego);

			Label^ dev = crearLabel("DESARROLLADORES:", 0, 195, 1280, 45, 22, naranjaNeon, true);
			pictureBox1->Controls->Add(dev);

			Label^ nombres = crearLabel(
				"JULIO VILLAREAL TORRE\n\n"
				"LUIGGI PEREZ CABEZAS\n\n"
				"SUNMI NATALI\n\n"
				"DIEGO REQUENA",
				340, 250, 600, 220, 16, blancoFrio, true
			);
			pictureBox1->Controls->Add(nombres);

			Label^ curso = crearLabel("Curso: Algoritmos  |  Game Jam 2026-10", 0, 510, 1280, 35, 14, Color::LightCyan, true);
			pictureBox1->Controls->Add(curso);

			Label^ gracias = crearLabel("Gracias por jugar", 0, 550, 1280, 35, 17, moradoNeon, true);
			pictureBox1->Controls->Add(gracias);

			Button^ btnVolver = gcnew Button();
			btnVolver->Text = "VOLVER AL MENU";
			btnVolver->Size = Drawing::Size(210, 50);
			btnVolver->Location = Point(535, 620);
			btnVolver->BackColor = azulOscuro;
			btnVolver->ForeColor = azulNeon;
			btnVolver->FlatStyle = FlatStyle::Flat;
			btnVolver->FlatAppearance->BorderColor = azulNeon;
			btnVolver->FlatAppearance->BorderSize = 2;
			btnVolver->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);

			btnVolver->Click += gcnew EventHandler(this, &EscenarioCreditos::btnVolver_Click);
			btnVolver->MouseEnter += gcnew EventHandler(this, &EscenarioCreditos::btnVolver_MouseEnter);
			btnVolver->MouseLeave += gcnew EventHandler(this, &EscenarioCreditos::btnVolver_MouseLeave);

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
