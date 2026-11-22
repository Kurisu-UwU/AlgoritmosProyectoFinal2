#pragma once
#include "Obstaculos.h"
#include "Protagonistas.h"
#include <vector>

using namespace System::Drawing;

class Perseguidor : public Entidad {
protected:
    int idX, idY;
    char orientacion;
public:

    Perseguidor(int x1, int y1, int velocidad,
        int alto, int ancho, bool exis)
        : Entidad(x1, y1, velocidad, alto, ancho, exis) {
        idX = idY = 0;
    }

    ~Perseguidor() { }

    void Dibujar(Graphics^ g, Bitmap^ bmp) {
        System::Drawing::Rectangle sectionshow = System::Drawing::Rectangle(idX * anchura, idY * altura, anchura, altura);
        System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, anchura * 1.0, altura * 1.0);
        g->DrawImage(bmp, zoom, sectionshow, GraphicsUnit::Pixel);
    }

    void Perseguir(Protagonista* protagonista, vector<Obstaculos*> obstaculos) {

        if (!existencia) {
            return;
        }

        int movX = 0;
        int movY = 0;

        if (protagonista->GetPX() > x) {
            movX = dx; idY = 6;
        }
        else if (protagonista->GetPX() < x) {
            movX = -dx; idY = 7;
        }

        if (protagonista->GetPY() > y) {
            movY = dx; idY = 4;
        }
        else if (protagonista->GetPY() < y) {
            movY = -dx; idY = 5;
        }

        if (movY != 0) {
            Rectangle rectY(x, y + movY, anchura, altura);
            bool puedeMoverY = true;

            for (int i = 0; i < obstaculos.size(); i++) {
                if (obstaculos[i]->CrearRectangle().IntersectsWith(rectY)) {
                    puedeMoverY = false;
                    break;
                }
            }

            if (puedeMoverY)
                y += movY; idX++;
            if (idX >= 16) { idX = 0; }
        }

        if (movX != 0) {
            Rectangle rectX(x + movX, y, anchura, altura);
            bool puedeMoverX = true;

            for (int i = 0; i < obstaculos.size(); i++) {
                if (obstaculos[i]->CrearRectangle().IntersectsWith(rectX)) {
                    puedeMoverX = false;
                    break;
                }
            }

            if (puedeMoverX)
                x += movX; idX++;
            if (idX >= 16) { idX = 0; }
        }

    }

    Rectangle CrearRectangle() {
        return Rectangle(x, y, anchura, altura);
    }
};