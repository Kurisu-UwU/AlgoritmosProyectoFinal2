#pragma once
#include "MilesMorales.h"
#include "Dialogos.h"
#include "Controladora.h"
namespace AlgoritmosProyectoFinal2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de NivelMiles
	/// </summary>
	public ref class NivelMiles : public System::Windows::Forms::Form
	{
	public:
		NivelMiles(void)
		{
			InitializeComponent();
			controladora = new Controladora();
			this->KeyPreview = true;
			srand((unsigned int)time(nullptr));
		}
		void CargaNivelPersecusion() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarPeny(60, 320, 50, 50);

			controladora->GenerarObstaculo(0, 0, 0, 225, 450);
			controladora->GenerarObstaculo(770, 0, 0, 225, 440);
			controladora->GenerarObstaculo(0, 415, 0, 225, 1210);

			controladora->GenerarPuerta(1200, 0, 60, 840, 2, 60, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
		}
		void CargarNivel1() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarPeny(60, 320, 50, 50);

			controladora->GenerarObstaculo(0, 0, 0, 223, 300);
			controladora->GenerarObstaculo(0, 223, 0, 680-223, 130);
			controladora->GenerarObstaculo(433, 0, 0, 284, 10);
			controladora->GenerarObstaculo(887, 0, 0, 255, 40);
			controladora->GenerarObstaculo(1082, 0, 0, 478, 30);
			controladora->GenerarObstaculo(84, 662, 0, 680-662, 1214-84);
			controladora->GenerarObstaculo(249, 224, 0, 320-224, 304-249);
			controladora->GenerarObstaculo(397,453 , 0, 552-453, 595-397);
			controladora->GenerarObstaculo(473,405 , 0, 465-405, 655-473);
			controladora->GenerarObstaculo(218,455 , 0, 506-455, 320-218);
			controladora->GenerarObstaculo(254,387 , 0,80, 10);
			controladora->GenerarObstaculo(450,250 , 0, 50, 205);
			controladora->GenerarObstaculo(640, 250, 0, 80, 20);
			controladora->GenerarObstaculo(1012, 250, 0,20 , 70);
			controladora->GenerarObstaculo(841,250 , 0, 284-250, 925-841);
			controladora->GenerarObstaculo(841,392 , 0, 478-392, 863-841);
			controladora->GenerarObstaculo(841,284 , 0, 333-284, 863-841);
			controladora->GenerarObstaculo(863,453 , 0, 478-453,1082-863 );
			controladora->GenerarObstaculo(0,0, 0, 20,1220);

			controladora->GenerarPuerta(1114,36,1200-1114,75-36, 3,1100,550);
			controladora->GenerarObstaculo(1200, 0,0, 840, 60);
		}
		void CargarNivel2() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();


			controladora->GenerarObstaculo(0, 0, 0, 20, 1220);
			controladora->GenerarObstaculo(0, 0, 0, 680, 20);
			controladora->GenerarObstaculo(1200, 0, 0, 840, 60);
			controladora->GenerarObstaculo(0, 662, 0, 680 - 662, 1220);

			controladora->GenerarObstaculo(157, 0, 0, 250, 1220-157);
			controladora->GenerarObstaculo(0,420, 0, 680-420, 1016);
			controladora->GenerarObstaculo(1016, 420, 0, 15, 1063-1016);
			controladora->GenerarObstaculo(1142, 420, 0, 15, 1220 - 1142);

			controladora->GenerarPuerta(0, 10, 1200, 20, 4, 1120, 530);
		}
		void CargarNivel3() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarObstaculo(0, 0, 0, 20, 1220);
			controladora->GenerarObstaculo(0, 0, 0, 680, 20);
			controladora->GenerarObstaculo(1200, 0, 0, 840, 60);
			controladora->GenerarObstaculo(0, 662, 0, 680 - 662, 1220);

			controladora->GenerarObstaculo(0, 227, 0, 680-227, 340);
			controladora->GenerarObstaculo(343, 471, 0, 488-471, 736-343);
			controladora->GenerarObstaculo(343, 226, 0, 362-226, 520-343);
			controladora->GenerarObstaculo(500, 133, 0, 235 - 133, 738 - 500);
			controladora->GenerarObstaculo(720,142 , 0,487-142 , 738-720);
			controladora->GenerarObstaculo(340,470 , 0,487-470 ,736-340 );
			controladora->GenerarObstaculo(850,130 , 0, 680-130, 20);
			controladora->GenerarObstaculo(850,220 , 0, 490-220, 1020-850);
			controladora->GenerarObstaculo(1024, 614, 0, 680 - 614, 1220 - 1024);
			controladora->GenerarObstaculo(1120,220 , 0, 20, 100);
			controladora->GenerarObstaculo(1020,414 , 0, 436-414,1096-1020 );
			controladora->GenerarObstaculo(1163,414 , 0,436-414 ,1220-1163 );

			controladora->GenerarPuerta(0, 0, 180  , 680, 5, 1100, 550);
		}
		void CargarNivel4() {
			controladora->LimpiarPuertas();
			controladora->LimpiarObstaculos();
			controladora->LimpiarObjetos();
			controladora->LimpiarPuertas();

			controladora->GenerarPeny(60, 320, 50, 50);

			controladora->GenerarObstaculo(0, 0, 0, 225, 450);
			controladora->GenerarObstaculo(770, 0, 0, 225, 440);
			controladora->GenerarObstaculo(0, 415, 0, 225, 1210);

			controladora->GenerarPuerta(1200, 0, 60, 840, 3, 60, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
		}
		//bool PuedeEntrarSala(int sala) {
		//	return sala != 3;
		//}
		void IrASala(int sala, int px, int py) {
			salaActual = sala;
			pnlPersecusion->Visible = (sala == 1);
			pnlJuego1->Visible = (sala == 2);
			pnlJuego2->Visible = (sala == 3);
			pnlJuego3->Visible = (sala == 4);
			pnlJuego4->Visible = (sala == 5);
			switch (sala) {
			case 1: CargaNivelPersecusion(); break;
			case 2: CargarNivel1(); break;
			case 3: CargarNivel2(); break;
			case 4: CargarNivel3(); break;
			case 5: CargarNivel4(); break;
			}
			miles->SetPX(px);
			miles->SetPY(py);
		}
		void DibujarDebug(Graphics^ g, Panel^ panel) {  // Overley con f2
			if (!modoDebug) return;
			controladora->DibujarPuertas(g);
			controladora->DibujarObstaculos(g);
			Point m = panel->PointToClient(System::Windows::Forms::Cursor::Position);
			System::String^ info = "[F2 ocultar]  Mouse: " + System::Convert::ToString(m.X) + ", " + System::Convert::ToString(m.Y)
				+ "   miles: " + System::Convert::ToString(miles->GetPX()) + ", " + System::Convert::ToString(miles->GetPY());
			g->FillRectangle(Brushes::Black, 0, 0, 430, 20);
			g->DrawString(info, SystemFonts::DefaultFont, Brushes::Lime, 4.0f, 4.0f);
		}
		void PonerInvisibleTodo() {
			pnlPersecusion->Visible = false;
			pnlJuego1->Visible = false;
			pnlJuego2->Visible = false;
			pnlJuego3->Visible = false;
			pnlJuego4->Visible = false;
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~NivelMiles()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
		virtual bool ProcessCmdKey(Message% msg, Keys keyData) override {
			if (novela != nullptr && novela->EstaActivo()) {
				novela->ProcesarTecla(keyData & Keys::KeyCode);
				return true;
			}
			return Form::ProcessCmdKey(msg, keyData);
		}
private: System::Windows::Forms::Timer^ timerJuego;
protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		int salaActual = 2;
		bool modoDebug = false;
		bool teclaA = false, teclaD = false, teclaW = false, teclaS = false;
		char ultimaDir = ' ';

		Graphics^ grperse;
		Graphics^ gr1;
		Graphics^ gr2;
		Graphics^ gr3;
		Graphics^ gr4;
		Graphics^ grp;
		BufferedGraphicsContext^ spaceperse;
		BufferedGraphicsContext^ space1;
		BufferedGraphicsContext^ space2;
		BufferedGraphicsContext^ space3;
		BufferedGraphicsContext^ space4;
		BufferedGraphicsContext^ spacep;
		BufferedGraphics^ bufferperse;
		BufferedGraphics^ buffer1;
		BufferedGraphics^ buffer2;
		BufferedGraphics^ buffer3;
		BufferedGraphics^ buffer4;
		BufferedGraphics^ bufferp;
		Bitmap^ bmpPeny;
		Bitmap^ bmpPanelControl;
		Bitmap^ bmpMapa1;
		Bitmap^ bmpMapa2;
		Bitmap^ bmpMapa3;
		Bitmap^ bmpMapa4;
		Bitmap^ bmpMapaPersecusion;
		Bitmap^ bmpMiles;
		Bitmap^ bmpGwen;
		Bitmap^ bmpMiguel;
		MilesMorales* miles;
		Controladora* controladora;
		NovelaVisual^ novela;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

private: System::Windows::Forms::Timer^ timerAnimacion;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Panel^ pnlTexto;
private: System::Windows::Forms::Panel^ pnlJuego2;
private: System::Windows::Forms::Panel^ pnlDeControl;
private: System::Windows::Forms::Label^ lblSpot;
private: System::Windows::Forms::Label^ lblPuntaje;
private: System::Windows::Forms::Label^ lblVida;
private: System::Windows::Forms::Label^ lblPersonaje;
private: System::Windows::Forms::Panel^ pnlJuego1;
private: System::Windows::Forms::Panel^ pnlJuego3;
private: System::Windows::Forms::Panel^ pnlJuego4;
private: System::Windows::Forms::Panel^ pnlPersecusion;
private: System::Windows::Forms::Button^ btnPersecucion;
private: System::Windows::Forms::Button^ btnNivel4;
private: System::Windows::Forms::Button^ btnNivel3;
private: System::Windows::Forms::Button^ btnNivel2;
private: System::Windows::Forms::Button^ btnNivel1;
private: System::Windows::Forms::Timer^ timerMovimiento;
#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			   this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			   this->timerAnimacion = (gcnew System::Windows::Forms::Timer(this->components));
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->pnlTexto = (gcnew System::Windows::Forms::Panel());
			   this->pnlJuego2 = (gcnew System::Windows::Forms::Panel());
			   this->pnlDeControl = (gcnew System::Windows::Forms::Panel());
			   this->lblSpot = (gcnew System::Windows::Forms::Label());
			   this->lblPuntaje = (gcnew System::Windows::Forms::Label());
			   this->lblVida = (gcnew System::Windows::Forms::Label());
			   this->lblPersonaje = (gcnew System::Windows::Forms::Label());
			   this->pnlJuego1 = (gcnew System::Windows::Forms::Panel());
			   this->pnlJuego3 = (gcnew System::Windows::Forms::Panel());
			   this->btnNivel4 = (gcnew System::Windows::Forms::Button());
			   this->btnNivel3 = (gcnew System::Windows::Forms::Button());
			   this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			   this->btnPersecucion = (gcnew System::Windows::Forms::Button());
			   this->pnlJuego4 = (gcnew System::Windows::Forms::Panel());
			   this->timerMovimiento = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlPersecusion = (gcnew System::Windows::Forms::Panel());
			   this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			   this->pnlTexto->SuspendLayout();
			   this->pnlDeControl->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // timerJuego
			   // 
			   this->timerJuego->Enabled = true;
			   this->timerJuego->Tick += gcnew System::EventHandler(this, &NivelMiles::timerJuego_Tick);
			   // 
			   // timerAnimacion
			   // 
			   this->timerAnimacion->Enabled = true;
			   this->timerAnimacion->Tick += gcnew System::EventHandler(this, &NivelMiles::timerAnimacion_Tick);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::Color::Transparent;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(19, 10);
			   this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(56, 23);
			   this->label4->TabIndex = 0;
			   this->label4->Text = L"label4";
			   // 
			   // pnlTexto
			   // 
			   this->pnlTexto->Controls->Add(this->label4);
			   this->pnlTexto->Location = System::Drawing::Point(11, 11);
			   this->pnlTexto->Margin = System::Windows::Forms::Padding(2);
			   this->pnlTexto->Name = L"pnlTexto";
			   this->pnlTexto->Size = System::Drawing::Size(1215, 89);
			   this->pnlTexto->TabIndex = 5;
			   this->pnlTexto->Visible = false;
			   // 
			   // pnlJuego2
			   // 
			   this->pnlJuego2->Location = System::Drawing::Point(8, 100);
			   this->pnlJuego2->Name = L"pnlJuego2";
			   this->pnlJuego2->Size = System::Drawing::Size(1215, 682);
			   this->pnlJuego2->TabIndex = 6;
			   // 
			   // pnlDeControl
			   // 
			   this->pnlDeControl->Controls->Add(this->lblSpot);
			   this->pnlDeControl->Controls->Add(this->lblPuntaje);
			   this->pnlDeControl->Controls->Add(this->lblVida);
			   this->pnlDeControl->Controls->Add(this->lblPersonaje);
			   this->pnlDeControl->Location = System::Drawing::Point(9, 6);
			   this->pnlDeControl->Margin = System::Windows::Forms::Padding(2);
			   this->pnlDeControl->Name = L"pnlDeControl";
			   this->pnlDeControl->Size = System::Drawing::Size(1215, 89);
			   this->pnlDeControl->TabIndex = 7;
			   // 
			   // lblSpot
			   // 
			   this->lblSpot->AutoSize = true;
			   this->lblSpot->BackColor = System::Drawing::Color::Transparent;
			   this->lblSpot->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblSpot->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->lblSpot->Location = System::Drawing::Point(587, 45);
			   this->lblSpot->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->lblSpot->Name = L"lblSpot";
			   this->lblSpot->Size = System::Drawing::Size(65, 23);
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
			   this->lblPuntaje->Location = System::Drawing::Point(587, 10);
			   this->lblPuntaje->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->lblPuntaje->Name = L"lblPuntaje";
			   this->lblPuntaje->Size = System::Drawing::Size(83, 23);
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
			   this->lblVida->Location = System::Drawing::Point(19, 45);
			   this->lblVida->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->lblVida->Name = L"lblVida";
			   this->lblVida->Size = System::Drawing::Size(62, 23);
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
			   this->lblPersonaje->Location = System::Drawing::Point(19, 10);
			   this->lblPersonaje->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->lblPersonaje->Name = L"lblPersonaje";
			   this->lblPersonaje->Size = System::Drawing::Size(99, 23);
			   this->lblPersonaje->TabIndex = 0;
			   this->lblPersonaje->Text = L"lblPersonaje";
			   this->lblPersonaje->Click += gcnew System::EventHandler(this, &NivelMiles::lblPersonaje_Click);
			   // 
			   // pnlJuego1
			   // 
			   this->pnlJuego1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->pnlJuego1->Location = System::Drawing::Point(8, 100);
			   this->pnlJuego1->Name = L"pnlJuego1";
			   this->pnlJuego1->Size = System::Drawing::Size(1215, 682);
			   this->pnlJuego1->TabIndex = 8;
			   // 
			   // pnlJuego3
			   // 
			   this->pnlJuego3->Location = System::Drawing::Point(8, 100);
			   this->pnlJuego3->Name = L"pnlJuego3";
			   this->pnlJuego3->Size = System::Drawing::Size(1215, 682);
			   this->pnlJuego3->TabIndex = 9;
			   this->pnlJuego3->Visible = false;
			   // 
			   // btnNivel4
			   // 
			   this->btnNivel4->Location = System::Drawing::Point(465, 127);
			   this->btnNivel4->Name = L"btnNivel4";
			   this->btnNivel4->Size = System::Drawing::Size(75, 23);
			   this->btnNivel4->TabIndex = 4;
			   this->btnNivel4->Text = L"Nivel 4";
			   this->btnNivel4->UseVisualStyleBackColor = true;
			   this->btnNivel4->Visible = false;
			   this->btnNivel4->Click += gcnew System::EventHandler(this, &NivelMiles::btnNivel4_Click);
			   // 
			   // btnNivel3
			   // 
			   this->btnNivel3->Location = System::Drawing::Point(366, 127);
			   this->btnNivel3->Name = L"btnNivel3";
			   this->btnNivel3->Size = System::Drawing::Size(75, 23);
			   this->btnNivel3->TabIndex = 3;
			   this->btnNivel3->Text = L"Nivel 3";
			   this->btnNivel3->UseVisualStyleBackColor = true;
			   this->btnNivel3->Visible = false;
			   this->btnNivel3->Click += gcnew System::EventHandler(this, &NivelMiles::btnNivel3_Click);
			   // 
			   // btnNivel2
			   // 
			   this->btnNivel2->Location = System::Drawing::Point(268, 127);
			   this->btnNivel2->Name = L"btnNivel2";
			   this->btnNivel2->Size = System::Drawing::Size(75, 23);
			   this->btnNivel2->TabIndex = 2;
			   this->btnNivel2->Text = L"Nivel 2";
			   this->btnNivel2->UseVisualStyleBackColor = true;
			   this->btnNivel2->Visible = false;
			   this->btnNivel2->Click += gcnew System::EventHandler(this, &NivelMiles::btnNivel2_Click);
			   // 
			   // btnPersecucion
			   // 
			   this->btnPersecucion->Location = System::Drawing::Point(30, 127);
			   this->btnPersecucion->Name = L"btnPersecucion";
			   this->btnPersecucion->Size = System::Drawing::Size(106, 23);
			   this->btnPersecucion->TabIndex = 0;
			   this->btnPersecucion->Text = L"NivelPersecusion";
			   this->btnPersecucion->UseVisualStyleBackColor = true;
			   this->btnPersecucion->Visible = false;
			   this->btnPersecucion->Click += gcnew System::EventHandler(this, &NivelMiles::btnPersecucion_Click);
			   // 
			   // pnlJuego4
			   // 
			   this->pnlJuego4->Location = System::Drawing::Point(8, 100);
			   this->pnlJuego4->Name = L"pnlJuego4";
			   this->pnlJuego4->Size = System::Drawing::Size(1215, 682);
			   this->pnlJuego4->TabIndex = 9;
			   this->pnlJuego4->Visible = false;
			   // 
			   // timerMovimiento
			   // 
			   this->timerMovimiento->Enabled = true;
			   this->timerMovimiento->Interval = 1;
			   this->timerMovimiento->Tick += gcnew System::EventHandler(this, &NivelMiles::timerMovimiento_Tick);
			   // 
			   // pnlPersecusion
			   // 
			   this->pnlPersecusion->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->pnlPersecusion->Location = System::Drawing::Point(8, 100);
			   this->pnlPersecusion->Name = L"pnlPersecusion";
			   this->pnlPersecusion->Size = System::Drawing::Size(1215, 682);
			   this->pnlPersecusion->TabIndex = 11;
			   this->pnlPersecusion->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &NivelMiles::pnlPersecusion_Paint);
			   // 
			   // btnNivel1
			   // 
			   this->btnNivel1->Location = System::Drawing::Point(167, 127);
			   this->btnNivel1->Name = L"btnNivel1";
			   this->btnNivel1->Size = System::Drawing::Size(75, 23);
			   this->btnNivel1->TabIndex = 1;
			   this->btnNivel1->Text = L"Nivel 1";
			   this->btnNivel1->UseVisualStyleBackColor = true;
			   this->btnNivel1->Visible = false;
			   this->btnNivel1->Click += gcnew System::EventHandler(this, &NivelMiles::btnNivel1_Click);
			   // 
			   // NivelMiles
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->ClientSize = System::Drawing::Size(1241, 845);
			   this->Controls->Add(this->btnPersecucion);
			   this->Controls->Add(this->btnNivel4);
			   this->Controls->Add(this->btnNivel3);
			   this->Controls->Add(this->btnNivel2);
			   this->Controls->Add(this->btnNivel1);
			   this->Controls->Add(this->pnlJuego1);
			   this->Controls->Add(this->pnlJuego4);
			   this->Controls->Add(this->pnlPersecusion);
			   this->Controls->Add(this->pnlJuego3);
			   this->Controls->Add(this->pnlDeControl);
			   this->Controls->Add(this->pnlJuego2);
			   this->Controls->Add(this->pnlTexto);
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"NivelMiles";
			   this->Text = L"NivelMiles";
			   this->Deactivate += gcnew System::EventHandler(this, &NivelMiles::NivelMiles_Deactivate);
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &NivelMiles::NivelMiles_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &NivelMiles::NivelMiles_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &NivelMiles::NivelMiles_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &NivelMiles::NivelMiles_KeyUp);
			   this->pnlTexto->ResumeLayout(false);
			   this->pnlTexto->PerformLayout();
			   this->pnlDeControl->ResumeLayout(false);
			   this->pnlDeControl->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void NivelMiles_Load(System::Object^ sender, System::EventArgs^ e) {
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

		gr4 = pnlJuego4->CreateGraphics();
		space4 = BufferedGraphicsManager::Current;
		buffer4 = space4->Allocate(gr4, pnlJuego4->ClientRectangle);

		bmpPanelControl = gcnew Bitmap("Imagenes/PanelControl.png");
		bmpMapaPersecusion = gcnew Bitmap("Imagenes/MilesMapa1.png");
		bmpMapa1 = gcnew Bitmap("Imagenes/MilesMapa2.png");
		bmpMapa2 = gcnew Bitmap("Imagenes/MilesMapa3.png");
		bmpMapa3 = gcnew Bitmap("Imagenes/MilesMapa4.png");
		bmpMapa4 = gcnew Bitmap("Imagenes/MilesMapa5.png");
		bmpGwen = gcnew Bitmap("Imagenes/Gwen.png");
		bmpMiles = gcnew Bitmap("Imagenes/MilesMorales.png");
		bmpPeny = gcnew Bitmap("Imagenes/PenyParker.png");

		miles = new MilesMorales(350, 50, bmpMiles->Width / 16, bmpMiles->Height / 8, 100, 4, 4, 100, 100, 0, "Miles", 'S', 1, 1);
		novela = gcnew NovelaVisual(pnlTexto);
		IrASala(2, 350, 50);
		novela->Iniciar(1);
	}
	private: System::Void timerJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		bufferp->Graphics->DrawImage(bmpPanelControl, 0, 0, pnlDeControl->Width * 1.0, pnlDeControl->Height * 1.0);
		if (!(novela != nullptr && novela->EstaActivo())) bufferp->Render(grp);

		if (pnlPersecusion->Visible == true) {
			bufferperse->Graphics->DrawImage(bmpMapaPersecusion, 0, 0, pnlPersecusion->Width * 1.0, pnlPersecusion->Height * 1.0);
			miles->Dibujar(bufferperse->Graphics, bmpMiles);
			DibujarDebug(bufferperse->Graphics, pnlPersecusion);
			bufferperse->Render(grperse);
}
		if (pnlJuego1->Visible == true) {
			buffer1->Graphics->DrawImage(bmpMapa1, 0, 0, pnlJuego1->Width * 1.0, pnlJuego1->Height * 1.0);
			miles->Dibujar(buffer1->Graphics, bmpMiles);
			DibujarDebug(buffer1->Graphics, pnlJuego1);
			buffer1->Render(gr1);
		}
		if (pnlJuego2->Visible == true) {
			buffer2->Graphics->DrawImage(bmpMapa2, 0, 0, pnlJuego2->Width * 1.0, pnlJuego2->Height * 1.0);
			miles->Dibujar(buffer2->Graphics, bmpMiles);
			DibujarDebug(buffer2->Graphics, pnlJuego2);
			buffer2->Render(gr2);
		}
		if (pnlJuego3->Visible == true) {
			buffer3->Graphics->DrawImage(bmpMapa3, 0, 0, pnlJuego3->Width * 1.0, pnlJuego3->Height * 1.0);
			if (!novela->EstaActivo()) {
				//controladora->ActualizarJefes(miles, pnlJuego3->Width, pnlJuego3->Height);
				//controladora->ActualizarProyectiles(pnlJuego3->Width, pnlJuego3->Height);
				//controladora->ActualizarProyectilesHorizontales(miles, pnlJuego3->Width);
			}
			//controladora->DibujarProyectilesHorizontales(buffer3->Graphics, bmpProyectilMalo);
			//controladora->DibujarProyectiles(buffer3->Graphics, bmpNota1);
			//controladora->DibujarJefe(buffer3->Graphics, bmpSpot);
			//controladora->ComprobarColisionJefe(miles);
			miles->Dibujar(buffer3->Graphics, bmpMiles);
			DibujarDebug(buffer3->Graphics, pnlJuego3);
			buffer3->Render(gr3);
			//if (ComprobarFinCombate()) return;
		}
		if (pnlJuego4->Visible == true) {
			buffer4->Graphics->DrawImage(bmpMapa4, 0, 0, pnlJuego4->Width * 1.0, pnlJuego4->Height * 1.0);
			miles->Dibujar(buffer4->Graphics, bmpMiles);
			DibujarDebug(buffer4->Graphics, pnlJuego4);
			buffer4->Render(gr4);
		}
		bufferp->Render(grp);

		lblVida->Text = "Vida: " + miles->getVida();
		lblPersonaje->Text = "Spider miles: ";
		lblPuntaje->Text = "Puntaje: " + 10;

	}
	private: System::Void timerMovimiento_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (miles == nullptr || buffer1 == nullptr || !timerJuego->Enabled) return;
		if (novela != nullptr && novela->EstaActivo()) { miles->ProtaQuieto(); return; }

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
			miles->ProtaQuieto();
			return;
		}
		int xAnterior = miles->GetPX();
		int yAnterior = miles->GetPY();
		miles->SetCaminando(true);
		int frame = miles->GetIdX();
		miles->move(buffer1->Graphics, dir);
		miles->SetIdX(frame);

		if (controladora->HayColision(miles)) {
			miles->SetPX(xAnterior);
			miles->SetPY(yAnterior);
		}
		Puerta* puerta = controladora->PuertaColisionando(miles);
		if (puerta != nullptr) {
			IrASala(puerta->GetNivelDestino(), puerta->GetXDestino(), puerta->GetYDestino());
		}
	}
