#pragma once
#include "Entidades.h"

using namespace System::Drawing;

class ProyectilHorizontal : public Entidad {
protected:
    int idX;
public:
    ProyectilHorizontal(int x1, int y1, int velocidad,int ancho, int alto): Entidad(x1, y1, velocidad, alto, ancho, true) {
        dy = 0;

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
        y += dy;
    }
    bool EsVertical() {return dx == 0 && dy != 0;}
    Rectangle CrearRectangle() {
        if (EsVertical()) {
            return Rectangle(x, y, anchura, altura * 2);
        }
        return Rectangle(x, y, anchura, altura);
    }

    void Dibujar(Graphics^ g, Bitmap^ bmp, int idX, int idY) {

        int anchoSprite = bmp->Width / 2;
        int altoSprite = bmp->Height;
        if (EsVertical()) { // claude IA
            // El fotograma 1 del sprite apunta a la derecha; girado 90 grados
            // (sentido horario) apunta hacia abajo.
            Rectangle fotograma = Rectangle(1 * anchoSprite, 0, anchoSprite, altoSprite);

            int largo = anchura * 2;   // largo del misil antes de girar
            int grosor = altura;       // grosor del misil
            float cx = x + grosor / 2.0f;   // centro del recuadro ya girado (grosor x largo)
            float cy = y + largo / 2.0f;

            System::Drawing::Drawing2D::GraphicsState^ estado = g->Save();
            g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
            g->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::Half;
            g->TranslateTransform(cx, cy);
            g->RotateTransform(dy > 0 ? 90.0f : -90.0f);   // cae: 90 / sube: -90

            Rectangle destino = Rectangle(-largo / 2, -grosor / 2, largo, grosor);
            g->DrawImage(bmp, destino, fotograma, GraphicsUnit::Pixel);

            g->Restore(estado);   // devuelve la transformacion y la interpolacion como estaban
            return;
        }
        Rectangle sectionshow = Rectangle(idX * anchoSprite, idY * altoSprite, anchoSprite, altoSprite);
            Rectangle zoom = Rectangle(x, y, anchura * 2, altura * 1);
        g->DrawImage(bmp, zoom, sectionshow, GraphicsUnit::Pixel);
    }

    int GetIdX() { return idX;}
};