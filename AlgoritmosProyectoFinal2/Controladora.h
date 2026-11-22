#pragma once
#include <vector>
#include "Obstaculos.h"
#include "Objeto.h"
#include "Enemigo.h"
#include "Perseguidor.h"
#include "Jefe.h"

using namespace std;

class Controladora {
private:
    vector<Obstaculos*> obstaculos;
    vector<Objeto*> objetos;
    vector<Enemigo*> enemigos;
    vector<Perseguidor*> seguidores;
    Jefe* jefe;

public:
    Controladora() {}

    ~Controladora() {
        LimpiarObstaculos();
        LimpiarObjetos();
    }

    vector<Obstaculos*> GetObstaculos() { return obstaculos; }
    vector<Objeto*> GetObjetos() { return objetos; }

    // =========================
    // METODOS DE OBSTACULOS
    // =========================

    void DibujarObstaculos(Graphics^ g) {
        for (int i = 0; i < obstaculos.size(); i++) {
            obstaculos[i]->Dibujar(g);
        }
    }

    void GenerarObstaculo(int x, int y, int velocidad, int ancho, int alto) {
        Obstaculos* ent = new Obstaculos(x, y, velocidad, ancho, alto, true);
        obstaculos.push_back(ent);
    }

    bool HayColision(Protagonista* personaje) {
        Rectangle rectPersonaje = personaje->CrearRectangle();

        for (int i = 0; i < obstaculos.size(); i++) {
            Rectangle rectObstaculo = obstaculos[i]->CrearRectangle();

            if (rectPersonaje.IntersectsWith(rectObstaculo)) {
                return true;
            }
        }

        return false;
    }

    void LimpiarObstaculos() {
        for (int i = 0; i < obstaculos.size(); i++) {
            delete obstaculos[i];
        }

        obstaculos.clear();
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

    // =========================
    // METODOS DE PERSEGUIDORES
    // =========================

    void AgregarPerseguidor(Perseguidor* perseguidor) {
        seguidores.push_back(perseguidor);
    }

    void ActualizarPerseguidores(Protagonista* protagonista) {
        for (int i = 0; i < seguidores.size(); i++) {
            seguidores[i]->Perseguir(protagonista, obstaculos);
        }
    }

    void DibujarSeguidores(Graphics^ g, Bitmap^ bmp) {
        for (int i = 0; i < seguidores.size(); i++) {
            seguidores[i]->Dibujar(g, bmp);
        }
    }

    // =========================
    // METODOS DE JEFE
    // =========================

    void DefinirJefe(Jefe* spot) {
        jefe = spot;
    }

    void ActualizarJefes(Protagonista* protagonista, int anchoMapa, int altoMapa) {

        jefe->Actualizar(protagonista, anchoMapa, altoMapa, obstaculos);
    }

    void DibujarJefe(Graphics^ g, Bitmap^ bmp) {
            jefe->Dibujar(g, bmp);
    }

    void LimpiarJefe() {
        if (jefe != nullptr) {
            delete jefe;
        }
    }

    Jefe* getJefe() {
        return jefe;
    }

};