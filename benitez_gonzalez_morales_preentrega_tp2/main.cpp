#include <ncurses.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "Habitacion.h"
#include "Detective.h"
#include "Sombra.h"
#include "Pista.h"

// Constantes
static const int TERM_WIDTH  = 120;
static const int TERM_HEIGHT = 40;
static const int PLAY_AREA_W = 100;
static const int PLAY_AREA_H = 30;
static const int PLAY_OFFSET_X = 2;
static const int PLAY_OFFSET_Y = 2;

// Estados de juego
enum class GameState { MENU, INSTRUCTIONS, PLAYING, VICTORY, GAME_OVER, EXIT };

// Objetos globales
std::vector<Habitacion> niveles;
Detective det;
Sombra sombra;
std::vector<Pista> pistas;

// --------------------------------------------------------------------------------
// Función utilitaria para texto centrado
// --------------------------------------------------------------------------------
void drawCentered(int y, const std::string& s) {
    int x = std::max(0, (COLS - (int)s.size()) / 2);
    mvaddnstr(y, x, s.c_str(), s.size());
}

// --------------------------------------------------------------------------------
// Generar pistas aleatorias
// --------------------------------------------------------------------------------
void generarPistas() {
    pistas.clear();
    for (int i = 0; i < 6; ++i) {
        int x, y, guard = 0;
        do {
            x = rand() % (niveles[0].w - 2) + 1;
            y = rand() % (niveles[0].h - 2) + 1;
            guard++;
        } while ((!niveles[0].isWalkable(x,y) || (x==det.pos.x && y==det.pos.y)) && guard < 500);

        pistas.emplace_back(x, y, (char)('A' + (i % 26)));
    }
}

// --------------------------------------------------------------------------------
// Reiniciar nivel
// --------------------------------------------------------------------------------
void resetNivel() {
    det.pos = {1,1};
    det.pistasTomadas = 0;
    sombra.pos = {PLAY_AREA_W-2, PLAY_AREA_H-2};
    generarPistas();
}

// --------------------------------------------------------------------------------
// Lógica principal
// --------------------------------------------------------------------------------
int main() {
    srand(time(NULL)); // inicializar rand

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(0);

    GameState state = GameState::MENU;

    // Crear nivel
    niveles.emplace_back(PLAY_AREA_W, PLAY_AREA_H);
    resetNivel();

    int ch;
    while (state != GameState::EXIT) {
        // ---------------- Menu ----------------
        if (state == GameState::MENU) {
            clear();
            box(stdscr,0,0);
            drawCentered(5,  "#############################");
            drawCentered(6,  "# DETECTIVE EN LA MANSIÓN #");
            drawCentered(7,  "#############################");
            drawCentered(10, "[J] Jugar   [I] Instrucciones   [S] Salir");
            refresh();
            while (state == GameState::MENU) {
                ch = getch();
                if (ch=='j'||ch=='J') { resetNivel(); state = GameState::PLAYING; }
                if (ch=='i'||ch=='I') state = GameState::INSTRUCTIONS;
                if (ch=='s'||ch=='S'||ch==27) state = GameState::EXIT;
                napms(10);
            }
        }

        // ---------------- Instrucciones ----------------
        else if (state == GameState::INSTRUCTIONS) {
            clear();
            drawCentered(3, "INSTRUCCIONES");
            drawCentered(6, "Recolecta todas las PISTAS (letras) para ganar.");
            drawCentered(7, "Evita a la SOMBRA (@) que te persigue.");
            drawCentered(8, "Movimiento: Flechas | Volver al menú: Q");
            drawCentered(10, "[ESPACIO] Volver al menú");
            refresh();
            while (state == GameState::INSTRUCTIONS) {
                ch = getch();
                if (ch==' '||ch=='q'||ch=='Q') state = GameState::MENU;
                napms(10);
            }
        }

        // ---------------- Juego ----------------
        else if (state == GameState::PLAYING) {
            // Input
            ch = getch();
            Dir d = Dir::NONE;
            switch(ch) {
                case KEY_UP: d=Dir::UP; break;
                case KEY_DOWN: d=Dir::DOWN; break;
                case KEY_LEFT: d=Dir::LEFT; break;
                case KEY_RIGHT: d=Dir::RIGHT; break;
                case 'q': case 'Q': state=GameState::MENU; break;
            }
            det.move(d, niveles[0]);

            // Recolectar pistas
            for (auto &p : pistas) {
                if (!p.tomada && p.pos.x==det.pos.x && p.pos.y==det.pos.y) {
                    p.tomada=true; det.pistasTomadas++;
                }
            }

            // Mover sombra
            sombra.step(niveles[0], det);
            if (sombra.pos.x==det.pos.x && sombra.pos.y==det.pos.y) state = GameState::GAME_OVER;

            // Victoria
            bool all = std::all_of(pistas.begin(), pistas.end(), [](const Pista &p){ return p.tomada; });
            if (all) state = GameState::VICTORY;

            // Render
            clear();
            mvprintw(0,2,"Pistas: %d/%d", det.pistasTomadas, (int)pistas.size());
            niveles[0].draw(PLAY_OFFSET_X, PLAY_OFFSET_Y);
            for (auto &p : pistas) p.draw(PLAY_OFFSET_X, PLAY_OFFSET_Y);
            sombra.draw(PLAY_OFFSET_X, PLAY_OFFSET_Y);
            det.draw(PLAY_OFFSET_X, PLAY_OFFSET_Y);
            refresh();

            napms(50); // pausa corta para la jugabilidad
        }

        // ---------------- Victoria ----------------
        else if (state == GameState::VICTORY) {
            clear();
            drawCentered(8,  "* CASO RESUELTO *");
            drawCentered(10, "Reuniste todas las pistas!");
            drawCentered(12, "[ENTER] Jugar de nuevo   [Q] Menú");
            refresh();
            while (state == GameState::VICTORY) {
                ch = getch();
                if (ch=='\n') { resetNivel(); state=GameState::PLAYING; }
                if (ch=='q'||ch=='Q') state=GameState::MENU;
                napms(10);
            }
        }

        // ---------------- Derrota ----------------
        else if (state == GameState::GAME_OVER) {
            clear();
            drawCentered(8,"— TE ATRAPÓ LA SOMBRA —");
            drawCentered(10,"El caso queda inconcluso.");
            drawCentered(12,"[ENTER] Reintentar   [Q] Menú");
            refresh();
            while (state == GameState::GAME_OVER) {
                ch = getch();
                if (ch=='\n') { resetNivel(); state=GameState::PLAYING; }
                if (ch=='q'||ch=='Q') state=GameState::MENU;
                napms(10);
            }
        }
    }

    endwin();
    return 0;
}
