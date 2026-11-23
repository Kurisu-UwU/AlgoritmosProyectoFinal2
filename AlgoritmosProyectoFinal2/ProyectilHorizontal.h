#pragma once
#include "Entidades.h"

using namespace System::Drawing;

class ProyectilHorizontal : public Entidad {
protected:
    int idX;
public:

    ProyectilHorizontal(int x1, int y1, int velocidad,
        int ancho, int alto)
        : Entidad(x1, y1, velocidad, alto, ancho, true) {

        if (x1 == 1150) {
            dx = -velocidad;
            idX = 0;
        }
        else {
            dx = velocidad;
            idX = 1;
        }
    }

    void Mover() {
        x += dx;
    }

    Rectangle CrearRectangle() {
        return Rectangle(x, y, anchura, altura);
    }

    void Dibujar(Graphics^ g, Bitmap^ bmp, int idX, int idY) {

        int anchoSprite = bmp->Width / 2;
        int altoSprite = bmp->Height;



        Rectangle sectionshow = Rectangle(idX * anchoSprite, idY * altoSprite, anchoSprite, altoSprite);

        Rectangle zoom = Rectangle(x, y, anchura * 2, altura * 1);

        g->DrawImage(bmp, zoom, sectionshow, GraphicsUnit::Pixel);
    }

    int GetIdX() {
        return idX;
    }
};