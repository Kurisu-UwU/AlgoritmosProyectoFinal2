#pragma once
#include "Objeto.h"

class Mancha : public Objeto {
public:
    Mancha(int x, int y, int ancho, int alto)
        : Objeto(x, y, 0, alto, ancho, true) {
    }

    ~Mancha() {}
};