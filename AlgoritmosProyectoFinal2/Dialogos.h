#pragma once

namespace AlgoritmosProyectoFinal2 {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Windows::Forms;

	public ref class NovelaVisual {
	private:
		int MARG;
		int RET;

		Panel^ panel;
		System::Windows::Forms::Timer^ timer;

		// linea actual
		String^ nombreActual;
		int perfilActual;
		bool izqActual;
		String^ textoActual;
		int velActual;

		int escena;
		int indice;
		int visibles;
		double acum;
		int esperaAuto;
		bool activo;
		bool acelerado;
		String^ textoEnvuelto;

		Graphics^ grp;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpPunk;
		Bitmap^ bmpSpot;
		Bitmap^ bmpGwen;
		Bitmap^ bmpMiles;
		Bitmap^ bmpMiguel;
		Bitmap^ bmpPeny;
		Bitmap^ bmpMargo;
		Bitmap^ bmpWoman;
		Bitmap^ bmpPeter;
		Bitmap^ bmpPavitr;
		Bitmap^ bmpNoir;

		System::Drawing::Font^ fuenteTexto;
		System::Drawing::Font^ fuenteNombre;
		System::Drawing::Font^ fuenteTitulo;
		System::Drawing::Font^ fuentePista;

	public:
		bool autoAvance;
		int pausaAuto;

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
			bmpMargo = CargarBmp("Imagenes/MargoKees.png");
			bmpWoman = CargarBmp("Imagenes/SpiderWoman.png");
			bmpPeter = CargarBmp("Imagenes/PeterPorker.png");
			bmpPavitr = CargarBmp("Imagenes/Pavitr.png");
			bmpNoir = CargarBmp("Imagenes/Noir.png");

			fuenteTexto = gcnew System::Drawing::Font("Comic Sans MS", 14.0f);
			fuenteNombre = gcnew System::Drawing::Font("Comic Sans MS", 12.0f, FontStyle::Bold);
			fuenteTitulo = gcnew System::Drawing::Font("Comic Sans MS", 24.0f, FontStyle::Bold);
			fuentePista = gcnew System::Drawing::Font("Comic Sans MS", 8.0f);

			timer = gcnew System::Windows::Forms::Timer();
			timer->Interval = 20;
			timer->Tick += gcnew EventHandler(this, &NovelaVisual::Tick);
			panel->Click += gcnew EventHandler(this, &NovelaVisual::AlClick);

			int i = 0;
			while (i < panel->Controls->Count) { panel->Controls[i]->Visible = false; i++; }
			panel->Visible = false;
		}
		Bitmap^ CargarBmp(String^ ruta) {
			if (System::IO::File::Exists(ruta)) return gcnew Bitmap(ruta);
			return nullptr;
		}
		bool EstaActivo() { return activo; }

