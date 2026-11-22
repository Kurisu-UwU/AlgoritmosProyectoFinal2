#pragma once
#include "Proyectiles.h"
class Notas : public Proyectiles {
private:
	short tipo;
	bool vivo;
	int velocidad;
	int width, height;
	int idX, idY;
public:
	Notas(int, int, int, int);
	~Notas();
	
	void SetVivo(bool viv) { vivo = viv; }
	void SetTipo(short tip) { tipo = tip; }

	bool PresionarNotas(int);
	void Dibujar(Graphics^ g, Bitmap^ bmp, Bitmap^ bmp2, Bitmap^ bmp3) override {
		Rectangle sectionShow = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width, height);
		if (this->tipo == 0) { g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel); }
		if (this->tipo == 1) { g->DrawImage(bmp2, zoom, sectionShow, GraphicsUnit::Pixel); }
		if (this->tipo == 2) { g->DrawImage(bmp3, zoom, sectionShow, GraphicsUnit::Pixel); }

	}

	bool GetVivo() { return vivo; }
	short GetTipo() { return tipo; }
	Rectangle GetRectangulo() { return Rectangle(x, y, width, height); }
};
Notas::Notas(int wid, int hei, int tip, int pos) : Proyectiles() {
	x = 1000; y = pos; vivo = false; tipo = tip;
	width = wid;
	height = hei;
	idX = 0; idY = 0;
	
}
Notas::~Notas() {}