#include "Detective.h"
#include <ncurses.h>

void Detective::draw(int ox, int oy) const {
    mvaddch(oy + pos.y, ox + pos.x, glyph);
}

void Detective::move(Dir d, const Habitacion& room) {
    int nx = pos.x, ny = pos.y;
    switch(d) {
        case Dir::UP: ny--; break;
        case Dir::DOWN: ny++; break;
        case Dir::LEFT: nx--; break;
        case Dir::RIGHT: nx++; break;
        default: break;
    }
    if (room.isWalkable(nx, ny)) {
        pos.x = nx;
        pos.y = ny;
    }
}