#pragma once
#include "VariablesGlobales.h"
#include "ControladoraNivelRitmo.h"
void NivelesRitmo1(Graphics^ gr, ControladoraNivelRitmo* controladora, int nivel, Bitmap^ bmpNota1, Bitmap^ bmpNota2, Bitmap^ bmpNota3) {
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
		case 120: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 0);  break;
		case 140: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 0);  break;
		case 170: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 1, 0);  break;
		case 180: controladora->CrearNota(bmpNota1->Width, bmpNota1->Height, 0, 1);  break;
		case 380:
			if (puntaje >= 10) {
				puntuaciontotal += puntaje;
			}
			else {
				//AnimacionBorrar();
				//DibujarDerrotaTambores();
				//AnimacionBorrar();
				tiempo = 0; puntaje = 0; vida = 20;
			}
			break;
		default: break;
		}
		tiempo++;
		break;
	}
		  /*case 2: {
			  AnimacionBorrar();
			  int booleanoGeneralParaNiveles2 = true;
			  tiempo = 0;
			  controladora->GenerarTambores(12);
			  controladora->AtributosTambores(12);
			  int puntaje = 0;
			  short pos = 1;
			  int vida = 20;
			  DibujarZX(26, 43);
			  do {
				  DibujarPanelDeControl();
				  switch (pos) {
				  case 0: DibujarPunk(26, 16); break;
				  case 1: DibujarPunk(26, 23); break;
				  case 2: DibujarPunk(26, 30); break;
				  default: break;
				  }
				  controladora->TamboresMovimiento(25);
				  _sleep(1);
				  if (_kbhit()) {
					  DibujarZX(26, 43);
					  BorrarPunk(26, 16);
					  BorrarPunk(26, 23);
					  BorrarPunk(26, 30);
					  tecla = _getch();
					  if (tecla == 'z' || tecla == 'Z')AnimacionZX(26, 43, 0);
					  if (tecla == 'x' || tecla == 'X')AnimacionZX(26, 43, 1);
					  switch (controladora->PresionarTambores(25, pos)) {
					  case 0: break;
					  case 1: puntaje += 2;  break;
					  case 2: puntaje++; vida--;  break;
					  }
					  if ((tecla == 's' || tecla == 'S') && pos < 2) { pos++; }
					  if ((tecla == 'w' || tecla == 'W') && pos > 0) { pos--; }
				  }
				  switch (tiempo) {
				  case 20: controladora->RevivirTambor(0, 1); break;
				  case 40: controladora->RevivirTambor(0, 1); break;
				  case 60: controladora->RevivirTambor(1, 1); break;
				  case 90: controladora->RevivirTambor(1, 1); break;
				  case 100: controladora->RevivirTambor(0, 0); break;
				  case 120: controladora->RevivirTambor(0, 0); break;
				  case 140: controladora->RevivirTambor(1, 0); break;
				  case 170: controladora->RevivirTambor(1, 0); break;
				  case 180: controladora->RevivirTambor(0, 1); break;
				  case 200: controladora->RevivirTambor(0, 1); break;
				  case 220: controladora->RevivirTambor(0, 2); break;
				  case 240: controladora->RevivirTambor(0, 2); break;
				  case 260: controladora->RevivirTambor(0, 1); break;
				  case 280: controladora->RevivirTambor(0, 1); break;
				  case 300: controladora->RevivirTambor(0, 0); break;
				  case 320: controladora->RevivirTambor(0, 0); break;
				  case 340: controladora->RevivirTambor(0, 1); break;
				  case 360: controladora->RevivirTambor(0, 1); break;
				  case 380: controladora->RevivirTambor(1, 1); break;
				  case 410: controladora->RevivirTambor(1, 1); break;
				  case 420: controladora->RevivirTambor(0, 1); break;
				  case 620:
					  if (puntaje >= 18) {
						  booleanoGeneralParaNiveles2 = false;
						  booleanoGeneralParaNiveles3 = false;
						  cantidaddeherramientas++;
					  }
					  else { AnimacionBorrar(); DibujarDerrotaTambores(); } break;
				  default: break;
				  }
				  tiempo++;
				  Posicion(20, 10); ColorAzul(); cout << "Tiempo: " << tiempo;
				  Posicion(40, 10); ColorVerde(); cout << "Puntaje: " << puntaje << " ";
				  Posicion(60, 10); ColorRojo(); cout << "Vida: " << vida << " ";
			  } while (booleanoGeneralParaNiveles2 && vida > 1);
			  AnimacionBorrar();
			  DibujarPanelDeControl();
			  DibujarEdificio(1, 7);
			  DibujarEdificio(26, 7);
			  DibujarEdificio(51, 7);
			  DibujarEdificio(76, 7);
			  DibujarEdificio(101, 7);
			  DibujarEdificio(126, 7);
			  DibujarEdificio(151, 7);
			  DibujarEdificio(176, 7);
			  DibujarEdificio(187, 32);
			  DibujarEdificio(162, 32);
			  DibujarEdificio(137, 32);
			  DibujarEdificio(1, 32);
			  DibujarEdificio(26, 32);
			  DibujarEdificio(51, 32);
			  puntuaciontotal += puntaje;
			  break;
		  }
		  case 3: {
			  AnimacionBorrar();
			  int booleanoGeneralParaNiveles2 = true;
			  tiempo = 0;
			  controladora->GenerarTambores(12);
			  controladora->AtributosTambores(12);
			  int puntaje = 0;
			  short pos = 1;
			  int vida = 20;
			  DibujarZX(26, 43);
			  do {
				  DibujarPanelDeControl();
				  switch (pos) {
				  case 0: DibujarPunk(26, 16); break;
				  case 1: DibujarPunk(26, 23); break;
				  case 2: DibujarPunk(26, 30); break;
				  default: break;
				  }
				  controladora->TamboresMovimiento(25);
				  _sleep(1);
				  if (_kbhit()) {
					  DibujarZX(26, 43);
					  BorrarPunk(26, 16);
					  BorrarPunk(26, 23);
					  BorrarPunk(26, 30);
					  tecla = _getch();
					  if (tecla == 'z' || tecla == 'Z')AnimacionZX(26, 43, 0);
					  if (tecla == 'x' || tecla == 'X')AnimacionZX(26, 43, 1);
					  switch (controladora->PresionarTambores(25, pos)) {
					  case 0: break;
					  case 1: puntaje += 2;  break;
					  case 2: puntaje++; vida--;  break;
					  }
					  if ((tecla == 's' || tecla == 'S') && pos < 2) { pos++; }
					  if ((tecla == 'w' || tecla == 'W') && pos > 0) { pos--; }
				  }
				  switch (tiempo) {
				  case 20: controladora->RevivirTambor(0, 1); break;
				  case 40: controladora->RevivirTambor(0, 1); break;
				  case 60: controladora->RevivirTambor(1, 1); break;
				  case 90: controladora->RevivirTambor(1, 1); break;
				  case 100: controladora->RevivirTambor(0, 0); break;
				  case 120: controladora->RevivirTambor(0, 0); break;
				  case 140: controladora->RevivirTambor(1, 0); break;
				  case 170: controladora->RevivirTambor(1, 0); break;
				  case 180: controladora->RevivirTambor(0, 1); break;
				  case 200: controladora->RevivirTambor(0, 1); break;
				  case 220: controladora->RevivirTambor(0, 2); break;
				  case 240: controladora->RevivirTambor(0, 2); break;
				  case 260: controladora->RevivirTambor(0, 1); break;
				  case 280: controladora->RevivirTambor(0, 1); break;
				  case 300: controladora->RevivirTambor(0, 0); break;
				  case 320: controladora->RevivirTambor(0, 0); break;
				  case 340: controladora->RevivirTambor(0, 1); break;
				  case 360: controladora->RevivirTambor(0, 1); break;
				  case 380: controladora->RevivirTambor(1, 1); break;
				  case 410: controladora->RevivirTambor(1, 1); break;
				  case 420: controladora->RevivirTambor(0, 1); break;
				  case 430: controladora->RevivirTambor(1, 1); break;
				  case 440: controladora->RevivirTambor(0, 1); break;
				  case 450: controladora->RevivirTambor(1, 1); break;
				  case 460: controladora->RevivirTambor(0, 1); break;
				  case 465: controladora->RevivirTambor(1, 1); break;
				  case 666:
					  if (puntaje >= 24) {
						  booleanoGeneralParaNiveles2 = false;
						  booleanoGeneralParaNiveles5 = false;
						  cantidaddeherramientas++;
					  }
					  else { AnimacionBorrar(); DibujarDerrotaTambores(); } break;
				  default: break;
				  }
				  tiempo++;
				  Posicion(20, 10); ColorAzul(); cout << "Tiempo: " << tiempo;
				  Posicion(40, 10); ColorVerde(); cout << "Puntaje: " << puntaje << " ";
				  Posicion(60, 10); ColorRojo(); cout << "Vida: " << vida << " ";
			  } while (booleanoGeneralParaNiveles2 && vida > 1);
			  AnimacionBorrar();
			  DibujarPanelDeControl();
			  DibujarEdificio(1, 7);
			  DibujarEdificio(26, 7);
			  DibujarEdificio(51, 7);
			  DibujarEdificio(76, 7);
			  DibujarEdificio(101, 7);
			  DibujarEdificio(126, 7);
			  DibujarEdificio(151, 7);
			  DibujarEdificio(176, 7);
			  DibujarEdificio(187, 32);
			  DibujarEdificio(162, 32);
			  DibujarEdificio(137, 32);
			  DibujarEdificio(1, 32);
			  DibujarEdificio(26, 32);
			  DibujarEdificio(51, 32);
			  puntuaciontotal += puntaje;
			  break;
		  }
		  case 4: {
			  AnimacionBorrar();
			  int booleanoGeneralParaNiveles2 = true;
			  tiempo = 0;
			  controladora->GenerarTambores(12);
			  controladora->AtributosTambores(12);
			  int puntaje = 0;
			  short pos = 1;
			  int vida = 20;
			  DibujarZX(26, 43);
			  do {
				  DibujarPanelDeControl();
				  switch (pos) {
				  case 0: DibujarPunk(26, 16); break;
				  case 1: DibujarPunk(26, 23); break;
				  case 2: DibujarPunk(26, 30); break;
				  default: break;
				  }
				  controladora->TamboresMovimiento(25);
				  _sleep(1);
				  if (_kbhit()) {
					  DibujarZX(26, 43);
					  BorrarPunk(26, 16);
					  BorrarPunk(26, 23);
					  BorrarPunk(26, 30);
					  tecla = _getch();
					  if (tecla == 'z' || tecla == 'Z')AnimacionZX(26, 43, 0);
					  if (tecla == 'x' || tecla == 'X')AnimacionZX(26, 43, 1);
					  switch (controladora->PresionarTambores(25, pos)) {
					  case 0: break;
					  case 1: puntaje += 2;  break;
					  case 2: puntaje++; vida--;  break;
					  }
					  if ((tecla == 's' || tecla == 'S') && pos < 2) { pos++; }
					  if ((tecla == 'w' || tecla == 'W') && pos > 0) { pos--; }
				  }
				  switch (tiempo) {
				  case 20: controladora->RevivirTambor(0, 1); break;
				  case 40: controladora->RevivirTambor(0, 1); break;
				  case 60: controladora->RevivirTambor(1, 1); break;
				  case 90: controladora->RevivirTambor(1, 1); break;
				  case 100: controladora->RevivirTambor(0, 0); break;
				  case 120: controladora->RevivirTambor(0, 0); break;
				  case 140: controladora->RevivirTambor(1, 0); break;
				  case 170: controladora->RevivirTambor(1, 0); break;
				  case 180: controladora->RevivirTambor(0, 1); break;
				  case 200: controladora->RevivirTambor(0, 1); break;
				  case 220: controladora->RevivirTambor(0, 2); break;
				  case 240: controladora->RevivirTambor(0, 2); break;
				  case 260: controladora->RevivirTambor(0, 1); break;
				  case 280: controladora->RevivirTambor(0, 1); break;
				  case 300: controladora->RevivirTambor(0, 0); break;
				  case 320: controladora->RevivirTambor(0, 0); break;
				  case 340: controladora->RevivirTambor(0, 1); break;
				  case 360: controladora->RevivirTambor(0, 1); break;
				  case 380: controladora->RevivirTambor(1, 1); break;
				  case 410: controladora->RevivirTambor(1, 1); break;
				  case 420: controladora->RevivirTambor(0, 1); break;
				  case 430: controladora->RevivirTambor(1, 1); break;
				  case 440: controladora->RevivirTambor(0, 1); break;
				  case 450: controladora->RevivirTambor(1, 1); break;
				  case 460: controladora->RevivirTambor(0, 1); break;
				  case 465: controladora->RevivirTambor(1, 1); break;
				  case 600: controladora->RevivirTambor(0, 1); break;
				  case 630: controladora->RevivirTambor(1, 1); break;
				  case 650: controladora->RevivirTambor(1, 1); break;
				  case 680: controladora->RevivirTambor(0, 1); break;
				  case 690: controladora->RevivirTambor(0, 1); break;
				  case 710: controladora->RevivirTambor(1, 1); break;
				  case 740: controladora->RevivirTambor(1, 1); break;
				  case 750: controladora->RevivirTambor(0, 1); break;
				  case 950:
					  if (puntaje >= 33) {
						  booleanoGeneralParaNiveles2 = false;
						  booleanoGeneralParaNiveles3 = false;
						  cantidaddeherramientas++;
					  }
					  else { AnimacionBorrar(); DibujarDerrotaTambores(); } break;
				  default: break;
				  }
				  tiempo++;
				  Posicion(20, 10); ColorAzul(); cout << "Tiempo: " << tiempo;
				  Posicion(40, 10); ColorVerde(); cout << "Puntaje: " << puntaje << " ";
				  Posicion(60, 10); ColorRojo(); cout << "Vida: " << vida << " ";
			  } while (booleanoGeneralParaNiveles2 && vida > 1);
			  AnimacionBorrar();
			  DibujarPanelDeControl();
			  DibujarEdificio(1, 32);
			  DibujarEdificio(26, 32);
			  DibujarEdificio(51, 32);
			  DibujarEdificio(76, 32);
			  DibujarEdificio(101, 32);
			  DibujarEdificio(126, 32);
			  DibujarEdificio(151, 32);
			  DibujarEdificio(176, 32);
			  DibujarEdificio(187, 7);
			  DibujarEdificio(162, 7);
			  DibujarEdificio(137, 7);
			  DibujarEdificio(1, 7);
			  DibujarEdificio(26, 7);
			  DibujarEdificio(51, 7);
			  puntuaciontotal += puntaje;
			  break;
		  }
		  case 5: {
			  AnimacionBorrar();
			  int booleanoGeneralParaNiveles2 = true;
			  tiempo = 0;
			  controladora->GenerarTambores(12);
			  controladora->AtributosTambores(12);
			  int puntaje = 0;
			  short pos = 1;
			  int vida = 20;
			  DibujarZX(26, 43);
			  do {
				  DibujarPanelDeControl();
				  switch (pos) {
				  case 0: DibujarPunk(26, 16); break;
				  case 1: DibujarPunk(26, 23); break;
				  case 2: DibujarPunk(26, 30); break;
				  default: break;
				  }
				  controladora->TamboresMovimiento(25);
				  _sleep(1);
				  if (_kbhit()) {
					  DibujarZX(26, 43);
					  BorrarPunk(26, 16);
					  BorrarPunk(26, 23);
					  BorrarPunk(26, 30);
					  tecla = _getch();
					  if (tecla == 'z' || tecla == 'Z')AnimacionZX(26, 43, 0);
					  if (tecla == 'x' || tecla == 'X')AnimacionZX(26, 43, 1);
					  switch (controladora->PresionarTambores(25, pos)) {
					  case 0: break;
					  case 1: puntaje += 2;  break;
					  case 2: puntaje++; vida--;  break;
					  }
					  if ((tecla == 's' || tecla == 'S') && pos < 2) { pos++; }
					  if ((tecla == 'w' || tecla == 'W') && pos > 0) { pos--; }
				  }
				  switch (tiempo) {
				  case 20: controladora->RevivirTambor(0, 1); break;
				  case 40: controladora->RevivirTambor(0, 1); break;
				  case 60: controladora->RevivirTambor(1, 1); break;
				  case 90: controladora->RevivirTambor(1, 1); break;
				  case 100: controladora->RevivirTambor(0, 0); break;
				  case 120: controladora->RevivirTambor(0, 0); break;
				  case 140: controladora->RevivirTambor(1, 0); break;
				  case 170: controladora->RevivirTambor(1, 0); break;
				  case 180: controladora->RevivirTambor(0, 1); break;
				  case 200: controladora->RevivirTambor(0, 1); break;
				  case 220: controladora->RevivirTambor(0, 2); break;
				  case 240: controladora->RevivirTambor(0, 2); break;
				  case 260: controladora->RevivirTambor(0, 1); break;
				  case 280: controladora->RevivirTambor(0, 1); break;
				  case 300: controladora->RevivirTambor(0, 0); break;
				  case 320: controladora->RevivirTambor(0, 0); break;
				  case 340: controladora->RevivirTambor(0, 1); break;
				  case 360: controladora->RevivirTambor(0, 1); break;
				  case 380: controladora->RevivirTambor(1, 1); break;
				  case 410: controladora->RevivirTambor(1, 1); break;
				  case 420: controladora->RevivirTambor(0, 1); break;
				  case 430: controladora->RevivirTambor(1, 1); break;
				  case 440: controladora->RevivirTambor(0, 1); break;
				  case 450: controladora->RevivirTambor(1, 1); break;
				  case 460: controladora->RevivirTambor(0, 1); break;
				  case 465: controladora->RevivirTambor(1, 1); break;
				  case 600: controladora->RevivirTambor(0, 1); break;
				  case 630: controladora->RevivirTambor(1, 1); break;
				  case 650: controladora->RevivirTambor(1, 1); break;
				  case 680: controladora->RevivirTambor(0, 1); break;
				  case 690: controladora->RevivirTambor(0, 1); break;
				  case 710: controladora->RevivirTambor(1, 1); break;
				  case 740: controladora->RevivirTambor(1, 1); break;
				  case 750: controladora->RevivirTambor(0, 1); break;
				  case 950:
					  if (puntaje >= 33) {
						  booleanoGeneralParaNiveles2 = false;
						  booleanoGeneralParaNiveles5 = false;
						  cantidaddeherramientas++;
					  }
					  else { AnimacionBorrar(); DibujarDerrotaTambores(); } break;
				  default: break;
				  }
				  tiempo++;
				  Posicion(20, 10); ColorAzul(); cout << "Tiempo: " << tiempo;
				  Posicion(40, 10); ColorVerde(); cout << "Puntaje: " << puntaje << " ";
				  Posicion(60, 10); ColorRojo(); cout << "Vida: " << vida << " ";
			  } while (booleanoGeneralParaNiveles2 && vida > 1);
			  AnimacionBorrar();
			  DibujarPanelDeControl();
			  DibujarEdificio(1, 32);
			  DibujarEdificio(26, 32);
			  DibujarEdificio(51, 32);
			  DibujarEdificio(76, 32);
			  DibujarEdificio(101, 32);
			  DibujarEdificio(126, 32);
			  DibujarEdificio(151, 32);
			  DibujarEdificio(176, 32);
			  DibujarEdificio(187, 7);
			  DibujarEdificio(162, 7);
			  DibujarEdificio(137, 7);
			  DibujarEdificio(1, 7);
			  DibujarEdificio(26, 7);
			  DibujarEdificio(51, 7);
			  puntuaciontotal += puntaje;
			  break;
		  }
		  case 6: {
			  AnimacionBorrar();
			  int booleanoGeneralParaNiveles2 = true;
			  tiempo = 0;
			  controladora->GenerarTambores(12);
			  controladora->AtributosTambores(12);
			  int puntaje = 0;
			  short pos = 1;
			  int vida = 20;
			  DibujarZX(26, 43);
			  do {
				  DibujarPanelDeControl();
				  switch (pos) {
				  case 0: DibujarPunk(26, 16); break;
				  case 1: DibujarPunk(26, 23); break;
				  case 2: DibujarPunk(26, 30); break;
				  default: break;
				  }
				  controladora->TamboresMovimiento(25);
				  _sleep(1);
				  if (_kbhit()) {
					  DibujarZX(26, 43);
					  BorrarPunk(26, 16);
					  BorrarPunk(26, 23);
					  BorrarPunk(26, 30);
					  tecla = _getch();
					  if (tecla == 'z' || tecla == 'Z')AnimacionZX(26, 43, 0);
					  if (tecla == 'x' || tecla == 'X')AnimacionZX(26, 43, 1);
					  switch (controladora->PresionarTambores(25, pos)) {
					  case 0: break;
					  case 1: puntaje += 2;  break;
					  case 2: puntaje++; vida--;  break;
					  }
					  if ((tecla == 's' || tecla == 'S') && pos < 2) { pos++; }
					  if ((tecla == 'w' || tecla == 'W') && pos > 0) { pos--; }
				  }
				  switch (tiempo) {
				  case 20: controladora->RevivirTambor(0, 1); break;
				  case 40: controladora->RevivirTambor(0, 1); break;
				  case 60: controladora->RevivirTambor(1, 1); break;
				  case 90: controladora->RevivirTambor(1, 1); break;
				  case 100: controladora->RevivirTambor(0, 0); break;
				  case 120: controladora->RevivirTambor(0, 0); break;
				  case 140: controladora->RevivirTambor(1, 0); break;
				  case 170: controladora->RevivirTambor(1, 0); break;
				  case 180: controladora->RevivirTambor(0, 1); break;
				  case 200: controladora->RevivirTambor(0, 1); break;
				  case 220: controladora->RevivirTambor(0, 2); break;
				  case 240: controladora->RevivirTambor(0, 2); break;
				  case 260: controladora->RevivirTambor(0, 1); break;
				  case 280: controladora->RevivirTambor(0, 1); break;
				  case 300: controladora->RevivirTambor(0, 0); break;
				  case 320: controladora->RevivirTambor(0, 0); break;
				  case 340: controladora->RevivirTambor(0, 1); break;
				  case 360: controladora->RevivirTambor(0, 1); break;
				  case 380: controladora->RevivirTambor(1, 1); break;
				  case 410: controladora->RevivirTambor(1, 1); break;
				  case 420: controladora->RevivirTambor(0, 1); break;
				  case 430: controladora->RevivirTambor(1, 1); break;
				  case 440: controladora->RevivirTambor(0, 1); break;
				  case 450: controladora->RevivirTambor(1, 1); break;
				  case 460: controladora->RevivirTambor(0, 1); break;
				  case 465: controladora->RevivirTambor(1, 1); break;
				  case 600: controladora->RevivirTambor(0, 1); break;
				  case 630: controladora->RevivirTambor(1, 1); break;
				  case 650: controladora->RevivirTambor(1, 1); break;
				  case 680: controladora->RevivirTambor(0, 1); break;
				  case 690: controladora->RevivirTambor(0, 1); break;
				  case 710: controladora->RevivirTambor(1, 1); break;
				  case 740: controladora->RevivirTambor(1, 1); break;
				  case 750: controladora->RevivirTambor(0, 1); break;
				  case 950:
					  if (puntaje >= 33) {
						  booleanoGeneralParaNiveles2 = false;
						  booleanoGeneralParaNiveles6 = false;
						  cantidaddeherramientas++;
					  }
					  else {
						  AnimacionBorrar();
						  DibujarDerrotaTambores();
						  AnimacionBorrar();
						  tiempo = 0;
					  } break;
				  default: break;
				  }
				  tiempo++;
				  Posicion(20, 10); ColorAzul(); cout << "Tiempo: " << tiempo;
				  Posicion(40, 10); ColorVerde(); cout << "Puntaje: " << puntaje << " ";
				  Posicion(60, 10); ColorRojo(); cout << "Vida: " << vida << " ";
			  } while (booleanoGeneralParaNiveles2 && vida > 1);
			  AnimacionBorrar();
			  DibujarPanelDeControl();
			  DibujarEdificio(1, 32);
			  DibujarEdificio(26, 32);
			  DibujarEdificio(51, 32);
			  DibujarEdificio(76, 32);
			  DibujarEdificio(101, 32);
			  DibujarEdificio(126, 32);
			  DibujarEdificio(151, 32);
			  DibujarEdificio(176, 32);
			  DibujarEdificio(187, 7);
			  DibujarEdificio(162, 7);
			  DibujarEdificio(137, 7);
			  DibujarEdificio(1, 7);
			  DibujarEdificio(26, 7);
			  DibujarEdificio(51, 7);
			  puntuaciontotal += puntaje;
			  break
		  }
		  */
		 default: break;
	}
}
