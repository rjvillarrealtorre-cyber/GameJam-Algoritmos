#pragma once
#include "EscenarioInstrucciones.h"
#include "EscenarioCreditos.h"

namespace Project86 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	public ref class EscenarioMenu1 : public System::Windows::Forms::Form
	{
	public:
		EscenarioMenu1(void)
		{
			InitializeComponent();

			pictureBox1->Paint += gcnew PaintEventHandler(this, &EscenarioMenu1::dibujarNeon);

			crearMenu();
			pictureBox1->Invalidate();
		}

	protected:
		~EscenarioMenu1()
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
				(gcnew System::ComponentModel::ComponentResourceManager(EscenarioMenu1::typeid));

			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();

			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Image =
				(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1024, 576);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;

			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 576);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"EscenarioMenu1";
			this->Text = L"Menu Principal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion

	private:

		Label^ crearLabel(String^ texto, int x, int y, int ancho, int alto, int tam, Color color)
		{
			Label^ lbl = gcnew Label();
			lbl->Text = texto;
			lbl->Location = Point(x, y);
			lbl->Size = Drawing::Size(ancho, alto);
			lbl->BackColor = Color::Transparent;
			lbl->ForeColor = color;
			lbl->TextAlign = ContentAlignment::MiddleCenter;
			lbl->AutoSize = false;
			lbl->Font = gcnew Drawing::Font("Segoe UI", tam, FontStyle::Bold);
			return lbl;
		}

		Button^ crearBoton(String^ texto, int x, int y, Color borde)
		{
			Button^ btn = gcnew Button();
			btn->Text = texto;
			btn->Size = Drawing::Size(310, 48);
			btn->Location = Point(x, y);
			btn->BackColor = Color::FromArgb(5, 10, 25);
			btn->ForeColor = Color::White;
			btn->FlatStyle = FlatStyle::Flat;
			btn->FlatAppearance->BorderColor = borde;
			btn->FlatAppearance->BorderSize = 2;
			btn->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);

			btn->MouseEnter += gcnew EventHandler(this, &EscenarioMenu1::btn_MouseEnter);
			btn->MouseLeave += gcnew EventHandler(this, &EscenarioMenu1::btn_MouseLeave);

			return btn;
		}

		void dibujarNeon(Object^ sender, PaintEventArgs^ e)
		{
			Graphics^ g = e->Graphics;
			g->SmoothingMode = SmoothingMode::AntiAlias;

			Pen^ cyan = gcnew Pen(Color::FromArgb(0, 245, 255), 2);
			Pen^ morado = gcnew Pen(Color::FromArgb(170, 90, 255), 2);

			g->DrawLine(cyan, 270, 78, 370, 78);
			g->DrawLine(cyan, 655, 78, 755, 78);
			g->DrawLine(cyan, 370, 78, 385, 66);
			g->DrawLine(cyan, 655, 78, 640, 66);

			g->FillEllipse(Brushes::Cyan, 265, 74, 8, 8);
			g->FillEllipse(Brushes::Cyan, 752, 74, 8, 8);

			g->DrawLine(morado, 400, 135, 470, 135);
			g->DrawLine(morado, 555, 135, 625, 135);
			g->FillEllipse(Brushes::Violet, 395, 131, 8, 8);
			g->FillEllipse(Brushes::Violet, 622, 131, 8, 8);

			g->DrawLine(cyan, 295, 505, 420, 505);
			g->DrawLine(morado, 605, 505, 730, 505);
			g->DrawLine(cyan, 420, 505, 445, 518);
			g->DrawLine(morado, 605, 505, 580, 518);

			delete cyan;
			delete morado;

			
		}

		void dibujarDecoracionBoton(Graphics^ g, int x, int y, Pen^ p)
		{
			g->DrawLine(p, x, y, x + 25, y);
			g->DrawLine(p, x, y, x + 15, y + 10);

			g->DrawLine(p, x + 335, y, x + 360, y);
			g->DrawLine(p, x + 360, y, x + 345, y + 10);

			g->FillEllipse(Brushes::Cyan, x - 5, y - 4, 8, 8);
			g->FillEllipse(Brushes::Cyan, x + 360, y - 4, 8, 8);
		}

		void crearMenu()
		{
			Color cyan = Color::FromArgb(0, 245, 255);
			Color morado = Color::FromArgb(160, 100, 255);
			Color naranja = Color::FromArgb(255, 160, 40);
			Color verde = Color::FromArgb(80, 255, 180);
			Color rojo = Color::FromArgb(255, 70, 100);

			Label^ titulo = crearLabel("POLINAVIS", 0, 32, 1024, 65, 34, cyan);
			pictureBox1->Controls->Add(titulo);

			Label^ subtitulo = crearLabel(">|< MENU >|<", 0, 88, 1024, 35, 16, Color::FromArgb(150, 120, 255));
			pictureBox1->Controls->Add(subtitulo);

			Button^ btnNivel1 = crearBoton("NIVEL 1 - SISTEMA SOLAR", 357, 160, cyan);
			Button^ btnNivel2 = crearBoton("NIVEL 2 - NEBULOSA DEL KHAOS", 357, 225, morado);
			Button^ btnInstrucciones = crearBoton("INSTRUCCIONES", 357, 290, naranja);
			Button^ btnCreditos = crearBoton("CREDITOS", 357, 355, verde);
			Button^ btnSalir = crearBoton("SALIR", 357, 420, rojo);

			btnNivel1->Click += gcnew EventHandler(this, &EscenarioMenu1::btnNivel1_Click);
			btnNivel2->Click += gcnew EventHandler(this, &EscenarioMenu1::btnNivel2_Click);
			btnInstrucciones->Click += gcnew EventHandler(this, &EscenarioMenu1::btnInstrucciones_Click);
			btnCreditos->Click += gcnew EventHandler(this, &EscenarioMenu1::btnCreditos_Click);
			btnSalir->Click += gcnew EventHandler(this, &EscenarioMenu1::btnSalir_Click);

			pictureBox1->Controls->Add(btnNivel1);
			pictureBox1->Controls->Add(btnNivel2);
			pictureBox1->Controls->Add(btnInstrucciones);
			pictureBox1->Controls->Add(btnCreditos);
			pictureBox1->Controls->Add(btnSalir);
		}

		void btnNivel1_Click(Object^ sender, EventArgs^ e)
		{
			MessageBox::Show("Nivel 1 en desarrollo.");
		}

		void btnNivel2_Click(Object^ sender, EventArgs^ e)
		{
			MessageBox::Show("Nivel 2 en desarrollo.");
		}

		void btnInstrucciones_Click(Object^ sender, EventArgs^ e)
		{
			EscenarioInstrucciones^ frm = gcnew EscenarioInstrucciones();
			frm->ShowDialog();
		}

		void btnCreditos_Click(Object^ sender, EventArgs^ e)
		{
			EscenarioCreditos^ frm = gcnew EscenarioCreditos();
			frm->ShowDialog();
		}

		void btnSalir_Click(Object^ sender, EventArgs^ e)
		{
			Application::Exit();
		}

		void btn_MouseEnter(Object^ sender, EventArgs^ e)
		{
			Button^ boton = (Button^)sender;
			boton->BackColor = Color::FromArgb(0, 255, 120);
			boton->ForeColor = Color::Black;
		}

		void btn_MouseLeave(Object^ sender, EventArgs^ e)
		{
			Button^ boton = (Button^)sender;
			boton->BackColor = Color::FromArgb(5, 10, 25);
			boton->ForeColor = Color::White;
		}
	};
}
