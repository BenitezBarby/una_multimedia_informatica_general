#pragma once
#include "Detective.h"
#include "Habitacion.h"

class Sombra {
public:
    Pos pos{2,2};
    char glyph{'%'};

    void draw(int ox, int oy) const;
    void step(const Habitacion& room, const Detective& det);
};
