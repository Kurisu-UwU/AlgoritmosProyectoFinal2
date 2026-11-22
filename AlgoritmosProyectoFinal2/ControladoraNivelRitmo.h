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
public:
    ControladoraNivelRitmo() {}
    ~ControladoraNivelRitmo() {
        LimpiarObstaculos();
        LimpiarObjetos();
        LimpiarNotas();
    }
    vector<Obstaculos*> GetObstaculos() { return obstaculos; }
    vector<Objeto*> GetObjetos() { return objetos; }
    // =========================
    // METODOS DE OBSTACULOS
    // =========================
    void TamboresMovimiento(int posparatocar, Bitmap^ bmp1, Bitmap^ bmp2, Bitmap^ bmp3, Graphics^ gr) {
        for (int i = 0; i < (int)notas.size(); i++) {
            if (notas[i]->GetVivo()) {
                if (notas[i]->GetX() > posparatocar - 11) { notas[i]->SetX(notas[i]->GetX() - 1); }
                notas[i]->Dibujar(gr, bmp1, bmp2, bmp3);
                if (notas[i]->GetX() < posparatocar - 10) { 
                    notas[i]->SetVivo(false); 
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
        Notas* ene = new Notas(width, height, tipo);
        ene->SetX(100);
        ene->SetY(100);
        ene->SetVivo(true);
        notas.push_back(ene);
    }
    // =========================
    // METODOS DE OBJETOS
    // =========================
    void GenerarObjeto(int x, int y, int velocidad, int ancho, int alto) {
        Objeto* ent = new Objeto(x, y, velocidad, alto, ancho, true);
        objetos.push_back(ent);
    }
    void DibujarObjetos(Graphics^ g, Bitmap^ bmp) {
        for (int i = 0; i < objetos.size(); i++) {
            objetos[i]->Dibujar(g, bmp);
        }
    }
    bool HayColisionObjeto(Protagonista* personaje) {
        for (int i = 0; i < objetos.size(); i++) {
            if (objetos[i]->Colisionar(personaje)) {
                return true;
            }
        }
        return false;
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
