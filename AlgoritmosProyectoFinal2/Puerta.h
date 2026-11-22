#pragma once
#include "Entidades.h"
#include "Protagonistas.h"
using namespace System::Drawing;

class Puerta : public Entidad {
private:
    int nivelDestino, xDestino, yDestino;
public:
    Puerta(int x1, int y1, int ancho, int alto, int sala, int xd, int yd) :Entidad(x1, y1, 0, alto, ancho, true) {
        nivelDestino = sala;
        xDestino = xd;
        yDestino = yd;
    }
    int GetNivelDestino() { return nivelDestino; }
    int GetXDestino() { return xDestino; }
    int GetYDestino() { return yDestino; }

    bool Colisiona(Protagonista* p) {
        return Rectangle(x, y, anchura, altura).IntersectsWith(p->CrearRectangle());
    }
    void Dibujar(Graphics^ g) { // claude ia para el modo vista de las colosiones
        SolidBrush^ relleno = gcnew SolidBrush(Color::FromArgb(70, 255, 0, 255));
        Pen^ borde = gcnew Pen(Color::Magenta, 3);
        g->FillRectangle(relleno, x, y, anchura, altura);
        g->DrawRectangle(borde, x, y, anchura, altura);
        delete relleno;
        delete borde;

        System::String^ texto = "PUERTA -> sala " + System::Convert::ToString(nivelDestino)
            + " | x:" + System::Convert::ToString(x) + " y:" + System::Convert::ToString(y)
            + " w:" + System::Convert::ToString(anchura) + " h:" + System::Convert::ToString(altura)
            + " | llegada:" + System::Convert::ToString(xDestino) + "," + System::Convert::ToString(yDestino);
        RectangleF clip = g->VisibleClipBounds;
        float maxX = clip.Right - 430.0f;   // que la etiqueta no se salga del panel
        float tx = System::Math::Max(0.0f, System::Math::Min((float)(x + 4), maxX));
        g->FillRectangle(Brushes::Black, tx, (float)(y + 24), 425.0f, 16.0f);
        g->DrawString(texto, SystemFonts::DefaultFont, Brushes::White, tx + 2, (float)(y + 25));
    }
};