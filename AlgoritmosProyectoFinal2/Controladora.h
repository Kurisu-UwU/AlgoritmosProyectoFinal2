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
#include "Mancha.h"
#include "Muro.h"

using namespace std;

class Controladora {
private:
    bool jefeColisionando;
    vector<Obstaculos*> obstaculos;
    vector<Objeto*> objetos;
    vector<Cofre*> cofres;
    vector<Enemigo*> enemigos;
    vector<Perseguidor*> seguidores;
    vector<Puerta*> puertas;
    vector<Proyectil*> proyectiles;
    vector<Mancha*> manchas;
    Jefe* jefe;
    Mancha* Peny;
    vector<ProyectilHorizontal*> proyectilesHorizontales;
    vector<NotaAtaque*> notasAtaque;
    vector<Muro*> PosteLuz;
    vector<Muro*> Cerca1;
    vector<Muro*> Cerca2;
    vector<Muro*> Conos1;
    vector<Muro*> Conos2;
    int contadorProyectiles;
    int intervaloProyectiles;
    int invulnerabilidad = 0;
    int cooldownAtaque = 0;

public:
    Controladora() {
        jefe = nullptr;
        Peny = nullptr;
        contadorProyectiles = 0;
        intervaloProyectiles = 60;
        srand((unsigned)time(NULL));
        jefeColisionando = false;
    }

