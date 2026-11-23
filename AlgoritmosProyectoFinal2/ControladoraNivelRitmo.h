#pragma once
#include <vector>
#include "Obstaculos.h"
#include "Objeto.h"
#include "Notas.h"
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Media;

class ControladoraNivelRitmo {
private:
    vector<Obstaculos*> obstaculos;
    vector<Objeto*> objetos;
    vector<Notas*> notas;
    int puntaje = 0;
    int vida = 20;
    int fallos = 0;   // notas que se escaparon sin tocarse (NivelRitmo lo lee para sonar el "fallo")
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
                    fallos++;
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
    // Devuelve: 0 = no habia ninguna nota al alcance, 1 = acierto, 2 = tecla equivocada
    int GolpearNota(Rectangle hitboxPunk, char tecla) {
        SoundPlayer^ pum; // Claude IA  // el ^ "hat" es un tipo de puntero/vector del CRL.net / no necesita de un delete[]
        SoundPlayer^ pam;
        String^ rutapum = "Sonidos/pum.wav";
        String^ rutapam = "Sonidos/pam.wav";
        try { pum = gcnew SoundPlayer(rutapum); pum->Load(); } // (...) Atrapa cualquier tipo de excepci?n
        catch (...) { pum = nullptr; } // si falta el archivo, no rompe el juego
        try { pam = gcnew SoundPlayer(rutapam); pam->Load(); }
        catch (...) { pam = nullptr; }
        int resultado = 0;
        int n = -1;
        SoundPlayer^ pu;
        switch (tecla) {
        case 'B': n = 0; pu = pam; break;
        case 'N': n = 1; pu = pum; break;
            //case 'M': n = 2; break;
        default: break;
        }
        for (int i = 0; i < (int)notas.size(); i++) {
            if (notas[i]->GetVivo() && notas[i]->GetRectangulo().IntersectsWith(hitboxPunk)) {
                if (notas[i]->GetTipo() == n) {
                    puntaje++;
                    if (resultado != 2) resultado = 1;
                    if (pu != nullptr) { pu->Play(); }
                    else { SystemSounds::Beep->Play(); }
                }
                else {
                    puntaje--;
                    resultado = 2;
                }
                notas[i]->SetVivo(false);
            }
        }
        return resultado;
    }

    // Devuelve cuantas notas se escaparon desde la ultima vez que se llamo y reinicia el contador
    int ConsumirFallos() {
        int f = fallos;
        fallos = 0;
        return f;
    }

    /*void DibujarTeclas(Graphics^ g, System::Drawing::Font^ fuente, System::Drawing::StringFormat^ formato) {
        for (int i = 0; i < (int)notas.size(); i++) {
            if (!notas[i]->GetVivo()) continue;
            System::String^ letra;
            switch (notas[i]->GetTipo()) {
            case 0: letra = "B"; break;
            case 1: letra = "N"; break;
            default: letra = "M"; break;
            }
            Rectangle r = notas[i]->GetRectangulo();
            System::Drawing::RectangleF cuadro((float)r.X, (float)r.Y, (float)r.Width, (float)r.Height);
            System::Drawing::RectangleF sombra(cuadro.X + 2.0f, cuadro.Y + 2.0f, cuadro.Width, cuadro.Height);
            g->DrawString(letra, fuente, System::Drawing::Brushes::Black, sombra, formato);
            g->DrawString(letra, fuente, System::Drawing::Brushes::White, cuadro, formato);
        }
    }
    */
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
