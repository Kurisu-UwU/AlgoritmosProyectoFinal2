#pragma once
// ============================================================================
//  DialogosPanel.h  -  Dialogos estilo novela visual dentro de un Panel (no ventana)
//  - Sin listas ni arrays: cada dialogo es un switch por numero de linea,
//    igual que TextPunk1(int n) de la version consola.
//  - Perfiles con los mismos numeros que CuadroDeTexto: 1 Miles, 2 Miguel, 3 Punk, 4 Gwen, 5 Spot, 8 Peny (0 = sin retrato)
//  - Controles: Z = texto rapido, X = saltar todo, ESPACIO / ENTER / E / clic = siguiente linea.
// ============================================================================

namespace AlgoritmosProyectoFinal2 {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Windows::Forms;

	public ref class NovelaVisual {
	private:
		int MARG;                 // margen del panel
		int RET;                  // lado del cuadro del retrato

		Panel^ panel;
		System::Windows::Forms::Timer^ timer;

		// linea actual
		String^ nombreActual;
		int perfilActual;
		bool izqActual;
		String^ textoActual;
		int velActual;            // milisegundos por letra (igual que el 'sleep' de EscribirTextoAnimado)

		int escena;               // que dialogo se esta reproduciendo
		int indice;               // numero de linea dentro del dialogo
		int visibles;             // letras ya escritas de la linea actual
		double acum;              // milisegundos acumulados para el efecto maquina de escribir
		int esperaAuto;
		bool activo;
		bool acelerado;
		String^ textoEnvuelto;    // linea actual ya partida en renglones

		Graphics^ grp;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpPunk;
		Bitmap^ bmpSpot;
		Bitmap^ bmpGwen;
		Bitmap^ bmpMiles;
		Bitmap^ bmpMiguel;
		Bitmap^ bmpPeny;

		System::Drawing::Font^ fuenteTexto;
		System::Drawing::Font^ fuenteNombre;
		System::Drawing::Font^ fuenteTitulo;
		System::Drawing::Font^ fuentePista;

	public:
		bool autoAvance;          // true: pasa sola a la siguiente linea (como la version consola)
		int pausaAuto;            // ms de espera antes de pasar sola

		NovelaVisual(Panel^ p) {
			panel = p;
			MARG = 8; RET = 93;
			indice = 0; visibles = 0; acum = 0; esperaAuto = 0; escena = 0;
			activo = false; acelerado = false;
			autoAvance = false; pausaAuto = 1500;
			nombreActual = ""; textoActual = ""; textoEnvuelto = "";
			perfilActual = 0; izqActual = true; velActual = 40;

			bmpPunk = gcnew Bitmap("Imagenes/SpiderPunk.png");
			bmpSpot = gcnew Bitmap("Imagenes/Spot.png");
			bmpGwen = gcnew Bitmap("Imagenes/Gwen.png");
			bmpMiles = gcnew Bitmap("Imagenes/MilesMorales.png");
			bmpMiguel = gcnew Bitmap("Imagenes/MiguelOhara.png");
			bmpPeny = gcnew Bitmap("Imagenes/PenyParker.png");

			fuenteTexto = gcnew System::Drawing::Font("Comic Sans MS", 14.0f);
			fuenteNombre = gcnew System::Drawing::Font("Comic Sans MS", 12.0f, FontStyle::Bold);
			fuenteTitulo = gcnew System::Drawing::Font("Comic Sans MS", 24.0f, FontStyle::Bold);
			fuentePista = gcnew System::Drawing::Font("Comic Sans MS", 8.0f);

			timer = gcnew System::Windows::Forms::Timer();
			timer->Interval = 20;
			timer->Tick += gcnew EventHandler(this, &NovelaVisual::Tick);
			panel->Click += gcnew EventHandler(this, &NovelaVisual::AlClick);

			// el label de prueba (label4) ya no hace falta: se oculta
			int i = 0;
			while (i < panel->Controls->Count) { panel->Controls[i]->Visible = false; i++; }
			panel->Visible = false;
		}

		bool EstaActivo() { return activo; }

		// ---- reproducir un dialogo (1 = intro de Punk) ---------------------------
		void Iniciar(int numeroEscena) {
			escena = numeroEscena;
			indice = 0;
			if (!CargarLinea()) return;
			acelerado = false; activo = true;

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

			PrepararTexto();
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
		// =====================  LOS DIALOGOS  =====================
		// Linea(nombre, perfil, retratoALaIzquierda, texto, velocidad)
		void Linea(String^ n, int perfil, bool izq, String^ t, int v) {
			nombreActual = n; perfilActual = perfil; izqActual = izq; textoActual = t->Trim(); velActual = v;
		}

		// Devuelve false cuando ya no hay mas lineas
		bool CargarLinea() {
			switch (escena) {
			case 1: return DialogoPunkIntro(indice);
			default: return false;
			}
		}

		bool DialogoPunkIntro(int n) {
			switch (n) {
				// ---- titulo ----
			case 0:  Linea("", 0, false, "Anarquia entre los 2 caminos", 25); return true;
			case 1:  Linea("", 0, false, "A ROCKEAR!", 50); return true;
				// ---- Punk y Peny ----
			case 2:  Linea("Peny Parker", 8, false, "Punk! Por fin respondes!", 40); return true;
			case 3:  Linea("Spider Punk", 3, true, "... Peny. Que pasa?", 40); return true;
			case 4:  Linea("Peny Parker", 8, false, "La maquina de dimensiones se averio y todos quedamos dispersos", 40); return true;
			case 5:  Linea("Spider Punk", 3, true, "Genial... mas problemas", 40); return true;
			case 6:  Linea("Peny Parker", 8, false, "Para reunirnos de nuevo necesitamos reparar el portal", 40); return true;
			case 7:  Linea("Peny Parker", 8, false, "Hay varias herramientas escondidas en unos cofres por esta zona", 40); return true;
			case 8:  Linea("Spider Punk", 3, true, "Herramientas... en cofres?", 40); return true;
			case 9:  Linea("Peny Parker", 8, false, "Si! Pero tienen un seguro musical, tendras que seguir el ritmo para abrirlos", 40); return true;
			case 10: Linea("Spider Punk", 3, true, "Hmph... suena a trabajo. Pero me gusta el ruido", 50); return true;
			case 11: Linea("Peny Parker", 8, false, "Cuando las tengas todas podremos reunirnos con los demas. Suerte, Punk!", 40); return true;
				// ---- Punk y Gwen ----
			case 12: Linea("Spider Punk", 3, true, "... Que.... problematico", 25); return true;
			case 13: Linea("Spider Punk", 3, true, "Bien... tengo cosas pendientes por hacer", 40); return true;
			case 14: Linea("Spider Punk", 3, true, "... adios", 50); return true;
			case 15: Linea("Gwen Stacy", 4, false, "Vas a dejarnos justo ahora?!... EN UN MOMENTO COMO ESTE???", 50); return true;
			case 16: Linea("Gwen Stacy", 4, false, "Tenemos que hablar con miles, el tiene que... entender... que el canon no puede cambiarse...", 50); return true;
			case 17: Linea("Spider Punk", 3, true, "... Como dije, tengo asuntos pendientes, a no ser que quieras venir conmigo", 50); return true;
			case 18: Linea("Spider Punk", 3, true, "Vas a tener que encontrar cofres y recolectar tornillos...", 50); return true;
			case 19: Linea("Gwen Stacy", 4, false, "Tornillos?... bueno.. mas te vale que sea importante...", 50); return true;
			case 20: Linea("Gwen Stacy", 4, false, "Bueno... sabes donde encontrarme", 50); return true;
			default: return false;
			}
		}
		// =========================================================

		void AlClick(Object^ sender, EventArgs^ e) { Avanzar(); }

		void Avanzar() {
			if (!activo) return;
			if (visibles < textoEnvuelto->Length) {      // primero completa la linea
				visibles = textoEnvuelto->Length;
				return;
			}
			indice++;
			if (!CargarLinea()) { Terminar(); return; }
			PrepararTexto();
		}

		void Terminar() {
			timer->Stop();
			activo = false;
			acelerado = false;
			panel->Visible = false;
		}

		void PrepararTexto() {
			visibles = 0; acum = 0; esperaAuto = 0;
			int W = panel->ClientSize.Width;
			if (perfilActual == 0) { textoEnvuelto = Envolver(textoActual, fuenteTitulo, W - 80.0f); }
			else { textoEnvuelto = Envolver(textoActual, fuenteTexto, W - (MARG + RET + 16) - 24.0f); }
		}

		// parte el texto en renglones segun el ancho disponible, palabra por palabra
		String^ Envolver(String^ t, System::Drawing::Font^ f, float ancho) {
			Graphics^ g = buffer->Graphics;
			String^ resultado = "";
			String^ linea = "";
			int pos = 0;
			while (pos <= t->Length) {
				int sig = t->IndexOf(' ', pos);
				if (sig < 0) sig = t->Length;
				String^ p = t->Substring(pos, sig - pos);
				pos = sig + 1;
				String^ prueba = (linea->Length == 0) ? p : (linea + " " + p);
				if (linea->Length > 0 && g->MeasureString(prueba, f).Width > ancho) {
					resultado = resultado + linea + "\n";
					linea = p;
				}
				else { linea = prueba; }
			}
			return resultado + linea;
		}

		// pausa DESPUES de mostrar la letra anterior (los puntos y signos hacen pausa dramatica)
		double RetardoDespuesDe(wchar_t anterior, int velocidad) {
			if (anterior == L'\n') return 0.0;
			if (anterior == L'.' || anterior == L',' || anterior == L'?' || anterior == L'!') return velocidad * 6.0;
			return (double)velocidad;
		}

		void Tick(Object^ sender, EventArgs^ e) {
			if (!activo) return;
			int total = textoEnvuelto->Length;

			if (visibles < total) {
				acum += timer->Interval * (acelerado ? 8.0 : 1.0);
				while (visibles < total) {
					double d = (visibles == 0) ? 0.0 : RetardoDespuesDe(textoEnvuelto[visibles - 1], velActual);
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

		Color ColorDe(int perfil) {
			switch (perfil) {
			case 1:  return Color::FromArgb(220, 40, 70);     // Miles
			case 2:  return Color::FromArgb(210, 30, 30);     // Miguel
			case 3:  return Color::FromArgb(235, 60, 60);     // Punk
			case 4:  return Color::FromArgb(255, 105, 180);   // Gwen
			case 5:  return Color::FromArgb(235, 235, 235);   // Spot
			case 8:  return Color::FromArgb(150, 110, 255);   // Peny (morado, como el corazon de su arte)
			default: return Color::FromArgb(255, 128, 0);     // naranja, como tu label4
			}
		}

		Bitmap^ BmpDe(int perfil) {
			switch (perfil) {
			case 1:  return bmpMiles;
			case 2:  return bmpMiguel;
			case 3:  return bmpPunk;
			case 4:  return bmpGwen;
			case 5:  return bmpSpot;
			case 8:  return bmpPeny;
			default: return nullptr;
			}
		}

		void Dibujar() {
			Graphics^ g = buffer->Graphics;
			int W = panel->ClientSize.Width;
			int H = panel->ClientSize.Height;
			Color acento = ColorDe(perfilActual);
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

			if (perfilActual == 0) {
				// tarjeta de titulo: texto grande centrado
				StringFormat^ fmtCentro = gcnew StringFormat();
				fmtCentro->Alignment = StringAlignment::Center;
				fmtCentro->LineAlignment = StringAlignment::Center;
				g->DrawString(visible, fuenteTitulo, brAcento, RectangleF(0.0f, 0.0f, (float)W, (float)H), fmtCentro);
				delete fmtCentro;
			}
			else {
				// retrato
				int px = izqActual ? MARG : W - MARG - RET;
				System::Drawing::Rectangle marco = System::Drawing::Rectangle(px, MARG, RET, RET);
				SolidBrush^ brFondo = gcnew SolidBrush(Color::FromArgb(120, 120, 150));   // gris azulado: se ven Spot (blanco) y Miles (oscuro)
				g->FillRectangle(brFondo, marco);
				Bitmap^ bmp = BmpDe(perfilActual);
				if (bmp != nullptr) {
					// recorte de cabeza y torso del primer cuadro del sprite (64x64). Ajusta aqui si quieres otro encuadre.
					System::Drawing::Rectangle recorte = System::Drawing::Rectangle(12, 0, 40, 40);
					if (perfilActual == 8) recorte = System::Drawing::Rectangle(140, 45, 190, 190);   // Peny: imagen grande (461x462), cabeza y torso
					g->DrawImage(bmp, marco, recorte, GraphicsUnit::Pixel);
				}
				g->DrawRectangle(penBorde, marco);
				delete brFondo;

				// nombre y texto
				int x0 = izqActual ? (MARG + RET + 16) : 24;
				int x1 = izqActual ? (W - 24) : (W - MARG - RET - 16);
				g->DrawString(nombreActual, fuenteNombre, brAcento, (float)x0, 5.0f);
				g->DrawString(visible, fuenteTexto, brTexto, (float)x0, 32.0f);
				g->DrawString("Espacio: siguiente  |  Z: rapido  |  X: saltar", fuentePista, brPista,
					RectangleF((float)x0, 8.0f, (float)(x1 - x0), 18.0f), fmtDer);
			}

			// triangulito parpadeante: "ya termino, pulsa para seguir"
			if (lineaCompleta && ((Environment::TickCount / 400) % 2 == 0)) {
				int tx = W - 40;
				int ty = H - 24;
				if (perfilActual != 0 && !izqActual) tx = W - MARG - RET - 16 - 24;
				for (int i = 0; i < 10; i++) {
					g->FillRectangle(brAcento, tx + i, ty + i, 16 - 2 * i, 1);
				}
			}

			delete penBorde; delete brTexto; delete brAcento; delete brPista; delete fmtDer;
			buffer->Render(grp);
		}
	};
}
