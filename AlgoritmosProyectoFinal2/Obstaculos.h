#pragma once
#include "Entidades.h"
using namespace System::Drawing;
class Obstaculos : public Entidad {
private:
public:
	Obstaculos(int x1, int y1, int dx1, int alto, int ancho, bool owo) : Entidad() {
		x = x1;
		y = y1;
		dx = dx1;
		existencia = owo;
		anchura = ancho;
		altura = alto;
	}
	~Obstaculos() {}
	Rectangle CrearRectangle() {
		if (!existencia) return Rectangle(-1000, -1000, 0, 0);   // obstaculo desactivado (puerta abierta): ya no estorba
		return Rectangle(x, y, anchura, altura);
	}
	void Dibujar(Graphics^ g) {
		if (existencia) g->DrawRectangle(Pens::Red, x, y, anchura, altura);
	}
};