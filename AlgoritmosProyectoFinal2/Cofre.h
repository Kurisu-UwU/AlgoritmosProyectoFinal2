#pragma once
#include "Objeto.h"
#include "Protagonistas.h"

class Cofre : public Objeto {
private:
    int id = 0;
    bool abierto = false;
public:
    Cofre(int x1, int y1, int dx1, int alto, int ancho, bool exis)
        : Objeto(x1, y1, dx1, alto, ancho, exis) {
    }
    ~Cofre() {}
    int GetId() { return id; }
    void SetId(int i) { id = i; }
    bool GetAbierto() { return abierto; }
    void SetAbierto(bool a) { abierto = a; }
    void DibujarCofre(Graphics^ g, Bitmap^ bmp, Bitmap^ bmp2) {
        if (existencia) {
            Rectangle destino(x, y, anchura, altura);
            g->DrawImage(bmp, destino);
        }
    }
    bool Colisionar(Protagonista* personaje) override {
        Rectangle rectCofre(x, y, anchura, altura);
        Rectangle rectPersonaje = personaje->CrearRectangle();
        return rectCofre.IntersectsWith(rectPersonaje);
    }
};