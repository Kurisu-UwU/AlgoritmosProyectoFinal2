#pragma once
#include "SpiderPunk.h"
#include "Controladora.h"
#include "NivelRitmo.h"
namespace AlgoritmosProyectoFinal2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de NivelPunk
	/// </summary>
	public ref class NivelPunk : public System::Windows::Forms::Form
	{
	public:
		NivelPunk(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c?digo de constructor aqu?
			//

			controladora = new Controladora();
			this->KeyPreview = true;
			srand((unsigned int)time(nullptr));
		}
		void CargarNivel1() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarObstaculo(0, 0, 0, 225, 450);
			controladora->GenerarObstaculo(770, 0, 0, 225, 440);
			controladora->GenerarObstaculo(0, 415, 0, 225, 1210);

			controladora->GenerarCofre(300, 300, 32, 32, 0, CofreAbierto(0));
			controladora->GenerarCofre(560, 120, 32, 32, 1, CofreAbierto(1));
			controladora->GenerarCofre(600, 350, 32, 32, 2, CofreAbierto(2));
			controladora->GenerarPuerta(1200, 0, 60, 840, 2, 60, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
		}

		void CargarNivel2() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarObstaculo(0, 0, 0, 285, 435);
			controladora->GenerarObstaculo(790, 0, 0, 285, 445);
			controladora->GenerarObstaculo(1080, 460, 0, 225, 130);
			controladora->GenerarObstaculo(792, 460, 0, 225, 215);
			controladora->GenerarObstaculo(0, 468, 0, 285, 435);

			controladora->GenerarPuerta(0, 285, 40, 183, 1, 1100, 300);     // oeste -> sala 1
			controladora->GenerarPuerta(1200, 0, 60, 840, 3, 60, 650);      // este -> sala 3 (jefe)
		}

		void CargarNivel3() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->LimpiarJefe();

			controladora->GenerarObstaculo(0, 385, 0, 40, 1210);
			Jefe* spot = new Jefe(700, 600, 5, 64, 64, true, 20);
			controladora->DefinirJefe(spot);
			combateTerminado = false;

			//controladora->GenerarPuerta(0, 560, 40, 280, 2, 1250, 380);     // oeste -> sala 2
		}
		bool CofreAbierto(int id) {
			switch (id) {
			case 0:
				return estadocofre1; break;
			case 1:
				return estadocofre2; break;
			case 2:
				return estadocofre3; break;
			default: return false;
			}
		}
		void MarcarCofre(int id) {
			switch (id) {
			case 0:
				estadocofre1 = true; break;
			case 1: estadocofre2 = true; break;
			default: estadocofre3 = true; break;
			}
		}
		bool PuedeEntrarSala(int sala) {
			return sala != 3 || (estadocofre1 && estadocofre2 && estadocofre3);
		}
		void IrASala(int sala, int px, int py) {
			salaActual = sala;
			pnlJuego1->Visible = (sala == 1);
			pnlJuego2->Visible = (sala == 2);
			pnlJuego3->Visible = (sala == 3);
			switch (sala) {
			case 1: CargarNivel1(); break;
			case 2: CargarNivel2(); break;
			case 3: CargarNivel3(); break;
			}
			punk->SetPX(px);
			punk->SetPY(py);
		}

		bool JugarRitmo(int nivelRitmo) {
			int px = punk->GetPX();
			int py = punk->GetPY();
			timerJuego->Enabled = false;
			NivelRitmo^ frm = gcnew NivelRitmo(nivelRitmo, punk);
			System::Windows::Forms::DialogResult r = frm->ShowDialog(this);
			delete frm;
			punk->SetPX(px);
			punk->SetPY(py);
			timerJuego->Enabled = true;
			return r == System::Windows::Forms::DialogResult::OK;
		}

		void CargarNivelMusical(int n) {
			JugarRitmo(n);
		}
		// Overlay de ayuda: hitboxes de puertas (con sus datos) y coordenadas del mouse y de Punk.
		// Pasa el mouse sobre el mapa y lee la coordenada para escribirla en GenerarPuerta(...). F2 lo oculta.
		void DibujarDebug(Graphics^ g, Panel^ panel) {
			if (!modoDebug) return;
			controladora->DibujarPuertas(g);
			controladora->DibujarObstaculos(g);
			Point m = panel->PointToClient(System::Windows::Forms::Cursor::Position);
			System::String^ info = "[F2 ocultar]  Mouse: " + System::Convert::ToString(m.X) + ", " + System::Convert::ToString(m.Y)
				+ "   Punk: " + System::Convert::ToString(punk->GetPX()) + ", " + System::Convert::ToString(punk->GetPY());
			g->FillRectangle(Brushes::Black, 0, 0, 430, 20);
			g->DrawString(info, SystemFonts::DefaultFont, Brushes::Lime, 4.0f, 4.0f);
		}
		bool ComprobarFinCombate() {
			Jefe* spot = controladora->getJefe();
			if (spot == nullptr || combateTerminado) return false;

			if (spot->getVida() <= 0) {
				combateTerminado = true;
				timerJuego->Enabled = false;
				MessageBox::Show("Derrotaste a Spot! Nivel completado.");
				this->DialogResult = System::Windows::Forms::DialogResult::OK;   // cierra el nivel y vuelve al menu
				return true;
			}
			if (punk->getVida() <= 0) {
				timerJuego->Enabled = false;   // el MessageBox procesa mensajes: sin esto el timer se re-entra
				MessageBox::Show("Spot te derroto. Intentalo de nuevo!");
				IrASala(3, 60, 650);           // recarga la sala: Spot, lasers y vida de Punk reiniciados
				timerJuego->Enabled = true;
				return true;
			}
			return false;
		}
	protected:
		~NivelPunk()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlDeControl;
	private: System::Windows::Forms::Panel^ pnlJuego1;
	protected:

	private: System::Windows::Forms::Timer^ timerJuego;

	private: System::ComponentModel::IContainer^ components;

	private:

		int salaActual = 1;
		bool modoDebug = false;   // F2: muestra/oculta hitboxes de puertas y coordenadas
		bool estadocofre1 = false;
		bool estadocofre2 = false;
		bool estadocofre3 = false;
		bool combateTerminado = false;

		Graphics^ gr1;
		Graphics^ gr2;
		Graphics^ gr3;
		Graphics^ grp;
		BufferedGraphicsContext^ space1;
		BufferedGraphicsContext^ space2;
		BufferedGraphicsContext^ space3;
		BufferedGraphicsContext^ spacep;
		BufferedGraphics^ buffer1;
		BufferedGraphics^ buffer2;
		BufferedGraphics^ buffer3;
		BufferedGraphics^ bufferp;
		Bitmap^ bmpPanelControl;
		Bitmap^ bmpMapa1;
		Bitmap^ bmpMapa2;
		Bitmap^ bmpMapa3;
		Bitmap^ bmpMapaMusical;
		Bitmap^ bmpPunk;
		Bitmap^ bmpSpot;
		Bitmap^ bmpCofreC;
		Bitmap^ bmpCofreA;
		Bitmap^ bmpNota1;
		Bitmap^ bmpNota2;
		Bitmap^ bmpNota3;
		Bitmap^ bmpProyectilMalo;
		Controladora* controladora;

	private: System::Windows::Forms::Panel^ pnlJuego2;
	private: System::Windows::Forms::Panel^ pnlJuego3;
	private: System::Windows::Forms::Panel^ pnlJuegoMusical;

	private: System::Windows::Forms::Button^ btnPunk1;

	private: System::Windows::Forms::Button^ btnPunk3;
	private: System::Windows::Forms::Button^ btnPunk2;

	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;

	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ lblSpot;
	private: System::Windows::Forms::Label^ lblPuntaje;
	private: System::Windows::Forms::Label^ lblVida;
	private: System::Windows::Forms::Label^ lblPersonaje;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::Label^ label4;
	   SpiderPunk* punk;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->pnlDeControl = (gcnew System::Windows::Forms::Panel());
			   this->lblSpot = (gcnew System::Windows::Forms::Label());
			   this->lblPuntaje = (gcnew System::Windows::Forms::Label());
			   this->lblVida = (gcnew System::Windows::Forms::Label());
			   this->lblPersonaje = (gcnew System::Windows::Forms::Label());
			   this->pnlJuego1 = (gcnew System::Windows::Forms::Panel());
			   this->button10 = (gcnew System::Windows::Forms::Button());
			   this->button11 = (gcnew System::Windows::Forms::Button());
			   this->button12 = (gcnew System::Windows::Forms::Button());
			   this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlJuego2 = (gcnew System::Windows::Forms::Panel());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->pnlJuego3 = (gcnew System::Windows::Forms::Panel());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->pnlJuegoMusical = (gcnew System::Windows::Forms::Panel());
			   this->btnPunk3 = (gcnew System::Windows::Forms::Button());
			   this->btnPunk2 = (gcnew System::Windows::Forms::Button());
			   this->btnPunk1 = (gcnew System::Windows::Forms::Button());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->pnlDeControl->SuspendLayout();
			   this->pnlJuego1->SuspendLayout();
			   this->pnlJuego2->SuspendLayout();
			   this->pnlJuego3->SuspendLayout();
			   this->pnlJuegoMusical->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // pnlDeControl
			   // 
			   this->pnlDeControl->Controls->Add(this->lblSpot);
			   this->pnlDeControl->Controls->Add(this->lblPuntaje);
			   this->pnlDeControl->Controls->Add(this->lblVida);
			   this->pnlDeControl->Controls->Add(this->lblPersonaje);
			   this->pnlDeControl->Location = System::Drawing::Point(16, 12);
			   this->pnlDeControl->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->pnlDeControl->Name = L"pnlDeControl";
			   this->pnlDeControl->Size = System::Drawing::Size(1620, 110);
			   this->pnlDeControl->TabIndex = 0;
			   this->pnlDeControl->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &NivelPunk::pnlDeControl_Paint);
			   // 
			   // lblSpot
			   // 
			   this->lblSpot->AutoSize = true;
			   this->lblSpot->BackColor = System::Drawing::Color::Transparent;
			   this->lblSpot->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblSpot->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->lblSpot->Location = System::Drawing::Point(783, 55);
			   this->lblSpot->Name = L"lblSpot";
			   this->lblSpot->Size = System::Drawing::Size(78, 28);
			   this->lblSpot->TabIndex = 3;
			   this->lblSpot->Text = L"lblSpot";
			   // 
			   // lblPuntaje
			   // 
			   this->lblPuntaje->AutoSize = true;
			   this->lblPuntaje->BackColor = System::Drawing::Color::Transparent;
			   this->lblPuntaje->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblPuntaje->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->lblPuntaje->Location = System::Drawing::Point(783, 12);
			   this->lblPuntaje->Name = L"lblPuntaje";
			   this->lblPuntaje->Size = System::Drawing::Size(101, 28);
			   this->lblPuntaje->TabIndex = 2;
			   this->lblPuntaje->Text = L"lblPuntaje";
			   // 
			   // lblVida
			   // 
			   this->lblVida->AutoSize = true;
			   this->lblVida->BackColor = System::Drawing::Color::Transparent;
			   this->lblVida->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblVida->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->lblVida->Location = System::Drawing::Point(25, 55);
			   this->lblVida->Name = L"lblVida";
			   this->lblVida->Size = System::Drawing::Size(75, 28);
			   this->lblVida->TabIndex = 1;
			   this->lblVida->Text = L"lblVida";
			   // 
			   // lblPersonaje
			   // 
			   this->lblPersonaje->AutoSize = true;
			   this->lblPersonaje->BackColor = System::Drawing::Color::Transparent;
			   this->lblPersonaje->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblPersonaje->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->lblPersonaje->Location = System::Drawing::Point(25, 12);
			   this->lblPersonaje->Name = L"lblPersonaje";
			   this->lblPersonaje->Size = System::Drawing::Size(125, 28);
			   this->lblPersonaje->TabIndex = 0;
			   this->lblPersonaje->Text = L"lblPersonaje";
			   // 
			   // pnlJuego1
			   // 
			   this->pnlJuego1->Controls->Add(this->button10);
			   this->pnlJuego1->Controls->Add(this->button11);
			   this->pnlJuego1->Controls->Add(this->button12);
			   this->pnlJuego1->Location = System::Drawing::Point(16, 121);
			   this->pnlJuego1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pnlJuego1->Name = L"pnlJuego1";
			   this->pnlJuego1->Size = System::Drawing::Size(1620, 839);
			   this->pnlJuego1->TabIndex = 1;
			   this->pnlJuego1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &NivelPunk::pnlJuego1_Paint);
			   // 
			   // button10
			   // 
			   this->button10->Location = System::Drawing::Point(172, 25);
			   this->button10->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button10->Name = L"button10";
			   this->button10->Size = System::Drawing::Size(100, 28);
			   this->button10->TabIndex = 10;
			   this->button10->Text = L"Punk 3";
			   this->button10->UseVisualStyleBackColor = true;
			   this->button10->Visible = false;
			   this->button10->Click += gcnew System::EventHandler(this, &NivelPunk::button10_Click);
			   // 
			   // button11
			   // 
			   this->button11->Location = System::Drawing::Point(316, 25);
			   this->button11->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button11->Name = L"button11";
			   this->button11->Size = System::Drawing::Size(100, 28);
			   this->button11->TabIndex = 9;
			   this->button11->Text = L"Punk 2";
			   this->button11->UseVisualStyleBackColor = true;
			   this->button11->Visible = false;
			   this->button11->Click += gcnew System::EventHandler(this, &NivelPunk::button11_Click);
			   // 
			   // button12
			   // 
			   this->button12->Location = System::Drawing::Point(28, 25);
			   this->button12->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button12->Name = L"button12";
			   this->button12->Size = System::Drawing::Size(100, 28);
			   this->button12->TabIndex = 11;
			   this->button12->Text = L"Punk m";
			   this->button12->UseVisualStyleBackColor = true;
			   this->button12->Visible = false;
			   this->button12->Click += gcnew System::EventHandler(this, &NivelPunk::button12_Click);
			   // 
			   // timerJuego
			   // 
			   this->timerJuego->Enabled = true;
			   this->timerJuego->Tick += gcnew System::EventHandler(this, &NivelPunk::timerJuego_Tick);
			   // 
			   // pnlJuego2
			   // 
			   this->pnlJuego2->Controls->Add(this->button5);
			   this->pnlJuego2->Controls->Add(this->button6);
			   this->pnlJuego2->Controls->Add(this->button8);
			   this->pnlJuego2->Location = System::Drawing::Point(16, 121);
			   this->pnlJuego2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pnlJuego2->Name = L"pnlJuego2";
			   this->pnlJuego2->Size = System::Drawing::Size(1620, 839);
			   this->pnlJuego2->TabIndex = 2;
			   // 
			   // button5
			   // 
			   this->button5->Location = System::Drawing::Point(460, 25);
			   this->button5->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(100, 28);
			   this->button5->TabIndex = 8;
			   this->button5->Text = L"Punk 1";
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Visible = false;
			   this->button5->Click += gcnew System::EventHandler(this, &NivelPunk::button5_Click);
			   // 
			   // button6
			   // 
			   this->button6->Location = System::Drawing::Point(172, 25);
			   this->button6->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(100, 28);
			   this->button6->TabIndex = 10;
			   this->button6->Text = L"Punk 3";
			   this->button6->UseVisualStyleBackColor = true;
			   this->button6->Visible = false;
			   this->button6->Click += gcnew System::EventHandler(this, &NivelPunk::button6_Click);
			   // 
			   // button8
			   // 
			   this->button8->Location = System::Drawing::Point(28, 25);
			   this->button8->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(100, 28);
			   this->button8->TabIndex = 11;
			   this->button8->Text = L"Punk m";
			   this->button8->UseVisualStyleBackColor = true;
			   this->button8->Visible = false;
			   this->button8->Click += gcnew System::EventHandler(this, &NivelPunk::button8_Click);
			   // 
			   // pnlJuego3
			   // 
			   this->pnlJuego3->Controls->Add(this->button4);
			   this->pnlJuego3->Controls->Add(this->button3);
			   this->pnlJuego3->Controls->Add(this->button1);
			   this->pnlJuego3->Location = System::Drawing::Point(16, 121);
			   this->pnlJuego3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pnlJuego3->Name = L"pnlJuego3";
			   this->pnlJuego3->Size = System::Drawing::Size(1620, 839);
			   this->pnlJuego3->TabIndex = 3;
			   this->pnlJuego3->Visible = false;
			   // 
			   // button4
			   // 
			   this->button4->Location = System::Drawing::Point(460, 25);
			   this->button4->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(100, 28);
			   this->button4->TabIndex = 4;
			   this->button4->Text = L"Punk 1";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Visible = false;
			   this->button4->Click += gcnew System::EventHandler(this, &NivelPunk::button4_Click);
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(316, 25);
			   this->button3->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(100, 28);
			   this->button3->TabIndex = 5;
			   this->button3->Text = L"Punk 2";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Visible = false;
			   this->button3->Click += gcnew System::EventHandler(this, &NivelPunk::button3_Click);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(28, 25);
			   this->button1->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(100, 28);
			   this->button1->TabIndex = 7;
			   this->button1->Text = L"Punk m";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Visible = false;
			   this->button1->Click += gcnew System::EventHandler(this, &NivelPunk::button1_Click);
			   // 
			   // pnlJuegoMusical
			   // 
			   this->pnlJuegoMusical->Controls->Add(this->btnPunk3);
			   this->pnlJuegoMusical->Controls->Add(this->btnPunk2);
			   this->pnlJuegoMusical->Controls->Add(this->btnPunk1);
			   this->pnlJuegoMusical->Location = System::Drawing::Point(16, 121);
			   this->pnlJuegoMusical->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->pnlJuegoMusical->Name = L"pnlJuegoMusical";
			   this->pnlJuegoMusical->Size = System::Drawing::Size(1620, 839);
			   this->pnlJuegoMusical->TabIndex = 4;
			   this->pnlJuegoMusical->Visible = false;
			   this->pnlJuegoMusical->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &NivelPunk::pnlJuegoMusical_Paint);
			   // 
			   // btnPunk3
			   // 
			   this->btnPunk3->Location = System::Drawing::Point(32, 25);
			   this->btnPunk3->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->btnPunk3->Name = L"btnPunk3";
			   this->btnPunk3->Size = System::Drawing::Size(100, 28);
			   this->btnPunk3->TabIndex = 2;
			   this->btnPunk3->Text = L"Punk 3";
			   this->btnPunk3->UseVisualStyleBackColor = true;
			   this->btnPunk3->Visible = false;
			   this->btnPunk3->Click += gcnew System::EventHandler(this, &NivelPunk::btnPunk3_Click);
			   // 
			   // btnPunk2
			   // 
			   this->btnPunk2->Location = System::Drawing::Point(176, 25);
			   this->btnPunk2->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->btnPunk2->Name = L"btnPunk2";
			   this->btnPunk2->Size = System::Drawing::Size(100, 28);
			   this->btnPunk2->TabIndex = 1;
			   this->btnPunk2->Text = L"Punk 2";
			   this->btnPunk2->UseVisualStyleBackColor = true;
			   this->btnPunk2->Visible = false;
			   this->btnPunk2->Click += gcnew System::EventHandler(this, &NivelPunk::btnPunk2_Click);
			   // 
			   // btnPunk1
			   // 
			   this->btnPunk1->Location = System::Drawing::Point(320, 25);
			   this->btnPunk1->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->btnPunk1->Name = L"btnPunk1";
			   this->btnPunk1->Size = System::Drawing::Size(100, 28);
			   this->btnPunk1->TabIndex = 0;
			   this->btnPunk1->Text = L"Punk 1";
			   this->btnPunk1->UseVisualStyleBackColor = true;
			   this->btnPunk1->Visible = false;
			   this->btnPunk1->Click += gcnew System::EventHandler(this, &NivelPunk::btnPunk1_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->label4);
			   this->panel1->Location = System::Drawing::Point(16, 11);
			   this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1620, 109);
			   this->panel1->TabIndex = 4;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::Color::Transparent;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(25, 12);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(67, 28);
			   this->label4->TabIndex = 0;
			   this->label4->Text = L"label4";
			   // 
			   // NivelPunk
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->ClientSize = System::Drawing::Size(1655, 1040);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->pnlDeControl);
			   this->Controls->Add(this->pnlJuego2);
			   this->Controls->Add(this->pnlJuego1);
			   this->Controls->Add(this->pnlJuego3);
			   this->Controls->Add(this->pnlJuegoMusical);
			   this->Margin = System::Windows::Forms::Padding(4, 2, 4, 2);
			   this->Name = L"NivelPunk";
			   this->Text = L"NivelPunk";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &NivelPunk::NivelPunk_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &NivelPunk::NivelPunk_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &NivelPunk::NivelPunk_KeyDown);
			   this->pnlDeControl->ResumeLayout(false);
			   this->pnlDeControl->PerformLayout();
			   this->pnlJuego1->ResumeLayout(false);
			   this->pnlJuego2->ResumeLayout(false);
			   this->pnlJuego3->ResumeLayout(false);
			   this->pnlJuegoMusical->ResumeLayout(false);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
		   System::Void NivelPunk_Load(System::Object^ sender, System::EventArgs^ e) {

			   grp = pnlDeControl->CreateGraphics();
			   spacep = BufferedGraphicsManager::Current;
			   bufferp = spacep->Allocate(grp, pnlDeControl->ClientRectangle);

			   gr1 = pnlJuego1->CreateGraphics();
			   space1 = BufferedGraphicsManager::Current;
			   buffer1 = space1->Allocate(gr1, pnlJuego1->ClientRectangle);

			   gr2 = pnlJuego2->CreateGraphics();
			   space2 = BufferedGraphicsManager::Current;
			   buffer2 = space2->Allocate(gr2, pnlJuego2->ClientRectangle);

			   gr3 = pnlJuego3->CreateGraphics();
			   space3 = BufferedGraphicsManager::Current;
			   buffer3 = space3->Allocate(gr3, pnlJuego3->ClientRectangle);

			   bmpPanelControl = gcnew Bitmap("Imagenes/PanelControl.png");
			   bmpMapa1 = gcnew Bitmap("Imagenes/PunkMapa1.png");
			   bmpMapa2 = gcnew Bitmap("Imagenes/PunkMapa2.png");
			   bmpMapa3 = gcnew Bitmap("Imagenes/PunkMapa3.png");
			   bmpMapaMusical = gcnew Bitmap("Imagenes/PunkMapaMusical.png");
			   bmpPunk = gcnew Bitmap("Imagenes/SpiderPunk.png");
			   bmpCofreC = gcnew Bitmap("Imagenes/CofreCerrado.png");
			   bmpCofreA = gcnew Bitmap("Imagenes/CofreAbierto.png");
			   bmpSpot = gcnew Bitmap("Imagenes/Spot.png");
			   bmpNota1 = gcnew Bitmap("Imagenes/NotasMusicales1.png");
			   bmpNota2 = gcnew Bitmap("Imagenes/NotasMusicales2.png");
			   bmpNota3 = gcnew Bitmap("Imagenes/NotasMusicales3.png");
			   bmpProyectilMalo = gcnew Bitmap("Imagenes/Misiles.png");

			   punk = new SpiderPunk(100, 300, 64, 64, 100, 10, 10, 100, 100, 0, "Punk", 'S', 1, 1);
			   IrASala(1, 100, 300);
		   }

	private: System::Void timerJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		bufferp->Graphics->DrawImage(bmpPanelControl, 0, 0, pnlDeControl->Width * 1.0, pnlDeControl->Height * 1.0);

		if (pnlJuego1->Visible == true) {
			buffer1->Graphics->DrawImage(bmpMapa1, 0, 0, pnlJuego1->Width * 1.0, pnlJuego1->Height * 1.0);
			controladora->DibujarCofres(buffer1->Graphics, bmpCofreC, bmpCofreA);
			punk->Dibujar(buffer1->Graphics, bmpPunk);
			DibujarDebug(buffer1->Graphics, pnlJuego1);
			buffer1->Render(gr1);
		}
		if (pnlJuego2->Visible == true) {
			buffer2->Graphics->DrawImage(bmpMapa2, 0, 0, pnlJuego2->Width * 1.0, pnlJuego2->Height * 1.0);
			controladora->DibujarCofres(buffer2->Graphics, bmpCofreC, bmpCofreA);
			punk->Dibujar(buffer2->Graphics, bmpPunk);
			DibujarDebug(buffer2->Graphics, pnlJuego2);
			buffer2->Render(gr2);
		}
		if (pnlJuego3->Visible == true) {
			buffer3->Graphics->DrawImage(bmpMapa3, 0, 0, pnlJuego3->Width * 1.0, pnlJuego3->Height * 1.0);
			controladora->ActualizarJefes(punk, pnlJuego3->Width, pnlJuego3->Height);
			controladora->ActualizarProyectiles(pnlJuego3->Width, pnlJuego3->Height);
			controladora->DibujarProyectiles(buffer3->Graphics, bmpNota1);
			controladora->ActualizarProyectilesHorizontales(punk, pnlJuego3->Width);
			controladora->DibujarProyectilesHorizontales(buffer3->Graphics, bmpProyectilMalo);
			controladora->DibujarJefe(buffer3->Graphics, bmpSpot);
			punk->Dibujar(buffer3->Graphics, bmpPunk);
			DibujarDebug(buffer3->Graphics, pnlJuego3);
			buffer3->Render(gr3);
			if (ComprobarFinCombate()) return;
		}

		bufferp->Render(grp);

		lblVida->Text = "Vida: " + punk->getVida();
		lblPersonaje->Text = "Spider Punk: ";
		lblPuntaje->Text = "Puntaje: " + 10;

		if (pnlJuego3->Visible == true) {
			lblSpot->Text = "Vida de Spot: " + controladora->getJefe()->getVida();
		}
		else {
			lblSpot->Text = " ";
		}
	}
	private: System::Void NivelPunk_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		timerJuego->Enabled = false;
	}
	private: System::Void NivelPunk_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		int xAnterior = punk->GetPX();
		int yAnterior = punk->GetPY();
		switch (e->KeyCode) {
		case Keys::A:
			punk->move(buffer1->Graphics, 'A');
			break;
		case Keys::D:
			punk->move(buffer1->Graphics, 'D');
			break;
		case Keys::W:
			punk->move(buffer1->Graphics, 'W');
			break;
		case Keys::S:
			punk->move(buffer1->Graphics, 'S');
			break;
		case Keys::F:
			if (pnlJuego3->Visible == true) {
				controladora->Disparar(punk);
			}
			break;
		case Keys::E: {
			Cofre* cofre = controladora->CofreColisionando(punk);
			if (cofre != nullptr && !cofre->GetAbierto()) {     
				if (JugarRitmo(1)) {                             
					cofre->SetAbierto(true);
					MarcarCofre(cofre->GetId());
				}
			}
			break;
		}
		case Keys::F2:
			modoDebug = !modoDebug;
			button1->Visible = modoDebug;
			button3->Visible = modoDebug;
			button4->Visible = modoDebug;
			button5->Visible = modoDebug;
			button6->Visible = modoDebug;
			button8->Visible = modoDebug;
			button10->Visible = modoDebug;
			button11->Visible = modoDebug;
			button12->Visible = modoDebug;
			break;
		default:break;
		}
		if (controladora->HayColision(punk)) {
			punk->SetPX(xAnterior);
			punk->SetPY(yAnterior);
		}
		Puerta* puerta = controladora->PuertaColisionando(punk);
		if (puerta != nullptr) {
			if (PuedeEntrarSala(puerta->GetNivelDestino())) {
				IrASala(puerta->GetNivelDestino(), puerta->GetXDestino(), puerta->GetYDestino());
				return;   
			}
			MessageBox::Show("La puerta esta cerrada. Abre los 3 cofres primero.");
			punk->SetPX(xAnterior);
			punk->SetPY(yAnterior);
			return;
		}

		if (controladora->HayColision(punk)) {
			punk->SetPX(xAnterior);
			punk->SetPY(yAnterior);
		}
	}
	private: System::Void pnlJuego1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuego3->Visible = false;
			pnlJuegoMusical->Visible = true;
			CargarNivelMusical(1);
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuego3->Visible = false;
			pnlJuego2->Visible = true;
			CargarNivel2();
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuego3->Visible = false;
			pnlJuego1->Visible = true;
			CargarNivel1();
		}
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuego2->Visible = false;
			pnlJuegoMusical->Visible = true;
			CargarNivelMusical(1);
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuego2->Visible = false;
			pnlJuego3->Visible = true;
			CargarNivel3();
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuego2->Visible = false;
			pnlJuego1->Visible = true;
			CargarNivel1();
		}
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuego1->Visible = false;
			pnlJuegoMusical->Visible = true;
			CargarNivelMusical(1);
		}
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuego1->Visible = false;
			pnlJuego3->Visible = true;
			CargarNivel3();
		}
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuego1->Visible = false;
			pnlJuego2->Visible = true;
			CargarNivel2();
		}
	}
	private: System::Void btnPunk3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuegoMusical->Visible = false;
			pnlJuego3->Visible = true;
			CargarNivel3();
		}
	}
	private: System::Void btnPunk2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuegoMusical->Visible = false;
			pnlJuego2->Visible = true;
			CargarNivel2();
		}
	}
	private: System::Void btnPunk1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoDebug) {
			pnlJuegoMusical->Visible = false;
			pnlJuego1->Visible = true;
			CargarNivel1();
		}
	}
	private: System::Void pnlJuegoMusical_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pnlDeControl_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	};
}
