#pragma once
#include "VariablesGlobales.h"
#include "ControladoraNivelRitmo.h"
inline int NivelesRitmo1(Graphics^ gr, ControladoraNivelRitmo* controladora, int nivel, Bitmap^ bmpNota1, Bitmap^ bmpNota2, Bitmap^ bmpNota3) {
	controladora->dibujar_elementos(gr, bmpNota1, bmpNota2, bmpNota3, nivel);
	int puntaje = 0;
	int vida = 20;
	switch (nivel) {
	case 0: break;
	case 1: {
		controladora->TamboresMovimiento(1, bmpNota1, bmpNota2, bmpNota3, gr);
		switch (tiempo) {
		case 20: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height,0, 1); break;
		case 40: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 60: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1);  break;
		case 90: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1);  break;
		case 100: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 0);  break;
		case 120: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 0);  break;
		case 140: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 0);  break;
		case 170: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1);  break;
		case 180: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1);  break;
		case 400:
			tiempo = 0;
			if (controladora->GetPuntaje() >= 5) {
				return 1;
			}
			else { return 2; }
			//1 = gano, 2 = perdio
			break;
		default: break;
		}
		tiempo++;
		break;
	}
	case 2: {
		controladora->TamboresMovimiento(1, bmpNota1, bmpNota2, bmpNota3, gr);
		switch (tiempo) {
		case 20: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 40: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 60: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1);  break;
		case 90: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1);  break;
		case 100: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 0);  break;
		case 120: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 0);  break;
		case 140: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 0);  break;
		case 170: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1);  break;
		case 180: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1);  break;

		case 200: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 220: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 2); break;
		case 240: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 2); break;
		case 260: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 280: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 300: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 0); break;
		case 320: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 0); break;
		case 340: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 360: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 380: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1); break;
		case 410: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1); break;
		case 420: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;

		case 700:
			tiempo = 0;
			if (controladora->GetPuntaje() >= 5) {
				return 1;
			}
			else { return 2; }
			//1 = gano, 2 = perdio
			break;
		default: break;
		}
		tiempo++;
		break;
	}
	case 3:
	{
		controladora->TamboresMovimiento(1, bmpNota1, bmpNota2, bmpNota3, gr);
		switch (tiempo) {
		case 20: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 40: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 60: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1);  break;
		case 90: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1);  break;
		case 100: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 0);  break;
		case 120: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 0);  break;
		case 140: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 0);  break;
		case 170: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1);  break;
		case 180: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1);  break;

		case 200: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 220: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 2); break;
		case 240: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 2); break;
		case 260: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 280: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 300: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 0); break;
		case 320: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 0); break;
		case 340: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 360: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 380: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1); break;
		case 410: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1); break;

		case 420: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 430: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1); break;
		case 440: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 450: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1); break;
		case 460: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1); break;
		case 465: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 1); break;

		case 800:
			tiempo = 0;
			if (controladora->GetPuntaje() >= 5) {
				return 1;
			}
			else { return 2; }
			//1 = gano, 2 = perdio
			break;
		default: break;
		}
		tiempo++;
		break;
	}
		 default: break;
	}
	return 0;
}
