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

	void GenerarObstaculo(int, int, int, int, int);
	void DibujarObstaculos(Graphics^ g) {
		for (int i = 0; i < obstaculos.size(); i++) {
			obstaculos[i]->Dibujar(g);
		}
	}
};
void Controladora::GenerarObstaculo(int x, int y, int velocidad, int ancho, int alto) {  // asignación de atributos a los obstáculos
	Obstaculos* ent = new Obstaculos(x, y, velocidad, ancho, alto, true);
	obstaculos.push_back(ent);
}
