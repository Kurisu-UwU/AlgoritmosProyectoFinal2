#pragma once
#include "Entidades.h"
#include "Protagonistas.h"
using namespace System::Drawing;

class Puerta : public Entidad {
private:
    int nivelDestino, xDestino, yDestino;
public:
    Puerta(int x1, int y1, int ancho, int alto, int sala, int xd, int yd):Entidad(x1, y1, 0, alto, ancho, true) {
        nivelDestino = sala;
        xDestino = xd;
        yDestino = yd;
    }
    int GetNivelDestino() { return nivelDestino; }
    int GetXDestino() { return xDestino; }
    int GetYDestino() { return yDestino; }

    bool Colisiona(Protagonista* p) {
        return Rectangle(x, y, anchura, altura).IntersectsWith(p->CrearRectangle());
    }
    void Dibujar(Graphics^ g) {
        g->DrawRectangle(Pens::Yellow, x, y, anchura, altura);
    }
};