		// ---- reproducir un dialogo ------------------------------------------------------------------
		// 1 = Punk intro | 2 = Punk antes de Spot | 3 = Miles intro | 4 = Miles con Gwen | 5 = Miguel intro
		// 6 = Miguel 1 | 7 = Miguel 2 (llamada) | 8 = Miguel final | 9 = Peter Porker | 10 = Pavitr
		// 11 = Noir | 12 = Spider Woman | 13 = Spot escapa | 14 = Final (todos) | 15 = Final Miles
		// 16 = Final Miguel | 17 = Final Punk | 18 = Final nivel 3
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
			buffer->Graphics->InterpolationMode = InterpolationMode::NearestNeighbor;
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
		void Linea(String^ n, int perfil, bool izq, String^ t, int v) {
			nombreActual = n; perfilActual = perfil; izqActual = izq; textoActual = t->Trim(); velActual = v;
		}
		// Devuelve false cuando ya no hay mas lineas
		bool CargarLinea() {
			switch (escena) {
			case 1: return DialogoPunkIntro(indice);
			case 2: return DialogoPunkSpot(indice);
			case 3: return DialogoMilesIntro(indice);
			case 4: return DialogoMilesConGwen(indice);
			case 5: return DialogoMiguelIntro(indice);
			case 6: return DialogoMiguel1(indice);
			case 7: return DialogoMiguel2(indice);
			case 8: return DialogoMiguelFinal(indice);
			case 9: return DialogoPeterPorker(indice);
			case 10: return DialogoPavitr(indice);
			case 11: return DialogoNoir(indice);
			case 12: return DialogoWoman(indice);
			case 13: return DialogoSpotScape(indice);
			case 14: return DialogoFinal(indice);
			case 15: return DialogoFinalMiles(indice);
			case 16: return DialogoFinalMiguel(indice);
			case 17: return DialogoFinalPunk(indice);
			case 18: return DialogoFinalNivel3(indice);
			default: return false;
			}
		}
		bool DialogoMilesIntro(int n) {
			switch (n) {  // 1 = miles / 2 = miguel / 3 = punk / 4 = gwen / 5 = spot / 8 = peny
				// ---- titulo ----
			case 0:  Linea("", 0, false, "La realidad que aveces duele", 25); return true;
			case 1:  Linea("", 0, false, "Adentrandose en la recamara de contencion...", 50); return true;
				// ---- Punk y Peny ----
			case 2:  Linea("Miles Morales", 1, true, "Que... acabas de hacer?... quien.. eres?", 40); return true;

			case 3:  Linea("The Spot", 5, false, "Yo?....      ", 40); return true;
			case 4:  Linea("The Spot", 5, false, "Yo soy tu         ", 40); return true;
			case 5:  Linea("The Spot", 5, false, "Y tu... eres yo      ", 40); return true;
			case 6:  Linea("The Spot", 5, false, "Yo te cree a ti          ", 40); return true;
			case 7:  Linea("The Spot", 5, false, "Te converti en lo que eres ahora       ", 40); return true;
			case 8:  Linea("The Spot", 5, false, "Un HEROE      ", 40); return true;
			case 9:  Linea("The Spot", 5, false, "Y tu? me creaste como un monstruo     ", 40); return true;
			case 10: Linea("The Spot", 5, false, "YO SOY TU NEMESIS        ", 50); return true;

			case 11: Linea("Miguel O'hara", 2, true, "........       ", 40); return true;

			case 12: Linea("Spider Punk", 3, true, "Vaya problema         ", 25); return true;

			case 13: Linea("Miles Morales", 1, true, "Que... piensas hacerle a mi padre?      ", 40); return true;

			case 14: Linea("The Spot", 5, false, "Que pienso hacer?... es simple    ", 50); return true;
			case 15: Linea("The Spot", 5, false, "TU destruiste mi vida        ", 50); return true;
			case 16: Linea("The Spot", 5, false, "Yo destruire la TUYA        ", 50); return true;
			case 17: Linea("The Spot", 5, false, "Es tu destino, asi como lo fue el mio        ", 50); return true;
			case 18: Linea("The Spot", 5, false, "El CANON no puede cambiarse, Miles        ", 50); return true;

			case 19: Linea("Miles Morales", 1, true, "No te atrevas a HACERLE DANO!!!!!!        ", 50); return true;

			case 20: Linea("Miguel O'hara", 2, false, "ALTO!     ", 50); return true;

			case 21: Linea("Miles Morales", 1, true, "....", 50); return true;

			case 22: Linea("Miguel O'hara", 2, false, "Miles      ", 50); return true;
			case 23: Linea("Miguel O'hara", 2, false, "Sabes muy bien qu-", 50); return true;

			case 24: Linea("Miles Morales", 1, true, "Y QUE?    ", 50); return true;
			case 25: Linea("Miles Morales", 1, true, "DICES QUE DEJE MORIR A MI PADRE???", 50); return true;
			case 26: Linea("Miles Morales", 1, true, "ASI SIN MAS??", 50); return true;

			case 27: Linea("Spider Punk", 3, false, ".....      ", 50); return true;
			case 28: Linea("Spider Punk", 3, false, "Miles, escu-", 50); return true;

			case 29: Linea("Miles Morales", 1, true, "No, Lo entiendo", 50); return true;
			default: return false;
			}
		}
		bool DialogoPunkIntro(int n) {
			switch (n) {
				// ---- titulo ----
			case 0:  Linea("", 0, false, "Anarquia entre los 2 caminos", 25); return true;
			case 1:  Linea("", 0, false, "A ROCKEAR!", 50); return true;
				// ---- Punk y Peny ----
			case 2:  Linea("Peny Parker", 8, false, "Punk! Por fin te encuentro!", 40); return true;
			case 3:  Linea("Spider Punk", 3, true, "... Peny. Que haces aqui?", 40); return true;
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
		// Dialogo antes de la pelea contra Spot (escena 2)
		bool DialogoPunkSpot(int n) {
			switch (n) {
			case 0:  Linea("Spider Punk", 3, true, "... Que.... problematico", 25); return true;
			case 1:  Linea("The Spot", 5, false, "No tan rapido..... dime donde esta Miles", 40); return true;
			case 2:  Linea("Spider Punk", 3, true, "TU otra vez!", 50); return true;
			case 3:  Linea("Spider Punk", 3, true, "No vas a escapar esta v-", 50); return true;
			case 4:  Linea("The Spot", 5, false, "Silencio~", 50); return true;
			case 5:  Linea("The Spot", 5, false, "Donde esta?.... Miles.... tengo asuntos pendientes con el", 50); return true;
			case 6:  Linea("Spider Punk", 3, true, "Bueno..... Casualmente yo tambien lo estaba buscando", 50); return true;
			case 7:  Linea("Spider Punk", 3, true, "Que te parece si... el primero que lo encuentra gana?", 50); return true;
			case 8:  Linea("The Spot", 5, false, "Solo quieres hacerme perder el tiempo", 50); return true;
			case 9:  Linea("The Spot", 5, false, "Acabemos esto de una vez", 50); return true;
			case 10: Linea("Spider Punk", 3, true, "Es hora del espectaculo!", 50); return true;
			default: return false;
			}
		}
		// ---- dialogos pasados desde TextoAnimadoDialogosETC.h ----
		// perfiles: 1 miles / 2 miguel / 3 punk / 4 gwen / 5 spot / 6 margo / 7 spider woman / 8 peny
		//           9 peter porker / 10 pavitr / 11 noir / 12 llamada (sin retrato)
		bool DialogoMilesConGwen(int n) {
			switch (n) {
			case 0:   Linea("Gwen Stacy", 4, true, "MILES!", 25); return true;
			case 1:   Linea("Gwen Stacy", 4, true, "No espere encontrarte por aca", 25); return true;
			case 2:   Linea("Gwen Stacy", 4, true, "Y Miguel? aun sigue persiguiendote?", 25); return true;
			case 3:   Linea("Gwen Stacy", 4, true, "Ya veo....", 25); return true;
			case 4:   Linea("Gwen Stacy", 4, true, "Rapido, hay que irnos", 25); return true;
			default: return false;
			}
		}
		bool DialogoMiguelIntro(int n) {
			switch (n) {
			case 0:   Linea("", 0, false, "Miguel: Hola, mi nombre es Miguel O'hara", 25); return true;
			case 1:   Linea("", 0, false, "Salvemos el spider verso!", 50); return true;
			default: return false;
			}
		}
		bool DialogoMiguel1(int n) {
			switch (n) {
			case 0:   Linea("Miguel O'hara", 2, true, "Que acaba de pasar!", 40); return true;
			case 1:   Linea("Miguel O'hara", 2, true, "Como permitieron que Miles escapara, puede romper el canon y destruir el spider verso", 40); return true;
			case 2:   Linea("Gwen Stacy", 4, false, "Pues no se, tal vez no le gritaste con suficiente fuerza", 50); return true;
			case 3:   Linea("Miguel O'hara", 2, true, "Esto es culpa tuya, tu lo trajiste aqui y lo dejaste huir", 50); return true;
			case 4:   Linea("Gwen Stacy", 4, false, "Solo dejenme hablar con el, puedo resolver esto", 50); return true;
			case 5:   Linea("Miguel O'hara", 2, true, "No, ya nos has estorvado suficiente, te prohibo seguirnos a la dimension de Miles", 50); return true;
			case 6:   Linea("Gwen Stacy", 4, false, "No puedes hacer eso, Spider Woman dile que se equivoca", 50); return true;
			case 7:   Linea("Spider Woman", 7, false, "El tiene razon, deberias quedarte aqui", 50); return true;
			case 8:   Linea("Gwen Stacy", 4, false, "Eso no es justo, Miles no tenia malas intenciones", 50); return true;
			case 9:   Linea("Margo Kees", 6, false, "Gwen tiene razon, Miles no sabe lo que esta haciendo", 50); return true;
			case 10:  Linea("Miguel O'hara", 2, true, "Silencio!, tu solo estas aqui para manejar la maquina transportadora", 50); return true;
			case 11:  Linea("Miguel O'hara", 2, true, "Y controlar el sistema de seguridad", 50); return true;
			case 12:  Linea("Margo Kees", 6, false, "Estoy harta de esto, Miles es inocente", 50); return true;
			case 13:  Linea("Margo Kees", 6, false, "Veamos que tan facilmente lo encuentras con tu propio sistema de seguridad en tu contra", 50); return true;
			case 14:  Linea("Miguel O'hara", 2, true, "No tengo tiempo para esto, debo ir tras Miles, tu has lo que quieras", 50); return true;
			case 15:  Linea("Miguel O'hara", 2, true, "Spider Woman, vamonos, tu me ayudaras en la busqueda", 50); return true;
			case 16:  Linea("Spider Woman", 7, false, "Bien, vamonos", 50); return true;
			default: return false;
			}
		}
		bool DialogoMiguel2(int n) {
			switch (n) {
			case 0:   Linea("Spider Woman", 12, false, "Llamada entrante", 40); return true;
			case 1:   Linea("Spider Woman", 7, false, "Hola Miguel, me escuchas?", 40); return true;
			case 2:   Linea("Spider Woman", 7, false, "Paseandome por este lugar me di cuenta de que Miles esta dejando glitches por algunas zonas", 50); return true;
			case 3:   Linea("Spider Woman", 7, false, "Puedes usar esa informacion para localizarlo", 50); return true;
			case 4:   Linea("Spider Woman", 7, false, "Tambien he activado un rastreador que te indicara tu distancia a Miles", 50); return true;
			case 5:   Linea("Spider Woman", 7, false, "Yo buscare por otra zona, mucha suerte", 50); return true;
			default: return false;
			}
		}
		bool DialogoMiguelFinal(int n) {
			switch (n) {
			case 0:   Linea("Miguel O'hara", 2, true, "Por fin, despues de tanto te encuentro", 40); return true;
			case 1:   Linea("Miguel O'hara", 2, true, "No tienes idea de la cantidad de problemas que me has dado hoy", 40); return true;
			case 2:   Linea("Miles Morales", 1, false, "Intentar rescatar a un ser querido es un crimen?", 50); return true;
			case 3:   Linea("Miguel O'hara", 2, true, "Ese no es el punto, pones en riesgo todo el spider verso", 50); return true;
			case 4:   Linea("Miguel O'hara", 2, true, "Ahora que te tengo, por fin, todos estan a salvo", 50); return true;
			default: return false;
			}
		}
		bool DialogoPeterPorker(int n) {
			switch (n) {
			case 0:   Linea("Peter Porker", 9, false, "Estas buscando a Miles, lo vi hace rato por la pista de abajo, dijo algo sobre unas manchas", 40); return true;
			case 1:   Linea("Peter Porker", 9, false, "Sabes de que estaba hablando?", 40); return true;
			case 2:   Linea("Peter Porker", 9, false, "Como sea, encontrarlo no sera dificil, por donde pasa deja glitches", 50); return true;
			default: return false;
			}
		}
		bool DialogoPavitr(int n) {
			switch (n) {
			case 0:   Linea("Pavitr Prabhakar", 10, false, "Estas manchas aparecieron repentinamente", 40); return true;
			case 1:   Linea("Pavitr Prabhakar", 10, false, "Algunas sirven como transporte eficiente", 40); return true;
			case 2:   Linea("Pavitr Prabhakar", 10, false, "Otras te llevan a callejones sin salida", 50); return true;
			case 3:   Linea("Pavitr Prabhakar", 10, false, "Esta por ejemplo no te lleva a ningun lugar, no creo que Miles la haya tomado", 50); return true;
			default: return false;
			}
		}
		bool DialogoNoir(int n) {
			switch (n) {
			case 0:   Linea("Spider Man Noir", 11, false, "Que dice?", 40); return true;
			case 1:   Linea("Spider Man Noir", 11, false, "Si, vi a Miles", 40); return true;
			case 2:   Linea("Spider Man Noir", 11, false, "No, no paso por qui", 50); return true;
			case 3:   Linea("Spider Man Noir", 11, false, "Estaba hasta un estremo de la ciudad, dijo que tuvo que tomar 3 manchas para llegar", 50); return true;
			default: return false;
			}
		}
		bool DialogoWoman(int n) {
			switch (n) {
			case 0:   Linea("Spider Woman", 7, false, "Tambien llegaste aqui?", 40); return true;
			case 1:   Linea("Spider Woman", 7, false, "Siento que ya nos acercamos a Miles", 40); return true;
			case 2:   Linea("Spider Woman", 7, false, "Adelantate y ten cuidado", 50); return true;
			case 3:   Linea("Spider Woman", 7, false, "Creo que oi a alguien del otro lado de la mancha", 50); return true;
			default: return false;
			}
		}
		bool DialogoSpotScape(int n) {
			switch (n) {
			case 0:   Linea("The Spot", 5, false, "O ya llegaste", 40); return true;
			case 1:   Linea("Miguel O'hara", 2, true, "Fuiste tu quien dejo tus manchas por la ciudad", 40); return true;
			case 2:   Linea("Miguel O'hara", 2, true, "Que haces aqui?", 50); return true;
			case 3:   Linea("The Spot", 5, false, "Vine para vengarme de Miles, pero contigo aqui no creo que sea posible", 50); return true;
			case 4:   Linea("The Spot", 5, false, "Se que no puedo vencerte y mi venganza puede esperar", 50); return true;
			case 5:   Linea("The Spot", 5, false, "Como sea, me voy a causar estragos en otro multiverso, ahi te ves", 50); return true;
			default: return false;
			}
		}
		bool DialogoFinal(int n) {
			switch (n) {
			case 0:   Linea("Miguel O'hara", 2, true, "Que singnifica esto?", 40); return true;
			case 1:   Linea("Miguel O'hara", 2, true, "Que hacen aqui?", 40); return true;
			case 2:   Linea("Miguel O'hara", 2, true, "Gwen te prohibi venir a este multiverso", 50); return true;
			case 3:   Linea("Gwen Stacy", 4, true, "Hemos llegado a detenerte", 50); return true;
			case 4:   Linea("Spider Punk", 3, true, "Miguel, tienes que reconsiderarlo, puede haber otra forma", 40); return true;
			case 5:   Linea("Miguel O'hara", 2, true, "Otra forma, de que hablan? Lo que se requiere es aceptar el evento canonico", 40); return true;
			case 6:   Linea("Miles Morales", 1, true, "Miguel no los va a escuchar, ya intente razonar", 50); return true;
			case 7:   Linea("Miguel O'hara", 2, true, "...", 50); return true;
			case 8:   Linea("Miguel O'hara", 2, true, "Bien, los oigo, pero sera mejor que tengan una buena propuesta", 40); return true;
			case 9:   Linea("Spider Punk", 3, true, "No vamos a romper el evento canonico", 40); return true;
			case 10:  Linea("Spider Punk", 3, true, "Pero necesitamos que hables con tu padre y renuncie a su puesto", 50); return true;
			case 11:  Linea("Miles Morales", 1, true, "Claro, de esa manera lo salvaremos y no romperemos el evento canonico", 50); return true;
			case 12:  Linea("Miguel O'hara", 2, true, "No confio en ustedes, como se que haran eso, como se que no fracasaran", 40); return true;
			case 13:  Linea("Miguel O'hara", 2, true, "Todo el spider verso estaria en peligro", 40); return true;
			case 14:  Linea("Gwen Stacy", 4, true, "Miles revelara su identidad", 40); return true;
			case 15:  Linea("Miles Morales", 1, true, "Que yo que?", 40); return true;
			case 16:  Linea("Spider Punk", 3, true, "Miles, no sera tan malo como piensas, claro sera incomodo", 40); return true;
			case 17:  Linea("Spider Punk", 3, true, "Esto es para salvar a tu padre, que pase lo que deba pasar", 40); return true;
			case 18:  Linea("Miguel O'hara", 2, true, "De esta manera podran salvarlo y el spider verso estara a salvo", 40); return true;
			case 19:  Linea("Gwen Stacy", 4, true, "No tenemos que sacrificar algo o alguien por un bien mayor", 40); return true;
			case 20:  Linea("Spider Punk", 3, true, "Siempre podemos llegar a un acuerdo", 40); return true;
			case 21:  Linea("Miguel O'hara", 2, true, "Bien, confio en ustedes", 40); return true;
			default: return false;
			}
		}
		bool DialogoFinalMiles(int n) {
			switch (n) {
			case 0:   Linea("Miles Morales", 1, true, "Elegiste a Miles Morales", 40); return true;
			case 1:   Linea("Miles Morales", 1, true, "Te sentiste mas identificado con su historia", 40); return true;
			case 2:   Linea("Miles Morales", 1, true, "Te preocupas mucho por los demas", 40); return true;
			case 3:   Linea("Miles Morales", 1, true, "Sientes que hay varias formas de resolver un problema", 40); return true;
			case 4:   Linea("Miles Morales", 1, true, "Y no le daras la espalda a un ser querido", 40); return true;
			default: return false;
			}
		}
		bool DialogoFinalMiguel(int n) {
			switch (n) {
			case 0:   Linea("Miguel O'hara", 2, true, "Elegiste a Miguel O'hara", 40); return true;
			case 1:   Linea("Miguel O'hara", 2, true, "Te sentiste mas identificado con su historia", 40); return true;
			case 2:   Linea("Miguel O'hara", 2, true, "Te gusta tener el control sobre tus problemas y diversas situaciones", 40); return true;
			case 3:   Linea("Miguel O'hara", 2, true, "Cuando algo se vuelve complicado no asumes riesgos importantes", 40); return true;
			case 4:   Linea("Miguel O'hara", 2, true, "Eres precavido y siempre buscas lo mejor para todos", 40); return true;
			default: return false;
			}
		}
		bool DialogoFinalPunk(int n) {
			switch (n) {
			case 0:   Linea("Spider Punk", 3, true, "Elegiste a Spider Punk", 40); return true;
			case 1:   Linea("Spider Punk", 3, true, "Te sentiste mas identificado con su historia", 40); return true;
			case 2:   Linea("Spider Punk", 3, true, "Te tomas las cosas con calma y eres de mente abierta", 40); return true;
			case 3:   Linea("Spider Punk", 3, true, "No calificas a las personas como buena o mala y buscas entenderlas antes de juzgar", 40); return true;
			case 4:   Linea("Spider Punk", 3, true, "Eres una persona con espiritu rebelde y buscas varias soluciones ante un problema", 40); return true;
			default: return false;
			}
		}
		bool DialogoFinalNivel3(int n) {
			switch (n) {
			case 0:   Linea("Spider Punk", 3, true, "Te he vencido spot, no tienes escapatoria", 40); return true;
			case 1:   Linea("The Spot", 5, false, "Tal vez ganaste esta vez, pero eso no evitara mis planes, matare al padre de Miles para vengarme", 40); return true;
			case 2:   Linea("Spider Punk", 3, true, "No lo haras, yo ayudare a Miles, protegere a su padre", 40); return true;
			case 3:   Linea("The Spot", 5, true, "Romperas el canon? pondras en riesgo todo el spider verso", 40); return true;
			case 4:   Linea("Spider Punk", 3, true, "No, me encargare de que su padre renuncie a su puesto de oficial, asi no se rompera el evento canonico", 40); return true;
			case 5:   Linea("The Spot", 5, true, "No se me hubiese ocurrido antes, una solucion tan simple", 40); return true;
			case 6:   Linea("The Spot", 5, true, "Y como piensas llegar a su multiverso", 40); return true;
			case 7:   Linea("The Spot", 5, true, "Con las piezas que recolecte, arme mi herramienta para cambiar de multiverso", 40); return true;
			case 8:   Linea("The Spot", 5, true, "Bueno, supongo que eso es todo, ya no tengo nada mas que hacer", 40); return true;
			default: return false;
			}
		}
		// =========================================================

		void AlClick(Object^ sender, EventArgs^ e) { Avanzar(); }
		void Avanzar() {
			if (!activo) return;
			if (visibles < textoEnvuelto->Length) {
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
			case 1:  return Color::FromArgb(220, 40, 70);
			case 2:  return Color::FromArgb(210, 30, 30);
			case 3:  return Color::FromArgb(235, 60, 60);
			case 4:  return Color::FromArgb(255, 105, 180);
			case 5:  return Color::FromArgb(235, 235, 235);
			case 6:  return Color::FromArgb(0, 200, 170);
			case 7:  return Color::FromArgb(255, 200, 40);
			case 8:  return Color::FromArgb(150, 110, 255);
			case 9:  return Color::FromArgb(255, 150, 170);
			case 10: return Color::FromArgb(60, 140, 255);
			case 11: return Color::FromArgb(140, 140, 150);
			case 12: return Color::FromArgb(255, 200, 40);
			default: return Color::FromArgb(255, 128, 0);
			}
		}
		Bitmap^ BmpDe(int perfil) {
			switch (perfil) {
			case 1:  return bmpMiles;
			case 2:  return bmpMiguel;
			case 3:  return bmpPunk;
			case 4:  return bmpGwen;
			case 5:  return bmpSpot;
			case 6:  return bmpMargo;
			case 7:  return bmpWoman;
			case 8:  return bmpPeny;
			case 9:  return bmpPeter;
			case 10: return bmpPavitr;
			case 11: return bmpNoir;
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
				SolidBrush^ brFondo = gcnew SolidBrush(Color::FromArgb(120, 120, 150));
				g->FillRectangle(brFondo, marco);
				Bitmap^ bmp = BmpDe(perfilActual);
				if (bmp != nullptr) {
					System::Drawing::Rectangle recorte = System::Drawing::Rectangle(12, 0, 40, 40);
					if (perfilActual == 8) recorte = System::Drawing::Rectangle(140, 45, 190, 190);
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