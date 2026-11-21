#pragma once
#include <vector>
#include "Obstaculos.h"
using namespace std;
class Controladora {
private:
	vector<Obstaculos*> obstaculos;
public:
	Controladora() {}
	~Controladora() {}

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

			Rectangle rectObstaculo =
				obstaculos[i]->CrearRectangle();

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
};
