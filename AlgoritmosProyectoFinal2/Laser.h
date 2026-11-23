#pragma once
#include <cstdlib>

class Laser {
private:
	int x, y, dx;
	int ancho, alto;
	int aviso;       
	bool activo;

	void Reiniciar(int anchoMapa, int yMin, int yMax) {
		activo = false;
		aviso = TICKS_AVISO;
		ancho = 160 + rand() % 140;
		alto = 16;
		y = yMin + rand() % (yMax - yMin + 1);
		int velocidad = 18 + rand() % 12;   // px por tick
		if (rand() % 2 == 0) { dx = velocidad;  x = -ancho; }
		else { dx = -velocidad; x = anchoMapa; }
	}
public:
	static const int TICKS_AVISO = 8;

	Laser(int anchoMapa, int yMin, int yMax, int retraso) {
		Reiniciar(anchoMapa, yMin, yMax);
		aviso += retraso;
	}
	~Laser() {}

	void Actualizar(int anchoMapa, int yMin, int yMax) {
		if (!activo) {
			aviso--;
			if (aviso <= 0) { activo = true; }
			return;
		}
		x += dx;
		if ((dx > 0 && x > anchoMapa) || (dx < 0 && x + ancho < 0)) {
			Reiniciar(anchoMapa, yMin, yMax);
		}
	}

	bool EstaActivo() { return activo; }

	System::Drawing::Rectangle CrearRectangle() {
		return System::Drawing::Rectangle(x, y, ancho, alto);
	}

	void Dibujar(System::Drawing::Graphics^ g, int anchoMapa) {
		if (!activo) {
			if (aviso <= TICKS_AVISO && aviso % 2 == 0) {
				int cy = y + alto / 2;
				g->DrawLine(System::Drawing::Pens::OrangeRed, 0, cy, anchoMapa, cy);
				int bx = (dx > 0) ? 0 : anchoMapa - 24;
				g->FillRectangle(System::Drawing::Brushes::OrangeRed, bx, y, 24, alto);
			}
			return;
		}
		g->FillRectangle(System::Drawing::Brushes::Red, x, y, ancho, alto);
		g->FillRectangle(System::Drawing::Brushes::White, x, y + alto / 2 - 2, ancho, 4);
	}
};
