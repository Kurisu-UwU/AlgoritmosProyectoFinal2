#pragma once
#include "Entidades.h"
#include "Protagonistas.h"

using namespace System::Drawing;

class Objeto : public Entidad {
public:

    Objeto(int x1, int y1, int dx1, int alto, int ancho, bool exis)
        : Entidad(x1, y1, dx1, alto, ancho, exis) {
    }

    ~Objeto() { }

    bool Colisionar(Protagonista* personaje) {

        Rectangle rectObjeto = Rectangle(x, y, anchura, altura);

        Rectangle rectPersonaje = personaje->CrearRectangle();

        return rectObjeto.IntersectsWith(rectPersonaje);
    }
};