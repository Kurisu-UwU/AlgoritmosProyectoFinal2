#pragma once
#include "ControladoraNivelRitmo.h"
namespace AlgoritmosProyectoFinal2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NivelRitmo
	/// </summary>
	public ref class NivelRitmo : public System::Windows::Forms::Form
	{
	public:
		NivelRitmo(int n)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			gr = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(gr, this->ClientRectangle);
			nivel = n;
			bmpNota1 = gcnew Bitmap("Imagenes/NotasMusicales1.png");
			bmpNota2 = gcnew Bitmap("Imagenes/NotasMusicales2.png");
			bmpNota3 = gcnew Bitmap("Imagenes/NotasMusicales3.png");
			bmpMapaMusical = gcnew Bitmap("Imagenes/PunkMapaMusical.png");
			controladora = new ControladoraNivelRitmo();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NivelRitmo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		Graphics^ gr;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpMapaMusical;
		Bitmap^ bmpPunk;
		Bitmap^ bmpNota1;
		Bitmap^ bmpNota2;
		Bitmap^ bmpNota3;
		ControladoraNivelRitmo* controladora;
	private: System::Windows::Forms::Timer^ timer1;
		   int nivel;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &NivelRitmo::timer1_Tick);
			// 
			// NivelRitmo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(974, 575);
			this->Name = L"NivelRitmo";
			this->Text = L"NivelRitmo";
			this->Load += gcnew System::EventHandler(this, &NivelRitmo::NivelRitmo_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void NivelRitmo_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		switch (nivel) {
		case 1:
			buffer->Graphics->DrawImage(bmpMapaMusical, 0, 0, this->Width, this->Height);
			controladora->dibujar_elementos(gr, bmpNota1, bmpNota2, bmpNota3);
			buffer->Render(gr);
		}
	}
	};
}
