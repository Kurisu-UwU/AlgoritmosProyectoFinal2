#pragma once
#include "NivelPunk.h"
#include "NivelMiguel.h"
#include "NivelMiles.h"

namespace AlgoritmosProyectoFinal2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PantallaPrincipal
	/// </summary>
	public ref class PantallaPrincipal : public System::Windows::Forms::Form
	{
	public:
		PantallaPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PantallaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timerPantalla;
	private: System::Windows::Forms::Panel^ pnlPrincipal;

	private: System::Windows::Forms::Button^ btnJugar;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnOpciones;
	private: System::Windows::Forms::Panel^ pnlPersonaje;
	private: System::Windows::Forms::Button^ btnMiles;
	private: System::Windows::Forms::Button^ btnAtras;




	private: System::Windows::Forms::Button^ btnMiguel;
	private: System::Windows::Forms::Button^ btnPunk;


	protected:




	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		Bitmap^ bmpInicio;
		Bitmap^ bmpPersonaje;


		Graphics^ gr;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Graphics^ grp;
		BufferedGraphicsContext^ spacep;
		BufferedGraphics^ bufferp;
	private: System::Windows::Forms::Label^ label1;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timerPantalla = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlPrincipal = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnOpciones = (gcnew System::Windows::Forms::Button());
			this->pnlPersonaje = (gcnew System::Windows::Forms::Panel());
			this->btnMiles = (gcnew System::Windows::Forms::Button());
			this->btnAtras = (gcnew System::Windows::Forms::Button());
			this->btnMiguel = (gcnew System::Windows::Forms::Button());
			this->btnPunk = (gcnew System::Windows::Forms::Button());
			this->pnlPrincipal->SuspendLayout();
			this->pnlPersonaje->SuspendLayout();
			this->SuspendLayout();
			// 
			// timerPantalla
			// 
			this->timerPantalla->Enabled = true;
			this->timerPantalla->Tick += gcnew System::EventHandler(this, &PantallaPrincipal::timerPantalla_Tick);
			// 
			// pnlPrincipal
			// 
			this->pnlPrincipal->Controls->Add(this->label1);
			this->pnlPrincipal->Controls->Add(this->btnJugar);
			this->pnlPrincipal->Controls->Add(this->btnSalir);
			this->pnlPrincipal->Controls->Add(this->btnCreditos);
			this->pnlPrincipal->Controls->Add(this->btnOpciones);
			this->pnlPrincipal->Cursor = System::Windows::Forms::Cursors::Default;
			this->pnlPrincipal->Location = System::Drawing::Point(13, 14);
			this->pnlPrincipal->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pnlPrincipal->Name = L"pnlPrincipal";
			this->pnlPrincipal->Size = System::Drawing::Size(1405, 484);
			this->pnlPrincipal->TabIndex = 4;
			this->pnlPrincipal->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaPrincipal::pnlPrincipal_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(24, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(456, 65);
			this->label1->TabIndex = 4;
			this->label1->Text = L"SPIDER JOURNEY";
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::SystemColors::HotTrack;
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(1053, 34);
			this->btnJugar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(268, 62);
			this->btnJugar->TabIndex = 0;
			this->btnJugar->Text = L"JUGAR";
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &PantallaPrincipal::btnJugar_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::SystemColors::HotTrack;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(1053, 305);
			this->btnSalir->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(268, 62);
			this->btnSalir->TabIndex = 3;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = false;
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::SystemColors::HotTrack;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(1053, 126);
			this->btnCreditos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(268, 62);
			this->btnCreditos->TabIndex = 1;
			this->btnCreditos->Text = L"CRÉDITOS";
			this->btnCreditos->UseVisualStyleBackColor = false;
			// 
			// btnOpciones
			// 
			this->btnOpciones->BackColor = System::Drawing::SystemColors::HotTrack;
			this->btnOpciones->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpciones->Location = System::Drawing::Point(1053, 215);
			this->btnOpciones->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnOpciones->Name = L"btnOpciones";
			this->btnOpciones->Size = System::Drawing::Size(268, 62);
			this->btnOpciones->TabIndex = 2;
			this->btnOpciones->Text = L"OPCIONES";
			this->btnOpciones->UseVisualStyleBackColor = false;
			// 
			// pnlPersonaje
			// 
			this->pnlPersonaje->Controls->Add(this->btnMiles);
			this->pnlPersonaje->Controls->Add(this->btnAtras);
			this->pnlPersonaje->Controls->Add(this->btnMiguel);
			this->pnlPersonaje->Controls->Add(this->btnPunk);
			this->pnlPersonaje->Location = System::Drawing::Point(13, 12);
			this->pnlPersonaje->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pnlPersonaje->Name = L"pnlPersonaje";
			this->pnlPersonaje->Size = System::Drawing::Size(1405, 488);
			this->pnlPersonaje->TabIndex = 5;
			this->pnlPersonaje->Visible = false;
			this->pnlPersonaje->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaPrincipal::pnlPersonaje_Paint);
			// 
			// btnMiles
			// 
			this->btnMiles->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMiles->Location = System::Drawing::Point(100, 300);
			this->btnMiles->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMiles->Name = L"btnMiles";
			this->btnMiles->Size = System::Drawing::Size(268, 62);
			this->btnMiles->TabIndex = 0;
			this->btnMiles->Text = L"MILES MORALES";
			this->btnMiles->UseVisualStyleBackColor = true;
			this->btnMiles->Click += gcnew System::EventHandler(this, &PantallaPrincipal::btnMiles_Click);
			// 
			// btnAtras
			// 
			this->btnAtras->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAtras->Location = System::Drawing::Point(1200, 300);
			this->btnAtras->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAtras->Name = L"btnAtras";
			this->btnAtras->Size = System::Drawing::Size(167, 62);
			this->btnAtras->TabIndex = 3;
			this->btnAtras->Text = L"ATRÁS";
			this->btnAtras->UseVisualStyleBackColor = true;
			this->btnAtras->Click += gcnew System::EventHandler(this, &PantallaPrincipal::btnAtras_Click);
			// 
			// btnMiguel
			// 
			this->btnMiguel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMiguel->Location = System::Drawing::Point(451, 300);
			this->btnMiguel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMiguel->Name = L"btnMiguel";
			this->btnMiguel->Size = System::Drawing::Size(268, 62);
			this->btnMiguel->TabIndex = 1;
			this->btnMiguel->Text = L"MIGUEL O\'HARA";
			this->btnMiguel->UseVisualStyleBackColor = true;
			this->btnMiguel->Click += gcnew System::EventHandler(this, &PantallaPrincipal::btnMiguel_Click);
			// 
			// btnPunk
			// 
			this->btnPunk->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPunk->Location = System::Drawing::Point(800, 300);
			this->btnPunk->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnPunk->Name = L"btnPunk";
			this->btnPunk->Size = System::Drawing::Size(268, 62);
			this->btnPunk->TabIndex = 2;
			this->btnPunk->Text = L"SPIDER PUNK";
			this->btnPunk->UseVisualStyleBackColor = true;
			this->btnPunk->Click += gcnew System::EventHandler(this, &PantallaPrincipal::btnPunk_Click);
			// 
			// PantallaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1441, 511);
			this->Controls->Add(this->pnlPersonaje);
			this->Controls->Add(this->pnlPrincipal);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"PantallaPrincipal";
			this->Text = L"PantallaPrincipal";
			this->Load += gcnew System::EventHandler(this, &PantallaPrincipal::PantallaPrincipal_Load);
			this->pnlPrincipal->ResumeLayout(false);
			this->pnlPrincipal->PerformLayout();
			this->pnlPersonaje->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void PantallaPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {

		gr = pnlPrincipal->CreateGraphics();
		space = BufferedGraphicsManager::Current;
		buffer = space->Allocate(gr, pnlPrincipal->ClientRectangle);

		bmpInicio = gcnew Bitmap("Imagenes/PantallaMenu.png");

		grp = pnlPersonaje->CreateGraphics();
		spacep = BufferedGraphicsManager::Current;
		bufferp = spacep->Allocate(grp, pnlPersonaje->ClientRectangle);

		bmpPersonaje = gcnew Bitmap("Imagenes/PantallaPersonajes.png");
	}
	private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlPrincipal->Visible = false;
		pnlPersonaje->Visible = true;
	}
	private: System::Void btnAtras_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlPrincipal->Visible = true;
		pnlPersonaje->Visible = false;
	}
	private: System::Void btnPunk_Click(System::Object^ sender, System::EventArgs^ e) {
		NivelPunk^ frm = gcnew NivelPunk();
		frm->ShowDialog();
	}
	private: System::Void btnMiles_Click(System::Object^ sender, System::EventArgs^ e) {
		NivelMiles^ frm = gcnew NivelMiles();
		frm->ShowDialog();
	}
	private: System::Void btnMiguel_Click(System::Object^ sender, System::EventArgs^ e) {
		NivelMiguel^ frm = gcnew NivelMiguel();
		frm->ShowDialog();
	}
	private: System::Void pnlPrincipal_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}
private: System::Void timerPantalla_Tick(System::Object^ sender, System::EventArgs^ e) {
	buffer->Graphics->DrawImage(bmpInicio, 0, 0, pnlPrincipal->Width * 1.0, pnlPrincipal->Height * 1.0);

	buffer->Render(gr);


	bufferp->Graphics->DrawImage(bmpPersonaje, 0, 0, pnlPersonaje->Width * 1.0, pnlPersonaje->Height * 1.0);

	bufferp->Render(grp);
}
private: System::Void pnlPersonaje_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

};
}
