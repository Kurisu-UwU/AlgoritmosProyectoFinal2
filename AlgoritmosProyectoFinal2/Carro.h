#pragma once
#include "Entidades.h"
using namespace System::Drawing;

class Carro : public Entidad {
private:
	int tipo;
	int carril;
	bool yaGolpeo;  
public:
	Carro(int x1, int y1, int velocidad, int alto, int ancho, int tipo1, int carril1)
		: Entidad(x1, y1, velocidad, alto, ancho, true) {
		tipo = tipo1;
		carril = carril1;
		yaGolpeo = false;
	}
	~Carro() {}
	void Mover() {
		x -= dx;                        
		if (x + anchura < -20) existencia = false;
	}
	Rectangle CrearRectangle() {
		return Rectangle(x + (int)(anchura * 0.04), y + (int)(altura * 0.20),
			(int)(anchura * 0.92), (int)(altura * 0.60));
	}
	void Dibujar(Graphics^ g, Bitmap^ bmp) {
		g->DrawImage(bmp, Rectangle(x, y, anchura, altura));
	}

	int GetTipo() { return tipo; }
	int GetCarril() { return carril; }
	bool GetYaGolpeo() { return yaGolpeo; }
	void SetYaGolpeo(bool v) { yaGolpeo = v; }
};
