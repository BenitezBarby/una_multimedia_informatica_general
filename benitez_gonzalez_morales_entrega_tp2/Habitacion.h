#pragma once
#include <vector>
#include <string>

class Habitacion {
public:
    int w, h;
    std::vector<std::string> layout;

    Habitacion(int W, int H);

    bool isWalkable(int x, int y) const;
    void draw(int ox, int oy) const;
};