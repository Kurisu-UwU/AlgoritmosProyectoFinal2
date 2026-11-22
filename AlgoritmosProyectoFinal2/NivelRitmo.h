#pragma once
#include "ControladoraNivelRitmo.h"
#include "VariablesGlobales.h"
#include "NivelesRitmo.h"
#include "SpiderPunk.h"
namespace AlgoritmosProyectoFinal2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class NivelRitmo : public System::Windows::Forms::Form
	{
	public:
		NivelRitmo(int n, SpiderPunk* punkquiero)
		{
			InitializeComponent();
			nivel = n;
			bmpNota1 = gcnew Bitmap("Imagenes/NotasMusicales1.png");
			bmpNota2 = gcnew Bitmap("Imagenes/NotasMusicales2.png");
			bmpNota3 = gcnew Bitmap("Imagenes/NotasMusicales3.png");
			bmpPunk = gcnew Bitmap("Imagenes/SpiderPunk.png");
			bmpMapaMusical = gcnew Bitmap("Imagenes/PunkMapaMusical.png");
			controladora = new ControladoraNivelRitmo();
			punk = punkquiero;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NivelRitmo()
		{
			if (components)
			{
				if (timer1 != nullptr) timer1->Stop();
				if (controladora) { delete controladora; controladora = nullptr; }
				if (buffer != nullptr) { delete buffer; buffer = nullptr; }
				if (gr != nullptr) {
					delete gr; gr = nullptr;
				}
				if (components) { delete components; }
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		Graphics^ gr;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpMapaMusical;
		Bitmap^ bmpPunk;
		Bitmap^ bmpNota1;
		Bitmap^ bmpNota2;
		Bitmap^ bmpNota3;
		ControladoraNivelRitmo* controladora;
		SpiderPunk* punk;
		int tiempo = 0;
		int puntuaciontotal = 0;
		char tecla = 'f';
	private:
		System::Windows::Forms::Timer^ timer1;
		int nivel;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &NivelRitmo::timer1_Tick);
			// 
			// NivelRitmo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(974, 575);
			this->Name = L"NivelRitmo";
			this->Text = L"NivelRitmo";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &NivelRitmo::NivelRitmo_FormClosing);
			this->Load += gcnew System::EventHandler(this, &NivelRitmo::NivelRitmo_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &NivelRitmo::NivelRitmo_KeyDown);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void NivelRitmo_Load(System::Object^ sender, System::EventArgs^ e) {
		gr = this->CreateGraphics();
		space = BufferedGraphicsManager::Current;
		buffer = space->Allocate(gr, this->ClientRectangle);
		timer1->Interval = 1;
		timer1->Start();
		punk->SetPX(150);
		punk->SetPY(350);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (this->IsDisposed || !this->Visible || buffer == nullptr || gr == nullptr || !controladora) return;
		buffer->Graphics->DrawImage(bmpMapaMusical, 0, 0, this->Width, this->Height);
		switch (nivel) {
		case 1: {
			int estado = NivelesRitmo1(buffer->Graphics, controladora, 1, bmpNota1, bmpNota2, bmpNota3);
			punk->DibujarRitmo(buffer->Graphics, bmpPunk);
			tecla = 'f';
			if (estado != 0) {  //1=gano, 2=perdio
				timer1->Stop();
				if (estado == 1) puntuaciontotal += controladora->GetPuntaje();
				this->DialogResult = (estado == 1) ? System::Windows::Forms::DialogResult::OK
					: System::Windows::Forms::DialogResult::Cancel;
				return;
			}
			break;
		}
		default: break;
		}
		buffer->Render(gr);
	}
	private: System::Void NivelRitmo_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		timer1->Stop();
	}
	private: System::Void NivelRitmo_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::A:
			punk->PunkMoverRitmo(buffer->Graphics, 'A');
			break;
		case Keys::D:
			punk->PunkMoverRitmo(buffer->Graphics, 'D');
			break;
		case Keys::W:
			punk->PunkMoverRitmo(buffer->Graphics, 'W');
			break;
		case Keys::S:
			punk->PunkMoverRitmo(buffer->Graphics, 'S');
			break;
		case Keys::B: tecla = 'B'; controladora->GolpearNota(punk->CrearRectangle(), tecla); break;
		case Keys::N: tecla = 'N'; controladora->GolpearNota(punk->CrearRectangle(), tecla); break;
		case Keys::M: tecla = 'M'; controladora->GolpearNota(punk->CrearRectangle(), tecla); break;
		default: break;
		}
	}
};
}