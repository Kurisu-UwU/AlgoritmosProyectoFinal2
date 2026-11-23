#pragma once
#include "Entidades.h"

using namespace System::Drawing;

class Proyectil : public Entidad {
private:
    int dy;

public:

    Proyectil(int x1, int y1, char direccion)
        : Entidad(x1, y1, 10, 12, 12, true) {

        dy = 0;

        switch (direccion) {
        case 'A': dx = -20; break;
        case 'D': dx = 20; break;
        case 'W': dx = 0; dy = -20; break;
        case 'S': dx = 0; dy = 20; break;
        }
    }

    void Mover() {
        x += dx;
        y += dy;
    }

    void Dibujar(Graphics^ g, Bitmap^ bmp) {

        Rectangle sectionshow =
            Rectangle(0, 0, bmp->Width, bmp->Height);

        Rectangle zoom =
            Rectangle(x, y, anchura * 2, altura * 2);

        g->InterpolationMode =
            System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;

        g->DrawImage(
            bmp,
            zoom,
            sectionshow,
            GraphicsUnit::Pixel
        );
    }

    Rectangle CrearRectangle() {
        return Rectangle(x, y, anchura, altura);
    }
};