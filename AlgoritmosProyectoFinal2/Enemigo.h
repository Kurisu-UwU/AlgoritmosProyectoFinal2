#pragma once
#include "Entidades.h"

class Enemigo : public Entidad {
private:
    int limiteIzquierdo;
    int limiteDerecho;
    int sentido;

public:
    Enemigo(int x1, int y1, int velocidad,
        int alto, int ancho, bool exis,
        int limiteI, int limiteD)
        : Entidad(x1, y1, velocidad, alto, ancho, exis) {

        limiteIzquierdo = limiteI;
        limiteDerecho = limiteD;
        sentido = 1;
    }

    void Mover() {

        if (!existencia) {
            return;
        }

        x += dx * sentido;

        if (x + anchura >= limiteDerecho) {
            x = limiteDerecho - anchura;
            sentido = -1;
        }

        if (x <= limiteIzquierdo) {
            x = limiteIzquierdo;
            sentido = 1;
        }
    }

    
};