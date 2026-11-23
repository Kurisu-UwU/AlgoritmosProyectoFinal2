#pragma once
// ============================================================================
//  DialogosPanel.h  -  Dialogos estilo novela visual dentro de un Panel (no ventana)
//  - No bloquea la interfaz (usa un Timer, nada de _sleep ni bucles).
//  - Mismos controles que la version consola:  Z = texto rapido,  X = saltar todo.
//  - Extra de novela visual: ESPACIO / ENTER / E / clic = siguiente linea.
//  - Retratos recortados de los sprites que ya tienes en /Imagenes.
// ============================================================================

namespace AlgoritmosProyectoFinal2 {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Windows::Forms;

	public enum class Perfil { Ninguno, Miles, Miguel, Punk, Gwen, Spot };

	public ref class LineaDialogo {
	public:
		String^ nombre;
		Perfil perfil;
		bool izquierda;     // true: retrato a la izquierda (heroes), false: a la derecha
		String^ texto;
		int velocidad;      // milisegundos por letra (igual que el 'sleep' de EscribirTextoAnimado)
		LineaDialogo(String^ n, Perfil p, bool izq, String^ t, int v) {
			nombre = n; perfil = p; izquierda = izq; texto = t; velocidad = v;
		}
	};

	public ref class NovelaVisual {
	private:
		literal int MARG = 8;     // margen del panel
		literal int RET = 93;     // lado del cuadro del retrato (panel de 109 de alto)

		Panel^ panel;
		System::Windows::Forms::Timer^ timer;
		List<LineaDialogo^>^ lineas;
		int indice;
		int visibles;             // letras ya escritas de la linea actual
		double acum;              // milisegundos acumulados para el efecto maquina de escribir
		int esperaAuto;
		bool activo;
		bool acelerado;
		String^ textoEnvuelto;    // linea actual ya partida en renglones
		Action^ alTerminar;

		Graphics^ grp;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpPunk;
		Bitmap^ bmpSpot;
		Bitmap^ bmpGwen;
		Bitmap^ bmpMiles;
		Bitmap^ bmpMiguel;

		System::Drawing::Font^ fuenteTexto;
		System::Drawing::Font^ fuenteNombre;
		System::Drawing::Font^ fuenteTitulo;
		System::Drawing::Font^ fuentePista;

	public:
		bool autoAvance;          // true: pasa sola a la siguiente linea (como la version consola)
		int pausaAuto;            // ms de espera antes de pasar sola

		property bool Activo { bool get() { return activo; } }

		NovelaVisual(Panel^ p) {
			panel = p;
			lineas = gcnew List<LineaDialogo^>();
			indice = 0; visibles = 0; acum = 0; esperaAuto = 0;
			activo = false; acelerado = false;
			autoAvance = false; pausaAuto = 1500;
			alTerminar = nullptr;

			bmpPunk = gcnew Bitmap("Imagenes/SpiderPunk.png");
			bmpSpot = gcnew Bitmap("Imagenes/Spot.png");
			bmpGwen = gcnew Bitmap("Imagenes/Gwen.png");
			bmpMiles = gcnew Bitmap("Imagenes/MilesMorales.png");
			bmpMiguel = gcnew Bitmap("Imagenes/MiguelOhara.png");

			fuenteTexto = gcnew System::Drawing::Font("Comic Sans MS", 14.0f);
			fuenteNombre = gcnew System::Drawing::Font("Comic Sans MS", 12.0f, FontStyle::Bold);
			fuenteTitulo = gcnew System::Drawing::Font("Comic Sans MS", 24.0f, FontStyle::Bold);
			fuentePista = gcnew System::Drawing::Font("Comic Sans MS", 8.0f);

			timer = gcnew System::Windows::Forms::Timer();
			timer->Interval = 20;
			timer->Tick += gcnew EventHandler(this, &NovelaVisual::Tick);
			panel->Click += gcnew EventHandler(this, &NovelaVisual::AlClick);

			// el panel solo se ve mientras dura el dialogo; el label de prueba (label4) ya no hace falta
			for each (Control ^ c in panel->Controls) { c->Visible = false; }
			panel->Visible = false;
		}

		// ---- armar el dialogo --------------------------------------------------
		void Agregar(String^ nombre, Perfil perfil, bool izquierda, String^ texto, int velocidad) {
			lineas->Add(gcnew LineaDialogo(nombre, perfil, izquierda, texto->Trim(), velocidad));
		}
		void AgregarTitulo(String^ texto, int velocidad) {   // texto grande centrado, sin retrato
			lineas->Add(gcnew LineaDialogo("", Perfil::Ninguno, false, texto->Trim(), velocidad));
		}

		// ---- reproducir ----------------------------------------------------------
		void Iniciar() { Iniciar(nullptr); }
		void Iniciar(Action^ cuandoTermine) {
			if (lineas->Count == 0) {
				if (cuandoTermine != nullptr) cuandoTermine->Invoke();
				return;
			}
			alTerminar = cuandoTermine;
			indice = 0; acelerado = false; activo = true;

			panel->Visible = true;
			panel->BringToFront();

			if (buffer != nullptr) { delete buffer; buffer = nullptr; }
			if (grp != nullptr) { delete grp; grp = nullptr; }
			grp = panel->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(grp, panel->ClientRectangle);
			buffer->Graphics->TextRenderingHint = System::Drawing::Text::TextRenderingHint::ClearTypeGridFit;
			buffer->Graphics->InterpolationMode = InterpolationMode::NearestNeighbor;   // pixel art nitido
			buffer->Graphics->PixelOffsetMode = PixelOffsetMode::Half;

			PrepararLinea();
			timer->Start();
		}

		// Devuelve true si la tecla fue consumida por el dialogo
		bool ProcesarTecla(Keys k) {
			if (!activo) return false;
			switch (k) {
			case Keys::Space:
			case Keys::Enter:
			case Keys::E:
				Avanzar();
				break;
			case Keys::Z:
				acelerado = true;
				break;
			case Keys::X:
				Terminar();
				break;
			default: break;
			}
			return true;
		}

		void Liberar() {
			timer->Stop();
			activo = false;
			if (buffer != nullptr) { delete buffer; buffer = nullptr; }
			if (grp != nullptr) { delete grp; grp = nullptr; }
		}

	private:
		void AlClick(Object^ sender, EventArgs^ e) { Avanzar(); }

		void Avanzar() {
			if (!activo) return;
			if (visibles < textoEnvuelto->Length) {      // primero completa la linea
				visibles = textoEnvuelto->Length;
				return;
			}
			indice++;
			if (indice >= lineas->Count) { Terminar(); return; }
			PrepararLinea();
		}

		void Terminar() {
			timer->Stop();
			activo = false;
			acelerado = false;
			panel->Visible = false;
			lineas->Clear();
			Action^ cb = alTerminar;
			alTerminar = nullptr;
			if (cb != nullptr) cb->Invoke();
		}

		void PrepararLinea() {
			LineaDialogo^ l = lineas[indice];
			visibles = 0; acum = 0; esperaAuto = 0;
			int W = panel->ClientSize.Width;
			float ancho;
			System::Drawing::Font^ f;
			if (l->perfil == Perfil::Ninguno) { ancho = W - 80.0f; f = fuenteTitulo; }
			else { ancho = W - (MARG + RET + 16) - 24.0f; f = fuenteTexto; }
			textoEnvuelto = Envolver(l->texto, f, ancho);
		}

		String^ Envolver(String^ t, System::Drawing::Font^ f, float ancho) {
			Graphics^ g = buffer->Graphics;
			System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
			String^ linea = "";
			int pos = 0;
			while (pos <= t->Length) {                 // recorre palabra por palabra sin usar arrays
				int sig = t->IndexOf(' ', pos);
				if (sig < 0) sig = t->Length;
				String^ p = t->Substring(pos, sig - pos);
				pos = sig + 1;
				String^ prueba = (linea->Length == 0) ? p : (linea + " " + p);
				if (linea->Length > 0 && g->MeasureString(prueba, f).Width > ancho) {
					sb->Append(linea);
					sb->Append(L'\n');
					linea = p;
				}
				else { linea = prueba; }
			}
			sb->Append(linea);
			return sb->ToString();
		}

		// pausa DESPUES de mostrar la letra anterior (los puntos y signos hacen pausa dramatica)
		double RetardoDespuesDe(wchar_t anterior, int velocidad) {
			if (anterior == L'\n') return 0.0;
			if (anterior == L'.' || anterior == L',' || anterior == L'?' || anterior == L'!') return velocidad * 6.0;
			return (double)velocidad;
		}

		void Tick(Object^ sender, EventArgs^ e) {
			if (!activo) return;
			LineaDialogo^ l = lineas[indice];
			int total = textoEnvuelto->Length;

			if (visibles < total) {
				acum += timer->Interval * (acelerado ? 8.0 : 1.0);
				while (visibles < total) {
					double d = (visibles == 0) ? 0.0 : RetardoDespuesDe(textoEnvuelto[visibles - 1], l->velocidad);
					if (acum < d) break;
					acum -= d;
					visibles++;
				}
			}
			else if (autoAvance) {
				esperaAuto += timer->Interval;
				if (esperaAuto >= pausaAuto) {
					Avanzar();
					if (!activo) return;
				}
			}
			Dibujar();
		}

		Color ColorDe(Perfil p) {
			switch (p) {
			case Perfil::Punk:   return Color::FromArgb(235, 60, 60);
			case Perfil::Miles:  return Color::FromArgb(220, 40, 70);
			case Perfil::Miguel: return Color::FromArgb(210, 30, 30);
			case Perfil::Gwen:   return Color::FromArgb(255, 105, 180);
			case Perfil::Spot:   return Color::FromArgb(235, 235, 235);
			default:             return Color::FromArgb(255, 128, 0);   // naranja, como tu label4
			}
		}

		Bitmap^ BmpDe(Perfil p) {
			switch (p) {
			case Perfil::Punk:   return bmpPunk;
			case Perfil::Miles:  return bmpMiles;
			case Perfil::Miguel: return bmpMiguel;
			case Perfil::Gwen:   return bmpGwen;
			case Perfil::Spot:   return bmpSpot;
			default:             return nullptr;
			}
		}

		void Dibujar() {
			Graphics^ g = buffer->Graphics;
			int W = panel->ClientSize.Width;
			int H = panel->ClientSize.Height;
			LineaDialogo^ l = lineas[indice];
			Color acento = ColorDe(l->perfil);
			bool lineaCompleta = (visibles >= textoEnvuelto->Length);

			g->Clear(Color::FromArgb(20, 20, 32));
			Pen^ penBorde = gcnew Pen(acento, 3.0f);
			g->DrawRectangle(penBorde, 1, 1, W - 3, H - 3);

			SolidBrush^ brTexto = gcnew SolidBrush(Color::White);
			SolidBrush^ brAcento = gcnew SolidBrush(acento);
			SolidBrush^ brPista = gcnew SolidBrush(Color::FromArgb(130, 130, 150));
			StringFormat^ fmtDer = gcnew StringFormat();
			fmtDer->Alignment = StringAlignment::Far;

			String^ visible = textoEnvuelto->Substring(0, visibles);

			if (l->perfil == Perfil::Ninguno) {
				// tarjeta de titulo: texto grande centrado
				StringFormat^ fmtCentro = gcnew StringFormat();
				fmtCentro->Alignment = StringAlignment::Center;
				fmtCentro->LineAlignment = StringAlignment::Center;
				g->DrawString(visible, fuenteTitulo, brAcento, RectangleF(0.0f, 0.0f, (float)W, (float)H), fmtCentro);
				delete fmtCentro;
			}
			else {
				// retrato
				int px = l->izquierda ? MARG : W - MARG - RET;
				System::Drawing::Rectangle marco = System::Drawing::Rectangle(px, MARG, RET, RET);
				SolidBrush^ brFondo = gcnew SolidBrush(Color::FromArgb(120, 120, 150));   // gris azulado: se ven Spot (blanco) y Miles (oscuro)
				g->FillRectangle(brFondo, marco);
				Bitmap^ bmp = BmpDe(l->perfil);
				if (bmp != nullptr) {
					// recorte de cabeza y torso del primer cuadro del sprite (64x64). Ajusta aqui si quieres otro encuadre.
					System::Drawing::Rectangle recorte = System::Drawing::Rectangle(12, 0, 40, 40);
					g->DrawImage(bmp, marco, recorte, GraphicsUnit::Pixel);
				}
				g->DrawRectangle(penBorde, marco);
				delete brFondo;

				// nombre y texto
				int x0 = l->izquierda ? (MARG + RET + 16) : 24;
				int x1 = l->izquierda ? (W - 24) : (W - MARG - RET - 16);
				g->DrawString(l->nombre, fuenteNombre, brAcento, (float)x0, 5.0f);
				g->DrawString(visible, fuenteTexto, brTexto, (float)x0, 32.0f);
				g->DrawString("Espacio: siguiente  |  Z: rapido  |  X: saltar", fuentePista, brPista,
					RectangleF((float)x0, 8.0f, (float)(x1 - x0), 18.0f), fmtDer);
			}

			// triangulito parpadeante: "ya termino, pulsa para seguir"
			if (lineaCompleta && ((Environment::TickCount / 400) % 2 == 0)) {
				int tx = W - 40;
				int ty = H - 24;
				if (l->perfil != Perfil::Ninguno && !l->izquierda) tx = W - MARG - RET - 16 - 24;
				for (int i = 0; i < 10; i++) {          // triangulo dibujado con lineas horizontales (sin arrays)
					g->FillRectangle(brAcento, tx + i, ty + i, 16 - 2 * i, 1);
				}
			}

			delete penBorde; delete brTexto; delete brAcento; delete brPista; delete fmtDer;
			buffer->Render(grp);
		}
	};
}
