#pragma once
#include "Perseguidor.h"

class Gwen : public Perseguidor {
private:
    bool GwenPersigue;
public:
    Gwen(int x, int y, int velocidad, int alto, int ancho, bool existencia, int intervalo1) : Perseguidor(x, y, velocidad, alto, ancho, existencia) {
        GwenPersigue = false;
    }
    ~Gwen() {}

    bool GetPersigue() { return GwenPersigue;}
    void SetPersigue(bool persigue) { GwenPersigue = persigue; }
    void Dibujar(Graphics^ g, Bitmap^ bmp) override {
        System::Drawing::Rectangle sectionshow = System::Drawing::Rectangle(0, 0, anchura, altura);
        System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, anchura * 1.0, altura * 1.0);
        g->DrawImage(bmp, zoom, sectionshow, GraphicsUnit::Pixel);
	}
};