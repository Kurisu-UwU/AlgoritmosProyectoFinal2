#pragma once
#include "Protagonistas.h"

#define DURACION_INVISIBLE 150
#define RECARGA_INVISIBLE 300
#define FRAMES_INMUNIDAD 60

class MilesMorales : public Protagonista {
private:
	bool esInsisible;
	int tiempoInvisible, recargaInvisibilidad, tiempoInmunidad;
public:
	MilesMorales() {}
	MilesMorales(int x1, int y1, int anch, int alt, float e1, float vx1, float vy1, float a1, float vi1, float car, string n1, char mira, int idx, int idy) : Protagonista() {
		x = x1;
		y = y1;
		energia = e1;
		dx = vx1;
		dy = vy1;
		ataque = a1;
		vida = vi1;
		carga = car;
		nombre = n1;
		direccion = mira;
		ancho = anch;
		alto = alt;
		idX = idx;
		idY = idy;
		esInsisible = false;
		tiempoInvisible = 0;
		recargaInvisibilidad = 0;
		tiempoInmunidad = 0;
	};
	~MilesMorales() {}
	void SetInvisibilidad(bool invisibilidad) { esInsisible = invisibilidad; }
	bool GetInvisibilidad() { return esInsisible; }

	int GetTiempoInvisible() { return tiempoInvisible; }
	int GetRecargaInvisibilidad() { return recargaInvisibilidad; }
	int GetTiempoInmunidad() { return tiempoInmunidad; }
	bool EstaInmune() { return tiempoInmunidad > 0; }

	void ActivarInvisibilidad() {
		if (!esInsisible && recargaInvisibilidad == 0) {
			esInsisible = true;
			tiempoInvisible = DURACION_INVISIBLE;
		}
	}
	void ActualizarEstados() {
		if (esInsisible) {
			tiempoInvisible--;
			if (tiempoInvisible <= 0) {
				esInsisible = false;
				recargaInvisibilidad = RECARGA_INVISIBLE;
			}
		}
		else if (recargaInvisibilidad > 0) {
			recargaInvisibilidad--;
		}
		if (tiempoInmunidad > 0) tiempoInmunidad--;
	}
	void RecibirDanio(int danio) {
		if (tiempoInmunidad > 0 || esInsisible) return;
		vida -= danio;
		if (vida < 0) vida = 0;
		tiempoInmunidad = FRAMES_INMUNIDAD;
	}
	void Reaparecer() {
		vida = 100;
		esInsisible = false;
		tiempoInvisible = 0;
		tiempoInmunidad = FRAMES_INMUNIDAD;
	}
};