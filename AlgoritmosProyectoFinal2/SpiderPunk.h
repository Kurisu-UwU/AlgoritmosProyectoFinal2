#pragma once
#include "Protagonistas.h"

class SpiderPunk : public Protagonista {
private:
public:
	SpiderPunk() {}
	SpiderPunk(int x1, int y1, int anch, int alt, float e1, float vx1, float vy1, float a1, float vi1, float car, string n1, char mira, int idx, int idy) : Protagonista() {
		x = x1;
		y = y1;
		energia = e1;
		dx = vx1;
		dy = vy1;
		ataque = a1;
		vida = vi1;
		carga = car;
		nombre = n1;
		direccion = mira;
		ancho = anch;
		alto = alt;
		idX = idx;
		idY = idy;
	};
	~SpiderPunk() {}
	void DibujarRitmo(Graphics^ g, Bitmap^ bmp) {
		System::Drawing::Rectangle sectionshow = System::Drawing::Rectangle(idX * ancho, idY * alto, ancho, alto);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, ancho *1.2, alto *1.2);
		g->DrawImage(bmp, zoom, sectionshow, GraphicsUnit::Pixel);
	}
	void PunkMoverRitmo(Graphics^ g, char i) {
		switch (i) {
		case 'A':
			if (x > 0) {
				idY = 7;
				direccion = 'A';
			}
			break;
		case 'D':
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				idY = 6;
				direccion = 'D';
			}
			break;
		case 'W':
			if (y > 0) {
				idY = 5;
				if (y > 350)
				y -= 75;
				direccion = 'W';
			}
			break;
		case 'S':
			if (y + alto * 1.0 < g->VisibleClipBounds.Height) {
				idY = 4;
				if (y <500)
				y += 75;
				direccion = 'S';
			}
			break;
		}
		idX++;
		if (idX > 15)idX = 0;

	}
};