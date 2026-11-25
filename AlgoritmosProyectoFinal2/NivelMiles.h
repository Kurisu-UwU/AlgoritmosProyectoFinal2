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

			controladora->GenerarObstaculo(0, 0, 0, 225, 450);
			controladora->GenerarObstaculo(770, 0, 0, 225, 440);
			controladora->GenerarObstaculo(0, 415, 0, 225, 1210);

			controladora->GenerarPuerta(1200, 0, 60, 840, 2, 60, 340);   // (x, y, ancho, alto, salaDestino, xLlegada, yLlegada)
		}
		void CargarNivel2() {
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
		void CargarNivel3() {
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
		void CargarNivel4() {
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
		bool PuedeEntrarSala(int sala) {
			return sala != 3;
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
		int salaActual = 1;
		bool modoDebug = false;
		bool teclaA = false, teclaD = false, teclaW = false, teclaS = false;
		char ultimaDir = ' ';

		Graphics^ gr1;
		Graphics^ gr2;
		Graphics^ gr3;
		Graphics^ gr4;
		Graphics^ grp;
		BufferedGraphicsContext^ space1;
		BufferedGraphicsContext^ space2;
		BufferedGraphicsContext^ space3;
		BufferedGraphicsContext^ space4;
		BufferedGraphicsContext^ spacep;
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
private: System::Windows::Forms::Panel^ pnlDebug;
private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::Panel^ pnlJuego4;
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
			   this->pnlDebug = (gcnew System::Windows::Forms::Panel());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->pnlJuego4 = (gcnew System::Windows::Forms::Panel());
			   this->timerMovimiento = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlTexto->SuspendLayout();
			   this->pnlDeControl->SuspendLayout();
			   this->pnlDebug->SuspendLayout();
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
			   this->label4->Location = System::Drawing::Point(25, 12);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(67, 28);
			   this->label4->TabIndex = 0;
			   this->label4->Text = L"label4";
			   // 
			   // pnlTexto
			   // 
			   this->pnlTexto->Controls->Add(this->label4);
			   this->pnlTexto->Location = System::Drawing::Point(15, 14);
			   this->pnlTexto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->pnlTexto->Name = L"pnlTexto";
			   this->pnlTexto->Size = System::Drawing::Size(1620, 110);
			   this->pnlTexto->TabIndex = 5;
			   this->pnlTexto->Visible = false;
			   // 
			   // pnlJuego2
			   // 
			   this->pnlJuego2->Location = System::Drawing::Point(17, 100);
			   this->pnlJuego2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pnlJuego2->Name = L"pnlJuego2";
			   this->pnlJuego2->Size = System::Drawing::Size(1620, 839);
			   this->pnlJuego2->TabIndex = 6;
			   // 
			   // pnlDeControl
			   // 
			   this->pnlDeControl->Controls->Add(this->lblSpot);
			   this->pnlDeControl->Controls->Add(this->lblPuntaje);
			   this->pnlDeControl->Controls->Add(this->lblVida);
			   this->pnlDeControl->Controls->Add(this->lblPersonaje);
			   this->pnlDeControl->Location = System::Drawing::Point(12, 7);
			   this->pnlDeControl->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->pnlDeControl->Name = L"pnlDeControl";
			   this->pnlDeControl->Size = System::Drawing::Size(1620, 110);
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
			   this->pnlJuego1->Location = System::Drawing::Point(11, 123);
			   this->pnlJuego1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pnlJuego1->Name = L"pnlJuego1";
			   this->pnlJuego1->Size = System::Drawing::Size(1620, 839);
			   this->pnlJuego1->TabIndex = 8;
			   // 
			   // pnlJuego3
			   // 
			   this->pnlJuego3->Location = System::Drawing::Point(13, 123);
			   this->pnlJuego3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pnlJuego3->Name = L"pnlJuego3";
			   this->pnlJuego3->Size = System::Drawing::Size(1620, 839);
			   this->pnlJuego3->TabIndex = 9;
			   this->pnlJuego3->Visible = false;
			   // 
			   // pnlDebug
			   // 
			   this->pnlDebug->Controls->Add(this->button5);
			   this->pnlDebug->Controls->Add(this->button6);
			   this->pnlDebug->Controls->Add(this->button8);
			   this->pnlDebug->Location = System::Drawing::Point(9, 119);
			   this->pnlDebug->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pnlDebug->Name = L"pnlDebug";
			   this->pnlDebug->Size = System::Drawing::Size(1620, 839);
			   this->pnlDebug->TabIndex = 10;
			   // 
			   // button5
			   // 
			   this->button5->Location = System::Drawing::Point(460, 25);
			   this->button5->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(100, 28);
			   this->button5->TabIndex = 8;
			   this->button5->Text = L"miles 1";
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Visible = false;
			   // 
			   // button6
			   // 
			   this->button6->Location = System::Drawing::Point(172, 25);
			   this->button6->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(100, 28);
			   this->button6->TabIndex = 10;
			   this->button6->Text = L"miles 3";
			   this->button6->UseVisualStyleBackColor = true;
			   this->button6->Visible = false;
			   // 
			   // button8
			   // 
			   this->button8->Location = System::Drawing::Point(28, 25);
			   this->button8->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(100, 28);
			   this->button8->TabIndex = 11;
			   this->button8->Text = L"miles m";
			   this->button8->UseVisualStyleBackColor = true;
			   this->button8->Visible = false;
			   // 
			   // pnlJuego4
			   // 
			   this->pnlJuego4->Location = System::Drawing::Point(9, 116);
			   this->pnlJuego4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pnlJuego4->Name = L"pnlJuego4";
			   this->pnlJuego4->Size = System::Drawing::Size(1620, 839);
			   this->pnlJuego4->TabIndex = 9;
			   this->pnlJuego4->Visible = false;
			   // 
			   // timerMovimiento
			   // 
			   this->timerMovimiento->Tick += gcnew System::EventHandler(this, &NivelMiles::timerMovimiento_Tick);
			   // 
			   // NivelMiles
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1655, 1040);
			   this->Controls->Add(this->pnlJuego1);
			   this->Controls->Add(this->pnlJuego4);
			   this->Controls->Add(this->pnlDebug);
			   this->Controls->Add(this->pnlJuego3);
			   this->Controls->Add(this->pnlDeControl);
			   this->Controls->Add(this->pnlJuego2);
			   this->Controls->Add(this->pnlTexto);
			   this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			   this->pnlDebug->ResumeLayout(false);
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

		miles = new MilesMorales(100, 100, bmpMiles->Width / 16, bmpMiles->Height / 8, 100, 2, 2, 100, 100, 0, "miles", 'S', 0, 0);
		novela = gcnew NovelaVisual(pnlTexto);
		IrASala(1, 100, 300);
		novela->Iniciar(1);
	}
	private: System::Void timerJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		bufferp->Graphics->DrawImage(bmpPanelControl, 0, 0, pnlDeControl->Width * 1.0, pnlDeControl->Height * 1.0);
		if (!(novela != nullptr && novela->EstaActivo())) bufferp->Render(grp);

		if (pnlJuego1->Visible == true) {
			buffer1->Graphics->DrawImage(bmpMapa1, 0, 0, pnlJuego1->Width * 1.0, pnlJuego1->Height * 1.0);
			controladora->DibujarPeny(buffer1->Graphics, bmpPeny);
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
		bufferp->Render(grp);

		lblVida->Text = "Vida: " + miles->getVida();
		lblPersonaje->Text = "Spider miles: ";
		lblPuntaje->Text = "Puntaje: " + 10;

		if (pnlJuego3->Visible == true) {
			lblSpot->Text = "Vida de Spot: " + controladora->getJefe()->getVida();
		}
		else {
			lblSpot->Text = " ";
		}
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
			if (PuedeEntrarSala(puerta->GetNivelDestino())) {
				IrASala(puerta->GetNivelDestino(), puerta->GetXDestino(), puerta->GetYDestino());
				return;
			}
			miles->SetPX(xAnterior);
			miles->SetPY(yAnterior);
			miles->ProtaQuieto();
			SoltarTeclas();
			MessageBox::Show("La puerta esta cerrada. Abre los 3 cofres primero.");
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
			button5->Visible = modoDebug;
			button6->Visible = modoDebug;
			button8->Visible = modoDebug;
			break;
		default:break;
		}
		if (controladora->HayColision(miles)) {
			miles->SetPX(xAnterior);
			miles->SetPY(yAnterior);
		}
		Puerta* puerta = controladora->PuertaColisionando(miles);
		if (puerta != nullptr) {
			if (PuedeEntrarSala(puerta->GetNivelDestino())) {
				IrASala(puerta->GetNivelDestino(), puerta->GetXDestino(), puerta->GetYDestino());
				return;
			}
			MessageBox::Show("La puerta esta cerrada. Abre los 3 cofres primero.");
			miles->SetPX(xAnterior);
			miles->SetPY(yAnterior);
			return;
		}
		if (controladora->HayColision(miles)) {
			miles->SetPX(xAnterior);
			miles->SetPY(yAnterior);
		}
	}
		private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
			if (modoDebug) {
				pnlJuego2->Visible = false;
				//pnlJuegoMusical->Visible = true;
				//CargarNivelMusical(1);
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
	private: System::Void timerAnimacion_Tick(System::Object^ sender, System::EventArgs^ e) {
		miles->ProtaAnimacion();
	}
};
}