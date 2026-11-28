#pragma once
#include "Objeto.h"
#include "Obstaculos.h"
#include "Perseguidor.h"
using namespace System::Drawing;

class PlacaPresion : public Objeto {
private:
    bool activada;
    bool permanente;
    Obstaculos* puerta; 
public:
    PlacaPresion(int x1, int y1, int ancho, int alto, bool perm, Obstaculos* barrera) : Objeto(x1, y1, 0, alto, ancho, true) {
        activada = false;
        permanente = perm;
        puerta = barrera;
    }
    ~PlacaPresion() {}
    bool GetActivada() { return activada; }
    void Actualizar(Perseguidor* enemigo) {
        Rectangle centro = enemigo->CrearRectangle();
        centro.Inflate(-16, -16);
        bool encima = enemigo->GetExistencia() && Rectangle(x, y, anchura, altura).IntersectsWith(centro);
        if (encima) {
            activada = true;
        }
        else if (!permanente) {
            activada = false;
        }
        puerta->SetExsistencia(!activada);
    }
    void DibujarPuerta(Graphics^ g, Bitmap^ cerrada, Bitmap^ abierta) {
        Bitmap^ temp;
        if (activada) temp = abierta; else temp = cerrada;
        g->DrawImage(temp, Rectangle(puerta->GetX(), puerta->GetY(), puerta->GetAncho(), puerta->GetAlto()));
    }
    void DibujarPlaca(Graphics^ g, Bitmap^ sinPresionar, Bitmap^ presionado) {
        Bitmap^ temp;
        if (activada) temp = presionado; else temp = sinPresionar;
        g->DrawImage(temp, Rectangle(x, y, anchura, altura));
    }
    void DibujarHitbox(Graphics^ g) {   // para el modo debug (F2)
        g->DrawRectangle(Pens::Yellow, x, y, anchura, altura);
    }
};