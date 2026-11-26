#pragma once
#include <vector>
#include <cstdlib>
#include "Carro.h"
#include "MiguelOhara.h"

using namespace std;
using namespace System::Drawing;

// Estados de la persecucion
#define PERSE_ESPERA 0
#define PERSE_CORRIENDO 1
#define PERSE_GANO 2
#define PERSE_PERDIO 3

#define ANCHO_PANEL 1215
#define ALTO_PANEL 682
#define CARRETERA_Y 221        
#define CARRIL_ALTO 61
#define NUM_CARRILES 4
#define VEL_CARRETERA 8       
#define VEL_MILES_X 6
#define VEL_MILES_Y 7
#define MILES_X_MIN 300
#define MILES_X_MAX 850
#define MILES_Y_MIN 215
#define MILES_Y_MAX 417
#define MILES_X_INICIAL 420
#define MILES_Y_INICIAL 300
#define DANO_CARRO 20           
#define FRAMES_META 1500         
#define MS_POR_FRAME 30
#define MIGUEL_X_INICIAL 30
#define MIGUEL_X_MAX 255

class ControladoraPersecucion {
private:
	vector<Carro*> carros;
	MiguelOhara* miguel;
	float mx, my;
	int estado, frames, scroll, esperaSpawn, ultimoCarril, parpadeo, animMiguel;

