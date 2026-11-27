#pragma once
#include "Perseguidor.h"

class EnemigoPerseguidor : public Perseguidor {
private:
public:
    EnemigoPerseguidor(int x, int y, int velocidad, int alto, int ancho, bool existencia, int intervalo1) : Perseguidor(x, y, velocidad, alto, ancho, existencia) {
    }
    ~EnemigoPerseguidor() {}

    void Dibujar(Graphics^ g, Bitmap^ bmp) override {
        System::Drawing::Rectangle sectionshow = System::Drawing::Rectangle(0, 0, anchura, altura);
        System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, anchura * 1.0, altura * 1.0);
        g->DrawImage(bmp, zoom, sectionshow, GraphicsUnit::Pixel);
    }
};