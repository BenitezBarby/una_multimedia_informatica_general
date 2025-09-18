#pragma once
#include "Habitacion.h"

struct Pos { int x{}, y{}; };
enum class Dir { NONE, UP, DOWN, LEFT, RIGHT };

class Detective {
public:
    Pos pos{1,1};
    char glyph{'@'};
    int pistasTomadas{0};

    void draw(int ox, int oy) const;
    void move(Dir d, const Habitacion& room);
};