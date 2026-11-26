#pragma once
#include "MiguelOhara.h"
#include "Controladora.h"
#include "Dialogos.h"

namespace AlgoritmosProyectoFinal2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de NivelMiguel
	/// </summary>
	public ref class NivelMiguel : public System::Windows::Forms::Form
	{
	public:
		NivelMiguel(void)
		{
			InitializeComponent();
			controladora = new Controladora();
			this->KeyPreview = true;
			srand((unsigned int)time(nullptr));
		}

		void DibujarDebug(Graphics^ g, Panel^ panel) {  // Overley con f2
			if (!modoDebug) return;
			controladora->DibujarPuertas(g);
			controladora->DibujarObstaculos(g);
			Point m = panel->PointToClient(System::Windows::Forms::Cursor::Position);
			System::String^ info = "[F2 ocultar]  Mouse: " + System::Convert::ToString(m.X) + ", " + System::Convert::ToString(m.Y)
				+ "   Punk: " + System::Convert::ToString(miguel->GetPX()) + ", " + System::Convert::ToString(miguel->GetPY());
			g->FillRectangle(Brushes::Black, 0, 0, 430, 20);
			g->DrawString(info, SystemFonts::DefaultFont, Brushes::Lime, 4.0f, 4.0f);
		}

		void SoltarTeclas() {
			teclaA = false; teclaD = false; teclaW = false; teclaS = false;
		}

		void IrASala(int sala, int px, int py) {
			salaActual = sala;
			pnlJuego1->Visible = (sala == 1);
			pnlJuego2->Visible = (sala == 2);
			pnlJuego3->Visible = (sala == 3);
			pnlJuego4->Visible = (sala == 4);
			pnlJuego5->Visible = (sala == 5);
			pnlJuego6->Visible = (sala == 6);
			pnlJuego7->Visible = (sala == 7);
			pnlJuego8->Visible = (sala == 8);
			pnlJuego9->Visible = (sala == 9);
			pnlJuego10->Visible = (sala == 10);
			pnlJuego11->Visible = (sala == 11);
			pnlJuego12->Visible = (sala == 12);
			pnlJuego13->Visible = (sala == 13);
			pnlJuego14->Visible = (sala == 14);
			pnlJuego15->Visible = (sala == 15);
			pnlJuego16->Visible = (sala == 16);
			pnlJuego17->Visible = (sala == 17);
			pnlJuego18->Visible = (sala == 18);
			pnlJuego19->Visible = (sala == 19);
			pnlJuego20->Visible = (sala == 20);
			pnlJuego21->Visible = (sala == 21);
			pnlJuego22->Visible = (sala == 22);
			pnlJuego23->Visible = (sala == 23);
			pnlJuego24->Visible = (sala == 24);
			pnlJuego25->Visible = (sala == 25);
			switch (sala) {
			case 1: CargarNivel1(); break;
			case 2: CargarNivel2(); break;
			case 3: CargarNivel3(); break;
			case 4: CargarNivel4(); break;
			case 5: CargarNivel5(); break;
			case 6: CargarNivel6(); break;
			case 7: CargarNivel7(); break;
			case 8: CargarNivel8(); break;
			case 9: CargarNivel9(); break;
			case 10: CargarNivel10(); break;
			case 11: CargarNivel11(); break;
			case 12: CargarNivel12(); break;
			case 13: CargarNivel13(); break;
			case 14: CargarNivel14(); break;
			case 15: CargarNivel15(); break;
			case 16: CargarNivel16(); break;
			case 17: CargarNivel17(); break;
			case 18: CargarNivel18(); break;
			case 19: CargarNivel19(); break;
			case 20: CargarNivel20(); break;
			case 21: CargarNivel21(); break;
			case 22: CargarNivel22(); break;
			case 23: CargarNivel23(); break;
			case 24: CargarNivel24(); break;
			case 25: CargarNivel25(); break;
			}
			miguel->SetPX(px);
			miguel->SetPY(py);
		}

		void CargarNivel1() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarPeny(60, 320, 50, 50);

			controladora->GenerarObstaculo(0, 0, 0, 225, 1210);
			controladora->GenerarObstaculo(0, 415, 0, 225, 450);
			controladora->GenerarObstaculo(760, 415, 0, 225, 450);

			controladora->AgregarMancha(35, 260, 75, 150);

			controladora->GenerarPuerta(35, 260, 75, 150, 18, 1050, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
			controladora->GenerarPuerta(1200, 0, 60, 840, 2, 60, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
			controladora->GenerarPuerta(0, 650, 1210, 30, 6, 590, 40);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada) hacia abajo
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

			controladora->GenerarPuerta(0, 285, 40, 183, 1, 1100, 300);
			controladora->GenerarPuerta(1200, 0, 60, 840, 3, 60, 650);
		}

		void CargarNivel3() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarObstaculo(0, 0, 0, 285, 435);
			controladora->GenerarObstaculo(790, 0, 0, 285, 445);
			controladora->GenerarObstaculo(1080, 460, 0, 225, 130);
			controladora->GenerarObstaculo(792, 460, 0, 225, 215);
			controladora->GenerarObstaculo(0, 468, 0, 285, 435);

			controladora->GenerarPuerta(0, 285, 40, 183, 1, 1100, 300);
			controladora->GenerarPuerta(1200, 0, 60, 840, 3, 60, 650);
		}

		void CargarNivel4() {

		}

		void CargarNivel5() {

		}

		void CargarNivel6() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarPeny(60, 320, 50, 50);

			controladora->GenerarObstaculo(0, 0, 0, 225, 450);
			controladora->GenerarObstaculo(760, 0, 0, 225, 450);
			controladora->GenerarObstaculo(0, 415, 0, 225, 450);
			controladora->GenerarObstaculo(760, 415, 0, 225, 450);


			controladora->GenerarPuerta(1200, 0, 30, 840, 17, 60, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada) hacia la derecha
			controladora->GenerarPuerta(0, 0, 1210, 30, 11, 590, 580);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada) hacia arriba
			controladora->GenerarPuerta(0, 650, 1210, 30, 21, 590, 40);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada) hacia abajo
		}

		void CargarNivel7() {

		}

		void CargarNivel8() {

		}

		void CargarNivel9() {

		}

		void CargarNivel10() {

		}

		void CargarNivel11() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarPeny(60, 320, 50, 50);

			controladora->GenerarObstaculo(0, 0, 0, 225, 1210);
			controladora->GenerarObstaculo(0, 415, 0, 225, 450);
			controladora->GenerarObstaculo(760, 415, 0, 225, 450);

			controladora->GenerarPuerta(0, 650, 1210, 30, 16, 590, 40);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
		}

		void CargarNivel12() {

		}

		void CargarNivel13() {

		}

		void CargarNivel14() {

		}

		void CargarNivel15() {

		}

		void CargarNivel16() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarPeny(60, 320, 50, 50);

			controladora->GenerarObstaculo(0, 0, 0, 225, 450);
			controladora->GenerarObstaculo(760, 0, 0, 225, 450);
			controladora->GenerarObstaculo(0, 415, 0, 225, 450);
			controladora->GenerarObstaculo(760, 415, 0, 225, 450);


			controladora->GenerarPuerta(1200, 0, 30, 840, 17, 60, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada) hacia la derecha
			controladora->GenerarPuerta(0, 0, 1210, 30, 11, 590, 580);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada) hacia arriba
			controladora->GenerarPuerta(0, 650, 1210, 30, 21, 590, 40);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada) hacia abajo
		}

		void CargarNivel17() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarPeny(60, 320, 50, 50);

			controladora->GenerarObstaculo(0, 0, 0, 225, 1210);
			controladora->GenerarObstaculo(0, 415, 0, 225, 1210);

			controladora->GenerarPuerta(0, 0, 30, 840, 16, 1120, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
			controladora->GenerarPuerta(1200, 0, 30, 840, 18, 60, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
		}

		void CargarNivel18() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarPeny(60, 320, 50, 50);

			controladora->GenerarObstaculo(0, 0, 0, 225, 1210);
			controladora->GenerarObstaculo(0, 415, 0, 225, 1210);

			controladora->AgregarMancha(1100, 260, 75, 150);

			controladora->GenerarPuerta(0, 0, 30, 840, 17, 1120, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
			controladora->GenerarPuerta(1100, 260, 75, 150, 1, 150, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
		}

		void CargarNivel19() {

		}

		void CargarNivel20() {

		}

		void CargarNivel21() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarPeny(60, 320, 50, 50);

			controladora->GenerarObstaculo(0, 0, 0, 225, 450);
			controladora->GenerarObstaculo(760, 0, 0, 225, 450);
			controladora->GenerarObstaculo(0, 415, 0, 225, 1210);

			controladora->GenerarPuerta(0, 0, 1210, 30, 16, 590, 580);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
		}

		void CargarNivel22() {

		}

		void CargarNivel23() {

		}

		void CargarNivel24() {

		}

		void CargarNivel25() {

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~NivelMiguel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlJuego2;
	private: System::Windows::Forms::Panel^ pnlTexto;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ pnlDeControl;

	private: System::Windows::Forms::Panel^ pnlJuego25;

	private: System::Windows::Forms::Panel^ pnlJuego24;

	private: System::Windows::Forms::Panel^ pnlJuego23;

	private: System::Windows::Forms::Panel^ pnlJuego22;

	private: System::Windows::Forms::Panel^ pnlJuego21;

	private: System::Windows::Forms::Panel^ pnlJuego20;

	private: System::Windows::Forms::Panel^ pnlJuego19;

	private: System::Windows::Forms::Panel^ pnlJuego18;

	private: System::Windows::Forms::Panel^ pnlJuego17;

	private: System::Windows::Forms::Panel^ pnlJuego16;

	private: System::Windows::Forms::Panel^ pnlJuego15;

	private: System::Windows::Forms::Panel^ pnlJuego14;

	private: System::Windows::Forms::Panel^ pnlJuego13;

	private: System::Windows::Forms::Panel^ pnlJuego12;

	private: System::Windows::Forms::Panel^ pnlJuego11;

	private: System::Windows::Forms::Panel^ pnlJuego10;

	private: System::Windows::Forms::Panel^ pnlJuego9;

	private: System::Windows::Forms::Panel^ pnlJuego8;

	private: System::Windows::Forms::Panel^ pnlJuego7;

	private: System::Windows::Forms::Panel^ pnlJuego6;

	private: System::Windows::Forms::Panel^ pnlJuego5;

	private: System::Windows::Forms::Panel^ pnlJuego4;

	private: System::Windows::Forms::Panel^ pnlJuego3;

	private: System::Windows::Forms::Panel^ pnlJuego1;

	protected private: System::Windows::Forms::Panel^ pnlAnimacion;
private: System::ComponentModel::IContainer^ components;
protected private:
	private:

	private:
	protected:

	private:


		Controladora* controladora;

		Graphics^ gr0;
		Graphics^ gr1;
		Graphics^ gr2;
		Graphics^ gr3;
		Graphics^ gr4;
		Graphics^ gr5;
		Graphics^ gr6;
		Graphics^ gr7;
		Graphics^ gr8;
		Graphics^ gr9;
		Graphics^ gr10;
		Graphics^ gr11;
		Graphics^ gr12;
		Graphics^ gr13;
		Graphics^ gr14;
		Graphics^ gr15;
		Graphics^ gr16;
		Graphics^ gr17;
		Graphics^ gr18;
		Graphics^ gr19;
		Graphics^ gr20;
		Graphics^ gr21;
		Graphics^ gr22;
		Graphics^ gr23;
		Graphics^ gr24;
		Graphics^ gr25;
		Graphics^ grp;

		BufferedGraphicsContext^ space0;
		BufferedGraphicsContext^ space1;
		BufferedGraphicsContext^ space2;
		BufferedGraphicsContext^ space3;
		BufferedGraphicsContext^ space4;
		BufferedGraphicsContext^ space5;
		BufferedGraphicsContext^ space6;
		BufferedGraphicsContext^ space7;
		BufferedGraphicsContext^ space8;
		BufferedGraphicsContext^ space9;
		BufferedGraphicsContext^ space10;
		BufferedGraphicsContext^ space11;
		BufferedGraphicsContext^ space12;
		BufferedGraphicsContext^ space13;
		BufferedGraphicsContext^ space14;
		BufferedGraphicsContext^ space15;
		BufferedGraphicsContext^ space16;
		BufferedGraphicsContext^ space17;
		BufferedGraphicsContext^ space18;
		BufferedGraphicsContext^ space19;
		BufferedGraphicsContext^ space20;
		BufferedGraphicsContext^ space21;
		BufferedGraphicsContext^ space22;
		BufferedGraphicsContext^ space23;
		BufferedGraphicsContext^ space24;
		BufferedGraphicsContext^ space25;
		BufferedGraphicsContext^ spacep;

		BufferedGraphics^ buffer0;
		BufferedGraphics^ buffer1;
		BufferedGraphics^ buffer2;
		BufferedGraphics^ buffer3;
		BufferedGraphics^ buffer4;
		BufferedGraphics^ buffer5;
		BufferedGraphics^ buffer6;
		BufferedGraphics^ buffer7;
		BufferedGraphics^ buffer8;
		BufferedGraphics^ buffer9;
		BufferedGraphics^ buffer10;
		BufferedGraphics^ buffer11;
		BufferedGraphics^ buffer12;
		BufferedGraphics^ buffer13;
		BufferedGraphics^ buffer14;
		BufferedGraphics^ buffer15;
		BufferedGraphics^ buffer16;
		BufferedGraphics^ buffer17;
		BufferedGraphics^ buffer18;
		BufferedGraphics^ buffer19;
		BufferedGraphics^ buffer20;
		BufferedGraphics^ buffer21;
		BufferedGraphics^ buffer22;
		BufferedGraphics^ buffer23;
		BufferedGraphics^ buffer24;
		BufferedGraphics^ buffer25;
		BufferedGraphics^ bufferp;

		Bitmap^ bmpMapa1;
		Bitmap^ bmpMapa2;
		Bitmap^ bmpMapa3;
		Bitmap^ bmpMapa4;
		Bitmap^ bmpMiguel;
		Bitmap^ bmpPanelControl;
		Bitmap^ bmpMancha;

		NovelaVisual^ novela;
		MiguelOhara* miguel;

		bool modoDebug = false;
		int salaActual = 16;
		char ultimaDir = ' ';
		bool teclaA = false, teclaD = false, teclaW = false, teclaS = false;

private: System::Windows::Forms::Label^ lblPersonaje;
private: System::Windows::Forms::Label^ lblVida;
private: System::Windows::Forms::Label^ lblPuntaje;
private: System::Windows::Forms::Label^ lblLejania;
private: System::Windows::Forms::Timer^ timerJuego;
private: System::Windows::Forms::Timer^ timerMovimiento;
private: System::Windows::Forms::Timer^ timerAnimacion;









#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlJuego2 = (gcnew System::Windows::Forms::Panel());
			this->pnlTexto = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pnlDeControl = (gcnew System::Windows::Forms::Panel());
			this->lblVida = (gcnew System::Windows::Forms::Label());
			this->lblPuntaje = (gcnew System::Windows::Forms::Label());
			this->lblLejania = (gcnew System::Windows::Forms::Label());
			this->lblPersonaje = (gcnew System::Windows::Forms::Label());
			this->pnlJuego25 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego24 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego23 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego22 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego21 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego20 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego19 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego18 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego17 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego16 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego15 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego14 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego13 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego12 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego11 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego10 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego9 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego8 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego7 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego6 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego5 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego4 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego3 = (gcnew System::Windows::Forms::Panel());
			this->pnlJuego1 = (gcnew System::Windows::Forms::Panel());
			this->pnlAnimacion = (gcnew System::Windows::Forms::Panel());
			this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerMovimiento = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerAnimacion = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlTexto->SuspendLayout();
			this->pnlDeControl->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlJuego2
			// 
			this->pnlJuego2->Location = System::Drawing::Point(16, 121);
			this->pnlJuego2->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego2->Name = L"pnlJuego2";
			this->pnlJuego2->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego2->TabIndex = 3;
			this->pnlJuego2->Visible = false;
			// 
			// pnlTexto
			// 
			this->pnlTexto->Controls->Add(this->label4);
			this->pnlTexto->Location = System::Drawing::Point(16, 11);
			this->pnlTexto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pnlTexto->Name = L"pnlTexto";
			this->pnlTexto->Size = System::Drawing::Size(1620, 109);
			this->pnlTexto->TabIndex = 5;
			this->pnlTexto->Visible = false;
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
			// pnlDeControl
			// 
			this->pnlDeControl->Controls->Add(this->lblVida);
			this->pnlDeControl->Controls->Add(this->lblPuntaje);
			this->pnlDeControl->Controls->Add(this->lblLejania);
			this->pnlDeControl->Controls->Add(this->lblPersonaje);
			this->pnlDeControl->Location = System::Drawing::Point(16, 11);
			this->pnlDeControl->Margin = System::Windows::Forms::Padding(4);
			this->pnlDeControl->Name = L"pnlDeControl";
			this->pnlDeControl->Size = System::Drawing::Size(1620, 109);
			this->pnlDeControl->TabIndex = 4;
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
			this->lblVida->TabIndex = 4;
			this->lblVida->Text = L"lblVida";
			this->lblVida->Click += gcnew System::EventHandler(this, &NivelMiguel::label3_Click);
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
			this->lblPuntaje->TabIndex = 3;
			this->lblPuntaje->Text = L"lblPuntaje";
			// 
			// lblLejania
			// 
			this->lblLejania->AutoSize = true;
			this->lblLejania->BackColor = System::Drawing::Color::Transparent;
			this->lblLejania->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblLejania->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->lblLejania->Location = System::Drawing::Point(783, 55);
			this->lblLejania->Name = L"lblLejania";
			this->lblLejania->Size = System::Drawing::Size(100, 28);
			this->lblLejania->TabIndex = 2;
			this->lblLejania->Text = L"lblLejania";
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
			this->lblPersonaje->TabIndex = 1;
			this->lblPersonaje->Text = L"lblPersonaje";
			// 
			// pnlJuego25
			// 
			this->pnlJuego25->Location = System::Drawing::Point(16, 121);
			this->pnlJuego25->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego25->Name = L"pnlJuego25";
			this->pnlJuego25->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego25->TabIndex = 5;
			this->pnlJuego25->Visible = false;
			// 
			// pnlJuego24
			// 
			this->pnlJuego24->Location = System::Drawing::Point(16, 121);
			this->pnlJuego24->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego24->Name = L"pnlJuego24";
			this->pnlJuego24->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego24->TabIndex = 6;
			this->pnlJuego24->Visible = false;
			// 
			// pnlJuego23
			// 
			this->pnlJuego23->Location = System::Drawing::Point(16, 121);
			this->pnlJuego23->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego23->Name = L"pnlJuego23";
			this->pnlJuego23->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego23->TabIndex = 7;
			this->pnlJuego23->Visible = false;
			// 
			// pnlJuego22
			// 
			this->pnlJuego22->Location = System::Drawing::Point(16, 121);
			this->pnlJuego22->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego22->Name = L"pnlJuego22";
			this->pnlJuego22->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego22->TabIndex = 8;
			this->pnlJuego22->Visible = false;
			// 
			// pnlJuego21
			// 
			this->pnlJuego21->Location = System::Drawing::Point(16, 121);
			this->pnlJuego21->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego21->Name = L"pnlJuego21";
			this->pnlJuego21->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego21->TabIndex = 9;
			this->pnlJuego21->Visible = false;
			// 
			// pnlJuego20
			// 
			this->pnlJuego20->Location = System::Drawing::Point(16, 121);
			this->pnlJuego20->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego20->Name = L"pnlJuego20";
			this->pnlJuego20->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego20->TabIndex = 10;
			this->pnlJuego20->Visible = false;
			// 
			// pnlJuego19
			// 
			this->pnlJuego19->Location = System::Drawing::Point(16, 121);
			this->pnlJuego19->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego19->Name = L"pnlJuego19";
			this->pnlJuego19->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego19->TabIndex = 11;
			this->pnlJuego19->Visible = false;
			// 
			// pnlJuego18
			// 
			this->pnlJuego18->Location = System::Drawing::Point(16, 121);
			this->pnlJuego18->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego18->Name = L"pnlJuego18";
			this->pnlJuego18->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego18->TabIndex = 12;
			this->pnlJuego18->Visible = false;
			// 
			// pnlJuego17
			// 
			this->pnlJuego17->Location = System::Drawing::Point(16, 121);
			this->pnlJuego17->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego17->Name = L"pnlJuego17";
			this->pnlJuego17->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego17->TabIndex = 13;
			this->pnlJuego17->Visible = false;
			// 
			// pnlJuego16
			// 
			this->pnlJuego16->Location = System::Drawing::Point(16, 121);
			this->pnlJuego16->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego16->Name = L"pnlJuego16";
			this->pnlJuego16->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego16->TabIndex = 14;
			// 
			// pnlJuego15
			// 
			this->pnlJuego15->Location = System::Drawing::Point(16, 121);
			this->pnlJuego15->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego15->Name = L"pnlJuego15";
			this->pnlJuego15->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego15->TabIndex = 15;
			this->pnlJuego15->Visible = false;
			// 
			// pnlJuego14
			// 
			this->pnlJuego14->Location = System::Drawing::Point(16, 121);
			this->pnlJuego14->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego14->Name = L"pnlJuego14";
			this->pnlJuego14->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego14->TabIndex = 16;
			this->pnlJuego14->Visible = false;
			// 
			// pnlJuego13
			// 
			this->pnlJuego13->Location = System::Drawing::Point(16, 121);
			this->pnlJuego13->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego13->Name = L"pnlJuego13";
			this->pnlJuego13->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego13->TabIndex = 17;
			this->pnlJuego13->Visible = false;
			// 
			// pnlJuego12
			// 
			this->pnlJuego12->Location = System::Drawing::Point(16, 121);
			this->pnlJuego12->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego12->Name = L"pnlJuego12";
			this->pnlJuego12->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego12->TabIndex = 18;
			this->pnlJuego12->Visible = false;
			// 
			// pnlJuego11
			// 
			this->pnlJuego11->Location = System::Drawing::Point(16, 121);
			this->pnlJuego11->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego11->Name = L"pnlJuego11";
			this->pnlJuego11->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego11->TabIndex = 19;
			this->pnlJuego11->Visible = false;
			// 
			// pnlJuego10
			// 
			this->pnlJuego10->Location = System::Drawing::Point(16, 121);
			this->pnlJuego10->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego10->Name = L"pnlJuego10";
			this->pnlJuego10->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego10->TabIndex = 20;
			this->pnlJuego10->Visible = false;
			// 
			// pnlJuego9
			// 
			this->pnlJuego9->Location = System::Drawing::Point(16, 121);
			this->pnlJuego9->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego9->Name = L"pnlJuego9";
			this->pnlJuego9->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego9->TabIndex = 21;
			this->pnlJuego9->Visible = false;
			// 
			// pnlJuego8
			// 
			this->pnlJuego8->Location = System::Drawing::Point(16, 121);
			this->pnlJuego8->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego8->Name = L"pnlJuego8";
			this->pnlJuego8->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego8->TabIndex = 22;
			this->pnlJuego8->Visible = false;
			// 
			// pnlJuego7
			// 
			this->pnlJuego7->Location = System::Drawing::Point(16, 121);
			this->pnlJuego7->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego7->Name = L"pnlJuego7";
			this->pnlJuego7->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego7->TabIndex = 23;
			this->pnlJuego7->Visible = false;
			// 
			// pnlJuego6
			// 
			this->pnlJuego6->Location = System::Drawing::Point(16, 121);
			this->pnlJuego6->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego6->Name = L"pnlJuego6";
			this->pnlJuego6->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego6->TabIndex = 24;
			this->pnlJuego6->Visible = false;
			// 
			// pnlJuego5
			// 
			this->pnlJuego5->Location = System::Drawing::Point(16, 121);
			this->pnlJuego5->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego5->Name = L"pnlJuego5";
			this->pnlJuego5->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego5->TabIndex = 25;
			this->pnlJuego5->Visible = false;
			// 
			// pnlJuego4
			// 
			this->pnlJuego4->Location = System::Drawing::Point(16, 121);
			this->pnlJuego4->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego4->Name = L"pnlJuego4";
			this->pnlJuego4->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego4->TabIndex = 26;
			this->pnlJuego4->Visible = false;
			// 
			// pnlJuego3
			// 
			this->pnlJuego3->Location = System::Drawing::Point(16, 121);
			this->pnlJuego3->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego3->Name = L"pnlJuego3";
			this->pnlJuego3->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego3->TabIndex = 27;
			this->pnlJuego3->Visible = false;
			// 
			// pnlJuego1
			// 
			this->pnlJuego1->Location = System::Drawing::Point(16, 121);
			this->pnlJuego1->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego1->Name = L"pnlJuego1";
			this->pnlJuego1->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego1->TabIndex = 28;
			this->pnlJuego1->Visible = false;
			// 
			// pnlAnimacion
			// 
			this->pnlAnimacion->Location = System::Drawing::Point(16, 121);
			this->pnlAnimacion->Margin = System::Windows::Forms::Padding(4);
			this->pnlAnimacion->Name = L"pnlAnimacion";
			this->pnlAnimacion->Size = System::Drawing::Size(1620, 839);
			this->pnlAnimacion->TabIndex = 29;
			this->pnlAnimacion->Visible = false;
			// 
			// timerJuego
			// 
			this->timerJuego->Enabled = true;
			this->timerJuego->Tick += gcnew System::EventHandler(this, &NivelMiguel::timerJuego_Tick);
			// 
			// timerMovimiento
			// 
			this->timerMovimiento->Enabled = true;
			this->timerMovimiento->Tick += gcnew System::EventHandler(this, &NivelMiguel::timerMovimiento_Tick);
			// 
			// timerAnimacion
			// 
			this->timerAnimacion->Enabled = true;
			this->timerAnimacion->Tick += gcnew System::EventHandler(this, &NivelMiguel::timerAnimacion_Tick);
			// 
			// NivelMiguel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1655, 1040);
			this->Controls->Add(this->pnlJuego16);
			this->Controls->Add(this->pnlAnimacion);
			this->Controls->Add(this->pnlJuego1);
			this->Controls->Add(this->pnlJuego2);
			this->Controls->Add(this->pnlJuego3);
			this->Controls->Add(this->pnlJuego4);
			this->Controls->Add(this->pnlJuego5);
			this->Controls->Add(this->pnlJuego6);
			this->Controls->Add(this->pnlJuego7);
			this->Controls->Add(this->pnlJuego8);
			this->Controls->Add(this->pnlJuego9);
			this->Controls->Add(this->pnlJuego10);
			this->Controls->Add(this->pnlJuego11);
			this->Controls->Add(this->pnlJuego12);
			this->Controls->Add(this->pnlJuego13);
			this->Controls->Add(this->pnlJuego14);
			this->Controls->Add(this->pnlJuego15);
			this->Controls->Add(this->pnlJuego17);
			this->Controls->Add(this->pnlJuego18);
			this->Controls->Add(this->pnlJuego19);
			this->Controls->Add(this->pnlJuego20);
			this->Controls->Add(this->pnlJuego21);
			this->Controls->Add(this->pnlJuego22);
			this->Controls->Add(this->pnlJuego23);
			this->Controls->Add(this->pnlJuego24);
			this->Controls->Add(this->pnlJuego25);
			this->Controls->Add(this->pnlDeControl);
			this->Controls->Add(this->pnlTexto);
			this->Name = L"NivelMiguel";
			this->Text = L"NivelMiguel";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &NivelMiguel::NivelMiguel_FormClosing);
			this->Load += gcnew System::EventHandler(this, &NivelMiguel::NivelMiguel_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &NivelMiguel::NivelMiguel_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &NivelMiguel::NivelMiguel_KeyUp);
			this->pnlTexto->ResumeLayout(false);
			this->pnlTexto->PerformLayout();
			this->pnlDeControl->ResumeLayout(false);
			this->pnlDeControl->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void NivelMiguel_Load(System::Object^ sender, System::EventArgs^ e) {

		grp = pnlDeControl->CreateGraphics();
		spacep = BufferedGraphicsManager::Current;
		bufferp = spacep->Allocate(grp, pnlDeControl->ClientRectangle);

		gr0 = pnlAnimacion->CreateGraphics();
		space0 = BufferedGraphicsManager::Current;
		buffer0 = space0->Allocate(gr0, pnlAnimacion->ClientRectangle);

		gr1 = pnlJuego1->CreateGraphics();
		space1 = BufferedGraphicsManager::Current;
		buffer1 = space1->Allocate(gr1, pnlJuego1->ClientRectangle);

		gr2 = pnlJuego2->CreateGraphics();
		space2 = BufferedGraphicsManager::Current;
		buffer2 = space2->Allocate(gr2, pnlJuego2->ClientRectangle);

		gr3 = pnlJuego3->CreateGraphics();
		space3 = BufferedGraphicsManager::Current;
		buffer3 = space3->Allocate(gr3, pnlJuego3->ClientRectangle);

		gr4 = pnlJuego4->CreateGraphics();
		space4 = BufferedGraphicsManager::Current;
		buffer4 = space4->Allocate(gr4, pnlJuego4->ClientRectangle);

		gr5 = pnlJuego5->CreateGraphics();
		space5 = BufferedGraphicsManager::Current;
		buffer5 = space5->Allocate(gr5, pnlJuego5->ClientRectangle);

		gr6 = pnlJuego6->CreateGraphics();
		space6 = BufferedGraphicsManager::Current;
		buffer6 = space6->Allocate(gr6, pnlJuego6->ClientRectangle);

		gr7 = pnlJuego7->CreateGraphics();
		space7 = BufferedGraphicsManager::Current;
		buffer7 = space7->Allocate(gr7, pnlJuego7->ClientRectangle);

		gr8 = pnlJuego8->CreateGraphics();
		space8 = BufferedGraphicsManager::Current;
		buffer8 = space8->Allocate(gr8, pnlJuego8->ClientRectangle);

		gr9 = pnlJuego9->CreateGraphics();
		space9 = BufferedGraphicsManager::Current;
		buffer9 = space9->Allocate(gr9, pnlJuego9->ClientRectangle);

		gr10 = pnlJuego10->CreateGraphics();
		space10 = BufferedGraphicsManager::Current;
		buffer10 = space10->Allocate(gr10, pnlJuego10->ClientRectangle);

		gr11 = pnlJuego11->CreateGraphics();
		space11 = BufferedGraphicsManager::Current;
		buffer11 = space11->Allocate(gr11, pnlJuego11->ClientRectangle);

		gr12 = pnlJuego12->CreateGraphics();
		space12 = BufferedGraphicsManager::Current;
		buffer12 = space12->Allocate(gr12, pnlJuego12->ClientRectangle);

		gr13 = pnlJuego13->CreateGraphics();
		space13 = BufferedGraphicsManager::Current;
		buffer13 = space13->Allocate(gr13, pnlJuego13->ClientRectangle);

		gr14 = pnlJuego14->CreateGraphics();
		space14 = BufferedGraphicsManager::Current;
		buffer14 = space14->Allocate(gr14, pnlJuego14->ClientRectangle);

		gr15 = pnlJuego15->CreateGraphics();
		space15 = BufferedGraphicsManager::Current;
		buffer15 = space15->Allocate(gr15, pnlJuego15->ClientRectangle);

		gr16 = pnlJuego16->CreateGraphics();
		space16 = BufferedGraphicsManager::Current;
		buffer16 = space16->Allocate(gr16, pnlJuego16->ClientRectangle);

		gr17 = pnlJuego17->CreateGraphics();
		space17 = BufferedGraphicsManager::Current;
		buffer17 = space17->Allocate(gr17, pnlJuego17->ClientRectangle);

		gr18 = pnlJuego18->CreateGraphics();
		space18 = BufferedGraphicsManager::Current;
		buffer18 = space18->Allocate(gr18, pnlJuego18->ClientRectangle);

		gr19 = pnlJuego19->CreateGraphics();
		space19 = BufferedGraphicsManager::Current;
		buffer19 = space19->Allocate(gr19, pnlJuego19->ClientRectangle);

		gr20 = pnlJuego20->CreateGraphics();
		space20 = BufferedGraphicsManager::Current;
		buffer20 = space20->Allocate(gr20, pnlJuego20->ClientRectangle);

		gr21 = pnlJuego21->CreateGraphics();
		space21 = BufferedGraphicsManager::Current;
		buffer21 = space21->Allocate(gr21, pnlJuego21->ClientRectangle);

		gr22 = pnlJuego22->CreateGraphics();
		space22 = BufferedGraphicsManager::Current;
		buffer22 = space22->Allocate(gr22, pnlJuego22->ClientRectangle);

		gr23 = pnlJuego23->CreateGraphics();
		space23 = BufferedGraphicsManager::Current;
		buffer23 = space23->Allocate(gr23, pnlJuego23->ClientRectangle);

		gr24 = pnlJuego24->CreateGraphics();
		space24 = BufferedGraphicsManager::Current;
		buffer24 = space24->Allocate(gr24, pnlJuego24->ClientRectangle);

		gr25 = pnlJuego25->CreateGraphics();
		space25 = BufferedGraphicsManager::Current;
		buffer25 = space25->Allocate(gr25, pnlJuego25->ClientRectangle);

		bmpMapa1 = gcnew Bitmap("Imagenes/MiguelMapa1.png");
		bmpMapa2 = gcnew Bitmap("Imagenes/MiguelMapa2.png");
		bmpMapa3 = gcnew Bitmap("Imagenes/MiguelMapa3.png");
		bmpMapa4 = gcnew Bitmap("Imagenes/MiguelMapa4.png");
		bmpMiguel = gcnew Bitmap("Imagenes/MiguelOhara.png");
		bmpPanelControl = gcnew Bitmap("Imagenes/PanelControl.png");
		bmpMancha = gcnew Bitmap("Imagenes/ManchaSpot.png");

		miguel = new MiguelOhara(100, 300, 64, 64, 100, 20, 20, 100, 100, 0, "Miguel", 'S', 1, 1);
		IrASala(16, 100, 300);

	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void timerMovimiento_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (miguel == nullptr || buffer1 == nullptr || !timerJuego->Enabled) return;
	if (novela != nullptr && novela->EstaActivo()) { miguel->ProtaQuieto(); return; }

	char dir = ' ';
	if (ultimaDir == 'A' && teclaA) dir = 'A';
	else if (ultimaDir == 'D' && teclaD) dir = 'D';
	else if (ultimaDir == 'W' && teclaW) dir = 'W';
	else if (ultimaDir == 'S' && teclaS) dir = 'S';
	else if (teclaA) dir = 'A';
	else if (teclaD) dir = 'D';
	else if (teclaW) dir = 'W';
	else if (teclaS) dir = 'S';

	if (dir == ' ') {
		miguel->ProtaQuieto();
		return;
	}
	int xAnterior = miguel->GetPX();
	int yAnterior = miguel->GetPY();
	miguel->SetCaminando(true);
	int frame = miguel->GetIdX();
	miguel->move(buffer1->Graphics, dir);
	miguel->SetIdX(frame);

	if (controladora->HayColision(miguel)) {
		miguel->SetPX(xAnterior);
		miguel->SetPY(yAnterior);
	}
	Puerta* puerta = controladora->PuertaColisionando(miguel);
	if (puerta != nullptr) {
		IrASala(puerta->GetNivelDestino(), puerta->GetXDestino(), puerta->GetYDestino());
		return;
		miguel->SetPX(xAnterior);
		miguel->SetPY(yAnterior);
		miguel->ProtaQuieto();
		SoltarTeclas();
		MessageBox::Show("La puerta esta cerrada. Abre los 3 cofres primero.");
	}
}
private: System::Void timerJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
	bufferp->Graphics->DrawImage(bmpPanelControl, 0, 0, pnlDeControl->Width * 1.0, pnlDeControl->Height * 1.0);
	if (!(novela != nullptr && novela->EstaActivo())) bufferp->Render(grp);

	if (pnlJuego1->Visible == true) {
		buffer1->Graphics->DrawImage(bmpMapa2, 0, 0, pnlJuego1->Width * 1.0, pnlJuego1->Height * 1.0);
		miguel->Dibujar(buffer1->Graphics, bmpMiguel);
		controladora->DibujarManchas(buffer1->Graphics, bmpMancha);
		DibujarDebug(buffer1->Graphics, pnlJuego1);
		buffer1->Render(gr1);
	}

	if (pnlJuego2->Visible == true) {
		buffer2->Graphics->DrawImage(bmpMapa2, 0, 0, pnlJuego2->Width * 1.0, pnlJuego2->Height * 1.0);
		miguel->Dibujar(buffer2->Graphics, bmpMiguel);
		DibujarDebug(buffer2->Graphics, pnlJuego2);
		buffer2->Render(gr2);
	}

	if (pnlJuego3->Visible == true) {
		buffer3->Graphics->DrawImage(bmpMapa3, 0, 0, pnlJuego3->Width * 1.0, pnlJuego3->Height * 1.0);
		miguel->Dibujar(buffer3->Graphics, bmpMiguel);
		DibujarDebug(buffer3->Graphics, pnlJuego3);
		buffer3->Render(gr3);
	}

	if (pnlJuego4->Visible == true) {
		buffer4->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego4->Width * 1.0, pnlJuego4->Height * 1.0);
		miguel->Dibujar(buffer4->Graphics, bmpMiguel);
		DibujarDebug(buffer4->Graphics, pnlJuego4);
		buffer4->Render(gr4);
	}

	if (pnlJuego5->Visible == true) {
		buffer5->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego5->Width * 1.0, pnlJuego5->Height * 1.0);
		miguel->Dibujar(buffer5->Graphics, bmpMiguel);
		DibujarDebug(buffer5->Graphics, pnlJuego5);
		buffer5->Render(gr5);
	}

	if (pnlJuego6->Visible == true) {
		buffer6->Graphics->DrawImage(bmpMapa3, 0, 0, pnlJuego6->Width * 1.0, pnlJuego6->Height * 1.0);
		miguel->Dibujar(buffer6->Graphics, bmpMiguel);
		DibujarDebug(buffer6->Graphics, pnlJuego6);
		buffer6->Render(gr6);
	}

	if (pnlJuego7->Visible == true) {
		buffer7->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego7->Width * 1.0, pnlJuego7->Height * 1.0);
		miguel->Dibujar(buffer7->Graphics, bmpMiguel);
		DibujarDebug(buffer7->Graphics, pnlJuego7);
		buffer7->Render(gr7);
	}

	if (pnlJuego8->Visible == true) {
		buffer8->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego8->Width * 1.0, pnlJuego8->Height * 1.0);
		miguel->Dibujar(buffer8->Graphics, bmpMiguel);
		DibujarDebug(buffer8->Graphics, pnlJuego8);
		buffer8->Render(gr8);
	}

	if (pnlJuego9->Visible == true) {
		buffer9->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego9->Width * 1.0, pnlJuego9->Height * 1.0);
		miguel->Dibujar(buffer9->Graphics, bmpMiguel);
		DibujarDebug(buffer9->Graphics, pnlJuego9);
		buffer9->Render(gr9);
	}

	if (pnlJuego10->Visible == true) {
		buffer10->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego10->Width * 1.0, pnlJuego10->Height * 1.0);
		miguel->Dibujar(buffer10->Graphics, bmpMiguel);
		DibujarDebug(buffer10->Graphics, pnlJuego10);
		buffer10->Render(gr10);
	}

	if (pnlJuego11->Visible == true) {
		buffer11->Graphics->DrawImage(bmpMapa2, 0, 0, pnlJuego11->Width * 1.0, pnlJuego11->Height * 1.0);
		miguel->Dibujar(buffer11->Graphics, bmpMiguel);
		DibujarDebug(buffer11->Graphics, pnlJuego11);
		buffer11->Render(gr11);
	}

	if (pnlJuego12->Visible == true) {
		buffer12->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego12->Width * 1.0, pnlJuego12->Height * 1.0);
		miguel->Dibujar(buffer12->Graphics, bmpMiguel);
		DibujarDebug(buffer12->Graphics, pnlJuego12);
		buffer12->Render(gr12);
	}

	if (pnlJuego13->Visible == true) {
		buffer13->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego13->Width * 1.0, pnlJuego13->Height * 1.0);
		miguel->Dibujar(buffer13->Graphics, bmpMiguel);
		DibujarDebug(buffer13->Graphics, pnlJuego13);
		buffer13->Render(gr13);
	}

	if (pnlJuego14->Visible == true) {
		buffer14->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego14->Width * 1.0, pnlJuego14->Height * 1.0);
		miguel->Dibujar(buffer14->Graphics, bmpMiguel);
		DibujarDebug(buffer14->Graphics, pnlJuego14);
		buffer14->Render(gr14);
	}

	if (pnlJuego15->Visible == true) {
		buffer15->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego15->Width * 1.0, pnlJuego15->Height * 1.0);
		miguel->Dibujar(buffer15->Graphics, bmpMiguel);
		DibujarDebug(buffer15->Graphics, pnlJuego15);
		buffer15->Render(gr15);
	}

	if (pnlJuego16->Visible == true) {
		buffer16->Graphics->DrawImage(bmpMapa1, 0, 0, pnlJuego16->Width * 1.0, pnlJuego16->Height * 1.0);
		miguel->Dibujar(buffer16->Graphics, bmpMiguel);
		DibujarDebug(buffer16->Graphics, pnlJuego16);
		buffer16->Render(gr16);
	}

	if (pnlJuego17->Visible == true) {
		buffer17->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego17->Width * 1.0, pnlJuego17->Height * 1.0);
		miguel->Dibujar(buffer17->Graphics, bmpMiguel);
		DibujarDebug(buffer17->Graphics, pnlJuego17);
		buffer17->Render(gr17);
	}

	if (pnlJuego18->Visible == true) {
		buffer18->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego18->Width * 1.0, pnlJuego18->Height * 1.0);
		miguel->Dibujar(buffer18->Graphics, bmpMiguel);
		controladora->DibujarManchas(buffer18->Graphics, bmpMancha);
		DibujarDebug(buffer18->Graphics, pnlJuego18);
		buffer18->Render(gr18);
	}

	if (pnlJuego19->Visible == true) {
		buffer19->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego19->Width * 1.0, pnlJuego19->Height * 1.0);
		miguel->Dibujar(buffer19->Graphics, bmpMiguel);
		DibujarDebug(buffer19->Graphics, pnlJuego19);
		buffer19->Render(gr19);
	}

	if (pnlJuego20->Visible == true) {
		buffer20->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego20->Width * 1.0, pnlJuego20->Height * 1.0);
		miguel->Dibujar(buffer20->Graphics, bmpMiguel);
		DibujarDebug(buffer20->Graphics, pnlJuego20);
		buffer20->Render(gr20);
	}

	if (pnlJuego21->Visible == true) {
		buffer21->Graphics->DrawImage(bmpMapa3, 0, 0, pnlJuego21->Width * 1.0, pnlJuego21->Height * 1.0);
		miguel->Dibujar(buffer21->Graphics, bmpMiguel);
		DibujarDebug(buffer21->Graphics, pnlJuego21);
		buffer21->Render(gr21);
	}

	if (pnlJuego22->Visible == true) {
		buffer22->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego22->Width * 1.0, pnlJuego22->Height * 1.0);
		miguel->Dibujar(buffer22->Graphics, bmpMiguel);
		DibujarDebug(buffer22->Graphics, pnlJuego22);
		buffer22->Render(gr22);
	}

	if (pnlJuego23->Visible == true) {
		buffer23->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego23->Width * 1.0, pnlJuego23->Height * 1.0);
		miguel->Dibujar(buffer23->Graphics, bmpMiguel);
		DibujarDebug(buffer23->Graphics, pnlJuego23);
		buffer23->Render(gr23);
	}

	if (pnlJuego24->Visible == true) {
		buffer24->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego24->Width * 1.0, pnlJuego24->Height * 1.0);
		miguel->Dibujar(buffer24->Graphics, bmpMiguel);
		DibujarDebug(buffer24->Graphics, pnlJuego24);
		buffer24->Render(gr24);
	}

	if (pnlJuego25->Visible == true) {
		buffer25->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego25->Width * 1.0, pnlJuego25->Height * 1.0);
		miguel->Dibujar(buffer25->Graphics, bmpMiguel);
		DibujarDebug(buffer25->Graphics, pnlJuego25);
		buffer25->Render(gr25);
	}

	bufferp->Render(grp);

	lblVida->Text = "Vida: " + miguel->getVida();
	lblPersonaje->Text = "Spider Punk: ";
	lblPuntaje->Text = "Puntaje: " + 10;
	lblLejania->Text = "Lejania a Miles: ";

}
private: System::Void timerAnimacion_Tick(System::Object^ sender, System::EventArgs^ e) {
	miguel->ProtaAnimacion();
}
private: System::Void NivelMiguel_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (novela != nullptr && novela->EstaActivo()) {
		novela->ProcesarTecla(e->KeyCode);
		e->SuppressKeyPress = true;
		return;
	}
	int xAnterior = miguel->GetPX();
	int yAnterior = miguel->GetPY();
	switch (e->KeyCode) {
	case Keys::A: teclaA = true; ultimaDir = 'A'; break;
	case Keys::D: teclaD = true; ultimaDir = 'D'; break;
	case Keys::W: teclaW = true; ultimaDir = 'W'; break;
	case Keys::S: teclaS = true; ultimaDir = 'S'; break;
	case Keys::F:
		if (pnlJuego3->Visible == true) {
			controladora->Disparar(miguel);
		}
		break;
	case Keys::F2:
		modoDebug = !modoDebug;
		break;
	default:break;
	}
	if (controladora->HayColision(miguel)) {
		miguel->SetPX(xAnterior);
		miguel->SetPY(yAnterior);
	}
	Puerta* puerta = controladora->PuertaColisionando(miguel);
	if (puerta != nullptr) {
		IrASala(puerta->GetNivelDestino(), puerta->GetXDestino(), puerta->GetYDestino());
		return;
		MessageBox::Show("La puerta esta cerrada. Abre los 3 cofres primero.");
		miguel->SetPX(xAnterior);
		miguel->SetPY(yAnterior);
		return;
	}
	if (controladora->HayColision(miguel)) {
		miguel->SetPX(xAnterior);
		miguel->SetPY(yAnterior);
	}
}
private: System::Void NivelMiguel_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode) {
	case Keys::A: teclaA = false; break;
	case Keys::D: teclaD = false; break;
	case Keys::W: teclaW = false; break;
	case Keys::S: teclaS = false; break;
	default: break;
	}
}
private: System::Void NivelMiguel_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	timerJuego->Enabled = false;
	if (novela != nullptr) novela->Liberar();
	timerMovimiento->Enabled = false;
}
};
}