	int Limitar(int v, int minimo, int maximo) {
		if (v < minimo) return minimo;
		if (v > maximo) return maximo;
		return v;
	}
	int AnchoTipo(int t) {
		switch (t) { case 0: return 130; case 1: return 165; case 2: return 165; default: return 150; }
	}
	int AltoTipo(int t) {  
		switch (t) { case 0: return 78; case 1: return 99; case 2: return 94; default: return 57; }
	}
	int VelocidadCarril(int c) { 
		switch (c) {
		case 0: return VEL_CARRETERA + 6; case 1: return VEL_CARRETERA + 10;
		case 2: return VEL_CARRETERA + 4; default: return VEL_CARRETERA + 8;
		}
	}
	Rectangle HitboxMiles(Protagonista* miles) {
		Rectangle r = miles->CrearRectangle();
		r.Inflate(-10, -6);
		return r;
	}
	void LimpiarCarros() {
		for (int i = 0; i < (int)carros.size(); i++) delete carros[i];
		carros.clear();
	}

public:
	ControladoraPersecucion() {
		miguel = new MiguelOhara(MIGUEL_X_INICIAL, MILES_Y_INICIAL, 64, 64, 100, 0, 0, 100, 100, 0, "Miguel", 'D', 0, 6);
		miguel->SetCaminando(true);
		estado = PERSE_ESPERA; frames = 0; scroll = 0; esperaSpawn = 40; ultimoCarril = -1;
		parpadeo = 0; animMiguel = 0; mx = MIGUEL_X_INICIAL; my = MILES_Y_INICIAL;
	}
	~ControladoraPersecucion() {
		LimpiarCarros();
		delete miguel;
	}
	void Iniciar(Protagonista* miles) {
		LimpiarCarros();
		estado = PERSE_ESPERA; frames = 0; scroll = 0; esperaSpawn = 40; ultimoCarril = -1;
		parpadeo = 0; animMiguel = 0;
		mx = MIGUEL_X_INICIAL; my = MILES_Y_INICIAL;
		miguel->SetPX((int)mx); miguel->SetPY((int)my);
		miguel->SetIdY(6);
		miles->SetPX(MILES_X_INICIAL); miles->SetPY(MILES_Y_INICIAL);
		miles->SetVida(100);
		miles->SetMirada('D');
		miles->SetCaminando(true);
		miles->SetIdY(6);     
	}
	void Comenzar() { if (estado == PERSE_ESPERA) estado = PERSE_CORRIENDO; }
	void MoverMiles(Protagonista* miles, bool w, bool a, bool s, bool d) {
		if (estado != PERSE_CORRIENDO) return;
		int x = miles->GetPX(), y = miles->GetPY();
		if (w) y -= VEL_MILES_Y;
		if (s) y += VEL_MILES_Y;
		if (a) x -= VEL_MILES_X;
		if (d) x += VEL_MILES_X;
		miles->SetPX(Limitar(x, MILES_X_MIN, MILES_X_MAX));
		miles->SetPY(Limitar(y, MILES_Y_MIN, MILES_Y_MAX));
		miles->SetIdY(6);
	}
	void GenerarCarro() {
		int carril, intentos = 0;
		do { carril = rand() % NUM_CARRILES; intentos++; } while (carril == ultimoCarril && intentos < 10);


		int enZona = 0;
		for (int i = 0; i < (int)carros.size(); i++)
			if (carros[i]->GetX() > ANCHO_PANEL - 450) enZona++;
		if (enZona >= 2) return;

		int tipo = rand() % 4;
		bool hayOxidado = false;
		for (int i = 0; i < (int)carros.size(); i++) {
			if (carros[i]->GetCarril() != carril) continue;
			if (carros[i]->GetX() + carros[i]->GetAncho() > ANCHO_PANEL - 350) return;   // carril ocupado
			if (carros[i]->GetTipo() == 3) hayOxidado = true;
		}
		if (hayOxidado && tipo != 3) return;     

		int ancho = AnchoTipo(tipo), alto = AltoTipo(tipo);
		int velocidad = (tipo == 3) ? VEL_CARRETERA : VelocidadCarril(carril);   // el oxidado se ve "parado"
		int y = CARRETERA_Y + carril * CARRIL_ALTO + CARRIL_ALTO / 2 - alto / 2;
		carros.push_back(new Carro(ANCHO_PANEL + 10, y, velocidad, alto, ancho, tipo, carril));
		ultimoCarril = carril;
	}
	void Actualizar(Protagonista* miles) {
		if (estado == PERSE_ESPERA) return;
		if (estado == PERSE_CORRIENDO) {
			frames++;
			scroll += VEL_CARRETERA;
			if (parpadeo > 0) parpadeo--;

			esperaSpawn--;
			if (esperaSpawn <= 0) {
				GenerarCarro();
				int base = 34 - (16 * frames) / FRAMES_META;   // cada vez salen mas seguido
				esperaSpawn = base + rand() % 10;
			}

			Rectangle rm = HitboxMiles(miles);
			for (int i = 0; i < (int)carros.size(); i++) {
				carros[i]->Mover();
				if (!carros[i]->GetYaGolpeo() && carros[i]->CrearRectangle().IntersectsWith(rm)) {
					float vida = miles->GetVida() - DANO_CARRO;
					if (vida < 0) vida = 0;
					miles->SetVida(vida);
					carros[i]->SetYaGolpeo(true);
					parpadeo = 30;
				}
				if (!carros[i]->GetExistencia()) {
					delete carros[i];
					carros.erase(carros.begin() + i);
					i--;
				}
			}
			if (miles->GetVida() <= 0) estado = PERSE_PERDIO;
			else if (frames >= FRAMES_META) estado = PERSE_GANO;
		}
		MoverMiguel(miles);
	}
	void MoverMiguel(Protagonista* miles) {
		float objetivoX;
		if (estado == PERSE_PERDIO) {
			objetivoX = (float)miles->GetPX() - 40;          // te alcanza
		}
		else {
			float perdida = (100.0f - miles->GetVida()) / 100.0f;   // mas vida perdida = mas cerca
			if (perdida < 0) perdida = 0;
			if (perdida > 1) perdida = 1;
			objetivoX = MIGUEL_X_INICIAL + (MIGUEL_X_MAX - MIGUEL_X_INICIAL) * perdida;
		}
		float suavizado = (estado == PERSE_PERDIO) ? 0.2f : 0.08f;
		mx += (objetivoX - mx) * suavizado;
		my += ((float)miles->GetPY() - my) * 0.12f;
		miguel->SetPX((int)mx);
		miguel->SetPY((int)my);
		miguel->SetIdY(6);
		animMiguel++;
		if (animMiguel % 3 == 0) miguel->ProtaAnimacion();
	}
	// ---------- datos para el HUD ----------
	int GetEstado() { return estado; }
	int GetLejania(Protagonista* miles) {          // distancia Miguel-Miles en "metros"
		int hueco = miles->GetPX() - ((int)mx + 40);
		if (hueco < 0) hueco = 0;
		return hueco / 6;
	}
	int GetSegundosRestantes() {
		int restantes = FRAMES_META - frames;
		if (restantes < 0) restantes = 0;
		return (restantes * MS_POR_FRAME + 999) / 1000;
	}
	// ---------- dibujo ----------
	void DibujarFondo(Graphics^ g, Bitmap^ fondo) {   // fondo ya escalado al alto del panel
		int AP = ANCHO_PANEL, HP = ALTO_PANEL;
		int total = fondo->Width;
		int desde = scroll % total;
		int w1 = total - desde;
		if (w1 >= AP) {
			g->DrawImage(fondo, Rectangle(0, 0, AP, HP), desde, 0, AP, HP, GraphicsUnit::Pixel);
		}
		else {   // el mapa da la vuelta: se dibuja el final y luego el principio
			g->DrawImage(fondo, Rectangle(0, 0, w1, HP), desde, 0, w1, HP, GraphicsUnit::Pixel);
			g->DrawImage(fondo, Rectangle(w1, 0, AP - w1, HP), 0, 0, AP - w1, HP, GraphicsUnit::Pixel);
		}
	}
	void Dibujar(Graphics^ g, Bitmap^ fondo, cli::array<Bitmap^>^ bmpCarros, Bitmap^ bmpMiguel, Protagonista* miles, Bitmap^ bmpMiles) {
		DibujarFondo(g, fondo);
		int pies = miles->GetPY() + 48;
		// 1) coches que quedan "detras" de Miles (su suelo esta mas arriba)
		for (int i = 0; i < (int)carros.size(); i++)
			if (carros[i]->GetY() + carros[i]->GetAlto() * 0.8 <= pies)
				carros[i]->Dibujar(g, bmpCarros[carros[i]->GetTipo()]);
		// 2) Miguel y Miles (Miles parpadea un momento despues de un golpe)
		miguel->Dibujar(g, bmpMiguel);
		if (!(parpadeo > 0 && (parpadeo / 3) % 2 == 0)) miles->Dibujar(g, bmpMiles);
		// 3) coches que pasan "delante" de Miles
		for (int i = 0; i < (int)carros.size(); i++)
			if (carros[i]->GetY() + carros[i]->GetAlto() * 0.8 > pies)
				carros[i]->Dibujar(g, bmpCarros[carros[i]->GetTipo()]);
	}
	void DibujarHitboxes(Graphics^ g, Protagonista* miles) {
		for (int k = 0; k <= NUM_CARRILES; k++)
			g->DrawLine(Pens::Yellow, 0, CARRETERA_Y + k * CARRIL_ALTO, (int)ANCHO_PANEL, CARRETERA_Y + k * CARRIL_ALTO);
		for (int i = 0; i < (int)carros.size(); i++)
			g->DrawRectangle(Pens::Red, carros[i]->CrearRectangle());
		g->DrawRectangle(Pens::Lime, HitboxMiles(miles));
	}
};