#pragma once
#include <vector>
#include "Obstaculos.h"
#include "Objeto.h"
#include "Notas.h"
using namespace std;

class ControladoraNivelRitmo {
private:
    vector<Obstaculos*> obstaculos;
    vector<Objeto*> objetos;
    vector<Notas*> notas;
    int puntaje = 0;
    int vida = 20;
public:
    ControladoraNivelRitmo() {}
    ~ControladoraNivelRitmo() {
        LimpiarObstaculos();
        LimpiarObjetos();
        LimpiarNotas();
    }
    vector<Obstaculos*> GetObstaculos() { return obstaculos; }
    vector<Objeto*> GetObjetos() { return objetos; }
    int GetPuntaje() { return puntaje; }
    int GetVida() { return vida; }
    // =========================
    // METODOS DE OBSTACULOS
    // =========================
    void TamboresMovimiento(int posparatocar, Bitmap^ bmp1, Bitmap^ bmp2, Bitmap^ bmp3, Graphics^ gr) {
        for (int i = 0; i < (int)notas.size(); i++) {
            if (notas[i]->GetVivo()) {
                if (notas[i]->GetX() > posparatocar - 11) { notas[i]->SetX(notas[i]->GetX() - 5); }
                notas[i]->Dibujar(gr, bmp1, bmp2, bmp3);
                if (notas[i]->GetX() < posparatocar - 10) { 
                    notas[i]->SetVivo(false); 
                    puntaje--;
                }
            }
        }
        for (int i = 0; i < (int)notas.size(); i++) {
            if (notas[i]->GetVivo() == false) {
                delete notas[i];
                notas.erase(notas.begin() + i);
                i--;
            }
        }
    }
    void dibujar_elementos(Graphics^ g, Bitmap^ bmp, Bitmap^ bmp2, Bitmap^ bmp3, int tipo) {
        for (int i = 0; i < notas.size(); i++) {
            if (notas[i]->GetVivo()) { notas[i]->Dibujar(g, bmp, bmp2, bmp3); }
        }
    }
    void CrearNota(int width, int height, int tipo, int posY) {
        int Posyy = 0;
        switch (posY) {
        case 0: Posyy = 350; break;
        case 1: Posyy = 425; break;
        case 2: Posyy = 500; break;
        default: break;
        }
        Notas* ene = new Notas(width, height, tipo, Posyy);
        ene->SetVivo(true);
        notas.push_back(ene);
    }
    // =========================
    // METODOS DE OBJETOS
    // =========================
    void GolpearNota(Rectangle hitboxPunk, char tecla) {
            bool si = false;
            for (int i = 0; i < (int)notas.size(); i++) {
                if (notas[i]->GetVivo() && notas[i]->GetRectangulo().IntersectsWith(hitboxPunk)) {
                    int n;
                    switch (tecla) {
                    case 'B': n = 0; break;
                    case 'N': n = 1; break;
                    case 'M': n = 2; break;
                    }
                    if (notas[i]->GetTipo() == n) {
                        puntaje++;
                    }
                    else { puntaje--; }
                    notas[i]->SetVivo(false);
                }
            }
    }
    void LimpiarObjetos() {
        for (int i = 0; i < objetos.size(); i++) {
            delete objetos[i];
        }
        objetos.clear();
    }
    void LimpiarObstaculos() {
        for (int i = 0; i < obstaculos.size(); i++) {
            delete obstaculos[i];
        }
        obstaculos.clear();
    }
    void LimpiarNotas() {
        for (int i = 0; i < notas.size(); i++) {
            delete notas[i];
        }
        notas.clear();
    }
};
