#pragma once
#include "Perseguidor.h"
#include <vector>

using namespace std;
using namespace System::Drawing;

class Jefe : public Perseguidor {
private:
    int contador;
    int intervaloteletransportacion;
    int esquinaActual;

    bool animandoTeleport = false;
    bool teletransportado = false;

    int contadorAnimacion = 0;
    int velocidadAnimacion = 1;

    int nuevaX, nuevaY;
    int siguienteTeleport;

public:

    Jefe(int x, int y, int velocidad, int alto, int ancho, bool existencia, int intervalo1): Perseguidor(x, y, velocidad, alto, ancho, existencia) {

        contador = 0;
        intervaloteletransportacion = intervalo1;
        esquinaActual = -1;
    }

    void Teletransportar(int anchoMapa, int altoMapa,
        const vector<Obstaculos*>& obstaculos) {

        int esquinas[4][2] = {
            {15, 420},
            {1120, 420},
            {15, 600},
            {1120, 600}
        };

        int siguiente = (esquinaActual + 1) % 4;

        nuevaX = esquinas[siguiente][0];
        nuevaY = esquinas[siguiente][1];

        siguienteTeleport = siguiente;

        idY = 8;
        idX = 0;

        contadorAnimacion = 0;
        animandoTeleport = true;
        teletransportado = false;
    }

    void Actualizar(Protagonista* protagonista,
        int anchoMapa, int altoMapa,
        const vector<Obstaculos*>& obstaculos) {

        if (!existencia) {
            return;
        }

        if (animandoTeleport) {

            contadorAnimacion++;

            if (contadorAnimacion >= velocidadAnimacion) {

                contadorAnimacion = 0;

                if (!teletransportado) {

                    if (idX < 15) {
                        idX++;
                    }
                    else {
                        x = nuevaX;
                        y = nuevaY;

                        teletransportado = true;
                    }
                }

                else {

                    if (idX > 0) {
                        idX--;
                    }
                    else {
                        animandoTeleport = false;
                        teletransportado = false;

                        esquinaActual = siguienteTeleport;
                    }
                }
            }

            return;
        }

        contador++;

        if (contador >= intervaloteletransportacion) {

            contador = 0;

            Teletransportar(anchoMapa, altoMapa, obstaculos);

            if (animandoTeleport) {
                return;
            }
        }

        Perseguir(protagonista, obstaculos);
    }
};