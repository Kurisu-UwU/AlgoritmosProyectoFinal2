#pragma once
#include "Perseguidor.h"
#include <vector>

using namespace std;
using namespace System::Drawing;

class Jefe : public Perseguidor {
private:
    int contador;
    int intervalo;
    int esquinaActual;

public:

    Jefe(int x, int y, int velocidad,
        int alto, int ancho, bool existencia, int intervalo1)
        : Perseguidor(x, y, velocidad, alto, ancho, existencia) {

        contador = 0;
        intervalo = intervalo1;
        esquinaActual = -1;
    }

    void Teletransportar(int anchoMapa, int altoMapa,
        const vector<Obstaculos*>& obstaculos) {

        int esquinas[4][2] = {
            {0, 0},
            {anchoMapa - anchura, 0},
            {0, altoMapa - altura},
            {anchoMapa - anchura, altoMapa - altura}
        };

        for (int i = 0; i < 4; i++) {

            int siguiente = (esquinaActual + i + 1) % 4;

            int nuevaX = esquinas[siguiente][0];
            int nuevaY = esquinas[siguiente][1];

            Rectangle rectJefe(nuevaX, nuevaY, anchura, altura);

            bool puedeTeletransportarse = true;

            for (int j = 0; j < obstaculos.size(); j++) {

                if (obstaculos[j] != nullptr &&
                    obstaculos[j]->CrearRectangle().IntersectsWith(rectJefe)) {

                    puedeTeletransportarse = false;
                    break;
                }
            }

            if (puedeTeletransportarse) {
                x = nuevaX;
                y = nuevaY;
                esquinaActual = siguiente;
                return;
            }
        }
    }

    void Actualizar(Protagonista* protagonista,
        int anchoMapa, int altoMapa,
        const vector<Obstaculos*>& obstaculos) {

        if (!existencia) {
            return;
        }

        contador++;

        if (contador >= intervalo) {

            contador = 0;

            int xAnterior = x;
            int yAnterior = y;

            Teletransportar(anchoMapa, altoMapa, obstaculos);

            if (x != xAnterior || y != yAnterior)
                return;
        }

        Perseguir(protagonista, obstaculos);
    }
};