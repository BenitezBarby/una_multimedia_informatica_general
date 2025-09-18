#include "Sombra.h"
#include <ncurses.h>
#include <cstdlib>

void Sombra::draw(int ox, int oy) const {
    attron(COLOR_PAIR(2));
    mvaddch(oy + pos.y, ox + pos.x, glyph);
    attroff(COLOR_PAIR(2));
}


void Sombra::step(const Habitacion& room, const Detective& det) {
    int choice = rand() % 10;  // número entre 0 y 9
    int nx = pos.x, ny = pos.y;

    if (choice < 4) {  
        // movimiento aleatorio
        static const int dx[4] = {0,0,-1,1};
        static const int dy[4] = {-1,1,0,0};
        int i = rand() % 4;
        nx += dx[i]; 
        ny += dy[i];
    } else {
        // movimiento hacia el detective
        int dx = (det.pos.x > pos.x) ? 1 : (det.pos.x < pos.x ? -1 : 0);
        int dy = (det.pos.y > pos.y) ? 1 : (det.pos.y < pos.y ? -1 : 0);
        nx += dx; 
        ny += dy;
    }

    if (room.isWalkable(nx, ny)) {
        pos.x = nx; 
        pos.y = ny;
    }
}
