#pragma once
#include <cstdlib>

class NotaAtaque {
private:
	int x, y, dx, dy;
	int tam;
	bool activa;
	bool hostil;
public:
	NotaAtaque(int x1, int y1, int dx1, int dy1) {
		x = x1; y = y1; dx = dx1; dy = dy1;
		tam = 48;
		activa = true;
		hostil = false;
	}
	~NotaAtaque() {}

	void Mover(int anchoMapa, int altoMapa) {
		if (!activa) return;
		x += dx;
		y += dy;
		if (!hostil) {
			if (x + tam < 0 || x > anchoMapa || y + tam < 0 || y > altoMapa) {
				hostil = true;                      
				x = rand() % (anchoMapa - tam);
				y = -tam;
				dx = 0;
				dy = 14;
			}
		}
		else if (y > altoMapa) {
			activa = false;
		}
	}

	bool EstaActiva() { return activa; }
	bool EsHostil() { return hostil; }
	void Desactivar() { activa = false; }

	System::Drawing::Rectangle CrearRectangle() {
		return System::Drawing::Rectangle(x, y, tam, tam);
	}

	void Dibujar(System::Drawing::Graphics^ g, System::Drawing::Bitmap^ bmpAmiga, System::Drawing::Bitmap^ bmpHostil) {
		if (!activa) return;
		if (hostil) g->DrawImage(bmpHostil, x, y, tam, tam);
		else g->DrawImage(bmpAmiga, x, y, tam, tam);
	}
};
