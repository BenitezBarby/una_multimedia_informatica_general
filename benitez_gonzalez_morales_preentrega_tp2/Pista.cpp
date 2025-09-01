#include "Pista.h"
#include <ncurses.h>

Pista::Pista(int x, int y, char g) {
    pos.x = x;
    pos.y = y;
    glyph = g;
}

void Pista::draw(int ox, int oy) const {
    if (!tomada)
        mvaddch(oy + pos.y, ox + pos.x, glyph);
}