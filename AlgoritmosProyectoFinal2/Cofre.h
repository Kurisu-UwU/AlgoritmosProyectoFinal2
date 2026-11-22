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
            Bitmap^ temp;
            if (abierto) temp = bmp2; else temp = bmp;
            g->DrawImage(temp, destino);   // bmp = cerrado, bmp2 = abierto
        }
    }
    bool Colisionar(Protagonista* personaje) override {
        Rectangle rectCofre(x, y, anchura, altura);
        Rectangle rectPersonaje = personaje->CrearRectangle();
        return rectCofre.IntersectsWith(rectPersonaje);
    }
};