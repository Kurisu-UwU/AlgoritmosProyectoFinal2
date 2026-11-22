#pragma once
#include "Entidades.h"
#include "Protagonistas.h"

class Objeto : public Entidad {
private: 
public:
    Objeto(int x1, int y1, int dx1, int alto, int ancho, bool exis)
        : Entidad(x1, y1, dx1, alto, ancho, exis) {
    }
    ~Objeto() {}
    void Dibujar(Graphics^ g, Bitmap^ bmp) {
        if (existencia) {
            Rectangle destino(x, y, anchura, altura);
            g->DrawImage(bmp, destino);
        }
    }
    virtual bool Colisionar(Protagonista* personaje) {
        Rectangle rectObjeto(x, y, anchura, altura);
        Rectangle rectPersonaje = personaje->CrearRectangle();
        return rectObjeto.IntersectsWith(rectPersonaje);
    }
};