    ~Controladora() {
        LimpiarObstaculos();
        LimpiarObjetos();
        LimpiarPuertas();
        LimpiarJefe();
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

    void DibujarHitboxMuros(Graphics^ g) {
        for (int i = 0; i < PosteLuz.size(); i++) {
            PosteLuz[i]->GetObstaculo()->Dibujar(g);
        }
    }

    void GenerarObstaculo(int x, int y, int velocidad, int alto, int ancho) {
        Obstaculos* ent = new Obstaculos(x, y, velocidad, alto, ancho, true);
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

        for (int i = 0; i < PosteLuz.size(); i++) {
            Rectangle rectMuro = PosteLuz[i]->GetObstaculo()->CrearRectangle();

            if (rectPersonaje.IntersectsWith(rectMuro)) {
                return true;
            }
        }

        for (int i = 0; i < Conos1.size(); i++) {
            Rectangle rectMuro = Conos1[i]->GetObstaculo()->CrearRectangle();

            if (rectPersonaje.IntersectsWith(rectMuro)) {
                return true;
            }
        }

        for (int i = 0; i < Conos2.size(); i++) {
            Rectangle rectMuro = Conos2[i]->GetObstaculo()->CrearRectangle();

            if (rectPersonaje.IntersectsWith(rectMuro)) {
                return true;
            }
        }

        for (int i = 0; i < Cerca1.size(); i++) {
            Rectangle rectMuro = Cerca1[i]->GetObstaculo()->CrearRectangle();

            if (rectPersonaje.IntersectsWith(rectMuro)) {
                return true;
            }
        }

        for (int i = 0; i < Cerca2.size(); i++) {
            Rectangle rectMuro = Cerca2[i]->GetObstaculo()->CrearRectangle();

            if (rectPersonaje.IntersectsWith(rectMuro)) {
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

    void ComprobarColisionJefe(Protagonista* protagonista) {

        if (jefe == nullptr || !jefe->GetExistencia()) {
            jefeColisionando = false;
            return;
        }

        if (protagonista->CrearRectangle().IntersectsWith(jefe->CrearRectangle())) {

            if (!jefeColisionando) {

                // Spider Punk recibe daño
                protagonista->SetVida(
                    max(0.0f, protagonista->GetVida() - 10)
                );

                // Spider Punk se teletransporta
                protagonista->SetPX(70);
                protagonista->SetPY(540);

                jefeColisionando = true;
            }
        }
        else {
            jefeColisionando = false;
        }
    }

    // =======
    // Manchas
    // =======
    void GenerarPeny(int x, int y, int ancho, int alto) {
        Mancha* ent = new Mancha(x, y, ancho, alto);
        Peny = ent;
    }

    void AgregarMancha(int x, int y, int ancho, int alto) {
        manchas.push_back(new Mancha(x, y, ancho, alto));
    }

    void DibujarManchas(Graphics^ g, Bitmap^ bmp) {
        for (int i = 0; i < manchas.size(); i++) {
            manchas[i]->Dibujar(g, bmp);
        }
    }

    void DibujarPeny(Graphics^ g, Bitmap^ bmp) {
            Peny->Dibujar(g, bmp);
    }

    // =============
    // Solidos
    // =============

    void AgregarPosteLuz(int x, int y, int ancho, int alto) {
        PosteLuz.push_back(new Muro(x, y, 0, ancho, alto, true));
    }

    void DibujarPosteLuz(Graphics^ g, Bitmap^ bmp) {
        for (int i = 0; i < PosteLuz.size(); i++) {
            PosteLuz[i]->Dibujar(g, bmp);
        }
    }

    void LimpiarPosteLuz() {
        for (int i = 0; i < PosteLuz.size(); i++) {
            delete PosteLuz[i];
        }
        PosteLuz.clear();

        for (int i = 0; i < PosteLuz.size(); i++) {
            delete Conos1[i];
        }
        Conos1.clear();

        for (int i = 0; i < PosteLuz.size(); i++) {
            delete Conos2[i];
        }
        Conos2.clear();

        for (int i = 0; i < PosteLuz.size(); i++) {
            delete Cerca1[i];
        }
        Cerca1.clear();

        for (int i = 0; i < PosteLuz.size(); i++) {
            delete Cerca2[i];
        }
        Cerca2.clear();
    }
    
    void AgregarConos1(int x, int y, int ancho, int alto) {
        Conos1.push_back(new Muro(x, y, 0, ancho, alto, true));
    }

    void DibujarConos1(Graphics^ g, Bitmap^ bmp) {
        for (int i = 0; i < Conos1.size(); i++) {
            Conos1[i]->Dibujar(g, bmp);
        }
    }


    void AgregarConos2(int x, int y, int ancho, int alto) {
        Conos2.push_back(new Muro(x, y, 0, ancho, alto, true));
    }

    void DibujarConos2(Graphics^ g, Bitmap^ bmp) {
        for (int i = 0; i < Conos2.size(); i++) {
            Conos2[i]->Dibujar(g, bmp);
        }
    }

    void AgregarCerca1(int x, int y, int ancho, int alto) {
        Cerca1.push_back(new Muro(x, y, 0, ancho, alto, true));
    }

    void DibujarCerca1(Graphics^ g, Bitmap^ bmp) {
        for (int i = 0; i < Cerca1.size(); i++) {
            Cerca1[i]->Dibujar(g, bmp);
        }
    }

    void AgregarCerca2(int x, int y, int ancho, int alto) {
        Cerca2.push_back(new Muro(x, y, 0, ancho, alto, true));
    }

    void DibujarCerca2(Graphics^ g, Bitmap^ bmp) {
        for (int i = 0; i < Cerca2.size(); i++) {
            Cerca2[i]->Dibujar(g, bmp);
        }
    }

    void DibujarSolidos(Graphics^ g, Bitmap^ bmp1, Bitmap^ bmp2, Bitmap^ bmp3, Bitmap^ bmp4, Bitmap^ bmp5) {
        DibujarPosteLuz(g, bmp1);
        DibujarConos1(g, bmp2);
        DibujarConos2(g, bmp3);
        DibujarCerca1(g, bmp4);
        DibujarCerca2(g, bmp5);
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

        ProyectilHorizontal* nuevo =new ProyectilHorizontal(x, y, 22, 24, 24);
        nuevo->SetVelocidadVertical(0);
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
            Rectangle rectProyectil =proyectilesHorizontales[i]->CrearRectangle();

            if (rectProyectil.IntersectsWith(
                protagonista->CrearRectangle())) {
                protagonista->SetVida(max(0.0f, protagonista->GetVida() - 10));
                proyectilesHorizontales[i]->SetExsistencia(false);
            }

            if (proyectilesHorizontales[i]->GetX() <= 0 ||
                proyectilesHorizontales[i]->GetX() +
                proyectilesHorizontales[i]->GetAncho() >= anchoMapa) {
                proyectilesHorizontales[i]->SetExsistencia(false);
            }

            if (!proyectilesHorizontales[i]->GetExistencia()) {

                delete proyectilesHorizontales[i];
                proyectilesHorizontales.erase(proyectilesHorizontales.begin() + i);
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
                pro->SetVelocidad(0);
                pro->SetVelocidadVertical(20);
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

    // =========
    // Limpiar
    // =========

    void LimpiarProyectiles() {

        for (int i = 0; i < proyectiles.size(); i++) {delete proyectiles[i];}
        proyectiles.clear();
    }
    void LimpiarObjetos() {
        for (int i = 0; i < objetos.size(); i++) {
            delete objetos[i];
        }
        objetos.clear();

        for (int i = 0; i < manchas.size(); i++) {
            delete manchas[i];
        }
        manchas.clear();

        LimpiarCofres();
    }
    void LimpiarCofres() {
        for (int i = 0; i < cofres.size(); i++) {  delete cofres[i]; }
        cofres.clear();
    }
    void LimpiarJefe() {
        if (jefe != nullptr) { delete jefe; jefe = nullptr; }
    }
    void LimpiarPuertas() {
        for (int i = 0; i < puertas.size(); i++) { delete puertas[i]; }
        puertas.clear();
    }
    void LimpiarProyectilesHorizontales() {
        for (int i = 0; i < proyectilesHorizontales.size(); i++) { delete proyectilesHorizontales[i]; }
        proyectilesHorizontales.clear();
    }
    void LimpiarNotasAtaque() {
        for (int i = 0; i < (int)notasAtaque.size(); i++) { delete notasAtaque[i]; }
        notasAtaque.clear();
    }
    Jefe* getJefe() {
        if (jefe != nullptr) {
            return jefe;
        }
    }
};