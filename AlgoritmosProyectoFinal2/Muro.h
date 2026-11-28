#pragma once
#include "Objeto.h"
#include "Obstaculos.h"

class Muro {
private:
    Objeto* objeto;
    Obstaculos* obstaculo;

public:
    Muro(int x, int y, int velocidad, int alto, int ancho, bool existencia) {
        objeto = new Objeto(x, y, velocidad, alto, ancho, existencia);
        obstaculo = new Obstaculos(x, y, velocidad, alto, ancho, existencia);
    }

    ~Muro() {
        delete objeto;
        delete obstaculo;
    }

    void Dibujar(Graphics^ g, Bitmap^ bmp) {
        objeto->Dibujar(g, bmp);
    }

    Obstaculos* GetObstaculo() {
        return obstaculo;
    }

    Objeto* GetObjeto() {
        return objeto;
    }
};