private: System::Void NivelMiles_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	timerJuego->Enabled = false;
	if (novela != nullptr) novela->Liberar();
	timerMovimiento->Enabled = false;
}
		private: void SoltarTeclas() {
			teclaA = false; teclaD = false; teclaW = false; teclaS = false;
		}
private: System::Void NivelMiles_Deactivate(System::Object^ sender, System::EventArgs^ e) {
	SoltarTeclas();
}
private: System::Void NivelMiles_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode) {
	case Keys::A: teclaA = false; break;
	case Keys::D: teclaD = false; break;
	case Keys::W: teclaW = false; break;
	case Keys::S: teclaS = false; break;
	default: break;
	}
}	
private: System::Void NivelMiles_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (novela != nullptr && novela->EstaActivo()) {
			novela->ProcesarTecla(e->KeyCode);
			e->SuppressKeyPress = true;
			return;
		}
		int xAnterior = miles->GetPX();
		int yAnterior = miles->GetPY();
		switch (e->KeyCode) {
		case Keys::A: teclaA = true; ultimaDir = 'A'; break;
		case Keys::D: teclaD = true; ultimaDir = 'D'; break;
		case Keys::W: teclaW = true; ultimaDir = 'W'; break;
		case Keys::S: teclaS = true; ultimaDir = 'S'; break;
		case Keys::F:
			if (pnlJuego3->Visible == true) {
				controladora->Disparar(miles);
			}
			break;
		case Keys::E: {
			Cofre* cofre = controladora->CofreColisionando(miles);
			if (cofre != nullptr && !cofre->GetAbierto()) {
				//if (JugarRitmo(1)) {
				//	cofre->SetAbierto(true);
				//	MarcarCofre(cofre->GetId());
				//}
			}
			break;
		}
		case Keys::F2:
			modoDebug = !modoDebug;
			btnPersecucion->Visible = modoDebug;
			btnNivel1->Visible = modoDebug;
			btnNivel2->Visible = modoDebug;
			btnNivel3->Visible = modoDebug;
			btnNivel4->Visible = modoDebug;
			break;
		default:break;
		}
		if (controladora->HayColision(miles)) {
			miles->SetPX(xAnterior);
			miles->SetPY(yAnterior);
		}
		Puerta* puerta = controladora->PuertaColisionando(miles);
		if (puerta != nullptr) {
			IrASala(puerta->GetNivelDestino(), puerta->GetXDestino(), puerta->GetYDestino());
			return;
		}
		if (controladora->HayColision(miles)) {
			miles->SetPX(xAnterior);
			miles->SetPY(yAnterior);
		}
	}
	private: System::Void timerAnimacion_Tick(System::Object^ sender, System::EventArgs^ e) {
		miles->ProtaAnimacion();
	}
private: System::Void lblPersonaje_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pnlPersecusion_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void btnPersecucion_Click(System::Object^ sender, System::EventArgs^ e) {
	if (modoDebug) {
		PonerInvisibleTodo();
		pnlPersecusion->Visible = true;
		CargaNivelPersecusion();
	}
}
private: System::Void btnNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (modoDebug) {
		PonerInvisibleTodo();
		pnlJuego1->Visible = true;
		CargarNivel1();
	}
}
private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (modoDebug) {
		PonerInvisibleTodo();
		pnlJuego2->Visible = true;
		CargarNivel2();
	}
}
private: System::Void btnNivel3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (modoDebug) {
		PonerInvisibleTodo();
		pnlJuego3->Visible = true;
		CargarNivel3();
	}
}
private: System::Void btnNivel4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (modoDebug) {
		PonerInvisibleTodo();
		pnlJuego4->Visible = true;
		CargarNivel4();
	}
}
};
}