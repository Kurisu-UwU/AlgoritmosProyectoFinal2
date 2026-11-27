#pragma once
#include "Perseguidor.h"
#include <vector>

using namespace std;
using namespace System::Drawing;

class Gwen : public Perseguidor {
private:
    bool GwenPersigue;
public:
    Gwen(int x, int y, int velocidad, int alto, int ancho, bool existencia, int intervalo1) : Perseguidor(x, y, velocidad, alto, ancho, existencia) {
        GwenPersigue = false;
    }
    ~Gwen() {}

    bool GetPersigue() { return GwenPersigue;}
    void SetPersigue(bool persigue) { GwenPersigue = persigue; }
};