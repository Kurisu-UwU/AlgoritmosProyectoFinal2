#pragma once
#include "SpiderPunk.h"
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
			//
			//TODO: agregar código de constructor aquí
			//
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

			controladora->GenerarObstaculo(0, 0, 0, 285, 435);
			controladora->GenerarObstaculo(790, 0, 0, 285, 445);
			controladora->GenerarObstaculo(1080, 460, 0, 225, 130);
			controladora->GenerarObstaculo(792, 460, 0, 225, 215);
			controladora->GenerarObstaculo(0, 468, 0, 285, 435);

			controladora->GenerarPuerta(0, 285, 40, 183, 1, 1100, 300);
			controladora->GenerarPuerta(1200, 0, 60, 840, 3, 60, 650);
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
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


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
private: System::Windows::Forms::Label^ lblPersonaje;
private: System::Windows::Forms::Label^ lblVida;
private: System::Windows::Forms::Label^ lblPuntaje;
private: System::Windows::Forms::Label^ lblLejania;
private: System::Windows::Forms::Timer^ timerJuego;
private: System::Windows::Forms::Timer^ timerMovimiento;
private: System::Windows::Forms::Timer^ timerAnimacion;






	   Bitmap^ bmpMapa4;



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
			this->lblPersonaje = (gcnew System::Windows::Forms::Label());
			this->lblLejania = (gcnew System::Windows::Forms::Label());
			this->lblPuntaje = (gcnew System::Windows::Forms::Label());
			this->lblVida = (gcnew System::Windows::Forms::Label());
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
			// pnlJuego25
			// 
			this->pnlJuego25->Location = System::Drawing::Point(16, 121);
			this->pnlJuego25->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego25->Name = L"pnlJuego25";
			this->pnlJuego25->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego25->TabIndex = 5;
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
			this->pnlJuego16->Visible = false;
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
			// 
			// pnlJuego11
			// 
			this->pnlJuego11->Location = System::Drawing::Point(16, 121);
			this->pnlJuego11->Margin = System::Windows::Forms::Padding(4);
			this->pnlJuego11->Name = L"pnlJuego11";
			this->pnlJuego11->Size = System::Drawing::Size(1620, 839);
			this->pnlJuego11->TabIndex = 19;
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
			// NivelMiguel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1655, 1040);
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
			this->Controls->Add(this->pnlJuego16);
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
			this->Load += gcnew System::EventHandler(this, &NivelMiguel::NivelMiguel_Load);
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

	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
