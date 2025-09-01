#include "Habitacion.h"
#include <ncurses.h>

static const char WALL_CHAR = '#';
static const char FLOOR_CHAR = ' ';

Habitacion::Habitacion(int W, int H) : w(W), h(H) {
    layout.assign(h, std::string(w, FLOOR_CHAR));
    for (int x = 0; x < w; ++x) {
        layout[0][x] = WALL_CHAR;
        layout[h-1][x] = WALL_CHAR;
    }
    for (int y = 0; y < h; ++y) {
        layout[y][0] = WALL_CHAR;
        layout[y][w-1] = WALL_CHAR;
    }
}

bool Habitacion::isWalkable(int x, int y) const {
    if (x < 0 || y < 0 || x >= w || y >= h) return false;
    return layout[y][x] != WALL_CHAR;
}

void Habitacion::draw(int ox, int oy) const {
    for (int y = 0; y < h; ++y) {
        mvaddnstr(oy + y, ox, layout[y].c_str(), layout[y].size());
    }
}