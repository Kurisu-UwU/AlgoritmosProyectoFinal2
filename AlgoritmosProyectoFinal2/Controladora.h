#pragma once
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Obstaculos.h"
#include "Objeto.h"
#include "Enemigo.h"
#include "Perseguidor.h"
#include "Jefe.h"
#include "Puerta.h"
#include "Cofre.h"
#include "Proyectil.h"
#include "ProyectilHorizontal.h"
#include "NotaAtaque.h"

using namespace std;

class Controladora {
private:
    vector<Obstaculos*> obstaculos;
    vector<Objeto*> objetos;
    vector<Cofre*> cofres;
    vector<Enemigo*> enemigos;
    vector<Perseguidor*> seguidores;
    vector<Puerta*> puertas;
    vector<Proyectil*> proyectiles;
    Jefe* jefe;
    vector<ProyectilHorizontal*> proyectilesHorizontales;
    vector<NotaAtaque*> notasAtaque;
    int contadorProyectiles;
    int intervaloProyectiles;
    int invulnerabilidad = 0;
    int cooldownAtaque = 0;

public:
    Controladora() {
        jefe = nullptr;
        contadorProyectiles = 0;
        intervaloProyectiles = 60;
        srand((unsigned)time(NULL));
    }

    ~Controladora() {
        LimpiarObstaculos();
        LimpiarObjetos();
        LimpiarPuertas();
        LimpiarJefe();
        LimpiarNotasAtaque();
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

    void DefinirJefe(Jefe* spot) { jefe = spot; }
    void ActualizarJefes(Protagonista* protagonista, int anchoMapa, int altoMapa) {
        jefe->Actualizar(protagonista, anchoMapa, altoMapa, obstaculos);
    }
    void DibujarJefe(Graphics^ g, Bitmap^ bmp) {
        jefe->Dibujar(g, bmp);
    }

    // =======
    // Puertas 
    // =======

    void GenerarPuerta(int x, int y, int ancho, int alto, int sala, int xd, int yd) {
        puertas.push_back(new Puerta(x, y, ancho, alto, sala, xd, yd));
    }
    void DibujarPuertas(Graphics^ g) {
        for (int i = 0; i < puertas.size(); i++) puertas[i]->Dibujar(g);
    }
    Puerta* PuertaColisionando(Protagonista* p) {
        for (int i = 0; i < puertas.size(); i++)
            if (puertas[i]->Colisiona(p)) return puertas[i];
        return nullptr;
    }

    // ======
    // Cofre
    // ======

    void GenerarCofre(int x, int y, int alto, int ancho, int id, bool abierto) {
        Cofre* c = new Cofre(x, y, 0, alto, ancho, true);
        c->SetId(id);
        c->SetAbierto(abierto);
        cofres.push_back(c);
    }
    void DibujarCofres(Graphics^ g, Bitmap^ cerrado, Bitmap^ abierto) {
        for (int i = 0; i < cofres.size(); i++) cofres[i]->DibujarCofre(g, cerrado, abierto);
    }
    Cofre* CofreColisionando(Protagonista* p) {
        for (int i = 0; i < cofres.size(); i++)
            if (cofres[i]->Colisionar(p)) return cofres[i];
        return nullptr;
    }

    // =========
    // ProyectilMalo
    // =========

    void GenerarProyectilHorizontal() {

        int coordenadas[6][2] = {
            {1150, 450},
            {1150, 520},
            {1150, 590},
            {20, 450},
            {20, 520},
            {20, 590}
        };

        int aleatorio = rand() % 6;

        int x = coordenadas[aleatorio][0];
        int y = coordenadas[aleatorio][1];

        ProyectilHorizontal* nuevo =
            new ProyectilHorizontal(x, y, 8, 24, 24);

        proyectilesHorizontales.push_back(nuevo);
    }

    void ActualizarProyectilesHorizontales(
        Protagonista* protagonista, int anchoMapa) {

        contadorProyectiles++;

        if (contadorProyectiles >= intervaloProyectiles) {

            GenerarProyectilHorizontal();

            contadorProyectiles = 0;
        }

        for (int i = 0; i < proyectilesHorizontales.size(); i++) {

            proyectilesHorizontales[i]->Mover();

            Rectangle rectProyectil =
                proyectilesHorizontales[i]->CrearRectangle();

            if (rectProyectil.IntersectsWith(
                protagonista->CrearRectangle())) {

                protagonista->SetVida(
                    max(0.0f, protagonista->GetVida() - 10)
                );

                proyectilesHorizontales[i]->SetExsistencia(false);
            }

            if (proyectilesHorizontales[i]->GetX() <= 0 ||
                proyectilesHorizontales[i]->GetX() +
                proyectilesHorizontales[i]->GetAncho() >= anchoMapa) {

                proyectilesHorizontales[i]->SetExsistencia(false);
            }

            if (!proyectilesHorizontales[i]->GetExistencia()) {

                delete proyectilesHorizontales[i];

                proyectilesHorizontales.erase(
                    proyectilesHorizontales.begin() + i
                );

                i--;
            }
        }
    }

    void DibujarProyectilesHorizontales(Graphics^ g, Bitmap^ bmp) {

        for (int i = 0; i < proyectilesHorizontales.size(); i++) {

            int idX = proyectilesHorizontales[i]->GetIdX();

            proyectilesHorizontales[i]->Dibujar(g, bmp, idX, 0);
        }
    }

    // =========
    // Proyectil
    // =========

    void Disparar(Protagonista* personaje) {

        int x = personaje->GetPX();
        int y = personaje->GetPY();

        proyectiles.push_back(new Proyectil(x, y, personaje->GetMirada()));
    }

    void ActualizarProyectiles(int ancho, int alto) {

        for (int i = 0; i < proyectiles.size(); i++) {
            proyectiles[i]->Mover();
            Rectangle rectProyectil =proyectiles[i]->CrearRectangle();
            for (int j = 0; j < seguidores.size(); j++) {
                if (seguidores[j]->GetExistencia() &&
                    rectProyectil.IntersectsWith(seguidores[j]->CrearRectangle())) {
                    seguidores[j]->RecibirDanio(5);
                    proyectiles[i]->SetExsistencia(false);
                    break;
                }
            }
            if (jefe != nullptr && jefe->GetExistencia() && 
                proyectiles[i]->GetExistencia() && 
                rectProyectil.IntersectsWith(jefe->CrearRectangle())) {

                jefe->RecibirDanio(5);
                proyectiles[i]->SetExsistencia(false);
            }
            if (!proyectiles[i]->GetExistencia() ||
                proyectiles[i]->GetX() < 0 ||
                proyectiles[i]->GetY() < 0 ||
                proyectiles[i]->GetX() > ancho ||
                proyectiles[i]->GetY() > alto) {

                delete proyectiles[i];
                int random = rand() % 1100;
                ProyectilHorizontal* pro = new ProyectilHorizontal(random, 0, 8, 24, 24);
                pro->SetVelocidad(1);
                proyectilesHorizontales.push_back(pro);
                proyectiles.erase(proyectiles.begin() + i);
                i--;
            }
        }
    }

    void DibujarProyectiles(Graphics^ g, Bitmap^ bmp) {
        for (int i = 0; i < proyectiles.size(); i++) {
            proyectiles[i]->Dibujar(g, bmp);
        }
    }

    // =====
    // Notas
    // =====

    void DibujarNotasAtaque(Graphics^ g, Bitmap^ bmpBueno, Bitmap^ bmpMalo) {

    }

    // =========
    // Limpiar
    // =========

    void LimpiarProyectiles() {

        for (int i = 0; i < proyectiles.size(); i++) {
            delete proyectiles[i];
        }

        proyectiles.clear();
    }

    void LimpiarObjetos() {
        for (int i = 0; i < objetos.size(); i++) {
            delete objetos[i];
        }
        objetos.clear();
        LimpiarCofres();
    }

    void LimpiarCofres() {
        for (int i = 0; i < cofres.size(); i++) {
            delete cofres[i];
        }
        cofres.clear();
    }

    void LimpiarJefe() {
        if (jefe != nullptr) {
            delete jefe; jefe = nullptr;
        }
    }

    void LimpiarPuertas() {
        for (int i = 0; i < puertas.size(); i++) {
            delete puertas[i];
        }
        puertas.clear();
    }

    void LimpiarProyectilesHorizontales() {

        for (int i = 0; i < proyectilesHorizontales.size(); i++) {
            delete proyectilesHorizontales[i];
        }

        proyectilesHorizontales.clear();
    }
    void LimpiarNotasAtaque() {
        for (int i = 0; i < (int)notasAtaque.size(); i++) { delete notasAtaque[i]; }
        notasAtaque.clear();
    }
    Jefe* getJefe() { return jefe; }
};