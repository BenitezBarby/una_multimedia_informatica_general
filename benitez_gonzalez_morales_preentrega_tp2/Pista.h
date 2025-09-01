#pragma once
#include "Detective.h"

class Pista {
public:
    Pos pos{};
    bool tomada{false};
    char glyph{'?'};

    Pista() = default;
    Pista(int x, int y, char g='?');

    void draw(int ox, int oy) const;
};