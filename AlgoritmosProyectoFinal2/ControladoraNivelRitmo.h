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
    }

    vector<Obstaculos*> GetObstaculos() { return obstaculos; }
    vector<Objeto*> GetObjetos() { return objetos; }

    // =========================
    // METODOS DE OBSTACULOS
    // =========================

    void dibujar_elementos(Graphics^ g, Bitmap^ bmp, Bitmap^ bmp2, Bitmap^ bmp3) {
        for (int i = 0; i < notas.size(); i++)
        {
            notas[i]->Dibujar(g, bmp, bmp2, bmp3);
        }
    }

    void CrearNota(int width, int height, int tipo) {
        Notas* ene = new Notas(width, height, tipo);
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
};