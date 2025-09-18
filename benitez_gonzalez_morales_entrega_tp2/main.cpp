// Universidad Nacional de las Artes - Informática General (Cátedra Tirigall)
// TP2 Game Art con Ncurses — "Detective en la Mansión"

#include <ncurses.h>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cstdlib>
#include <sys/ioctl.h>
#include <unistd.h>


// --------------------------- CONSTANTES --------------------------------------
int TERM_WIDTH  = 120;
int TERM_HEIGHT = 40;

static const int PLAY_AREA_W = 100;
static const int PLAY_AREA_H = 30;
static const int PLAY_OFFSET_X = 2;
static const int PLAY_OFFSET_Y = 2;

static const char WALL_CHAR   = '#';
static const char FLOOR_CHAR  = ' ';
static const char DETECTIVE_CHAR = '@';
static const char SHADOW_CHAR    = '%';
static const char PISTA_CHAR     = '?';

enum class Dir { NONE, UP, DOWN, LEFT, RIGHT };
enum class GameState { MENU, INSTRUCTIONS, PLAYING, VICTORY, GAME_OVER, EXIT };

struct Pos { int x{}, y{}; };

inline bool inBounds(int x, int y, int w, int h) {
    return x >= 0 && y >= 0 && x < w && y < h;
}

void drawCentered(int y, const std::string& s, int colorPair = 0) {
    int x = std::max(0, (TERM_WIDTH - (int)s.size()) / 2);
    if (colorPair > 0) attron(COLOR_PAIR(colorPair));
    mvaddnstr(y, x, s.c_str(), s.size());
    if (colorPair > 0) attroff(COLOR_PAIR(colorPair));
}

void detectarResolucionTerminal(int &w, int &h) {
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0) {
        w = ws.ws_col;
        h = ws.ws_row;
    } else {
        w = 120; 
        h = 40;
    }
}


// ------------------------------ CLASES ---------------------------------------
class Habitacion {
public:
    int w, h;
    std::vector<std::string> layout;

    Habitacion(int W, int H) : w(W), h(H) {
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

    bool isWalkable(int x, int y) const {
        if (!inBounds(x, y, w, h)) return false;
        return layout[y][x] != WALL_CHAR;
    }

    void draw(int ox, int oy) const {
        for (int y = 0; y < h; ++y) {
            mvaddnstr(oy + y, ox, layout[y].c_str(), layout[y].size());
        }
    }
};

class Pista {
public:
    Pos pos{};
    bool tomada{false};
    char glyph{PISTA_CHAR};

    Pista() = default;
    Pista(int x, int y, char g='?') { pos.x = x; pos.y = y; glyph = g; }

    void draw(int ox, int oy) const {
        if (!tomada) {
            attron(COLOR_PAIR(3));
            mvaddch(oy + pos.y, ox + pos.x, glyph);
            attroff(COLOR_PAIR(3));
        }
    }
};

class Detective {
public:
    Pos pos{1,1};
    char glyph{DETECTIVE_CHAR};
    int pistasTomadas{0};

    void draw(int ox, int oy) const {
        attron(COLOR_PAIR(1));
        mvaddch(oy + pos.y, ox + pos.x, glyph);
        attroff(COLOR_PAIR(1));
    }

    void move(Dir d, const Habitacion& room) {
        int nx = pos.x, ny = pos.y;
        switch (d) {
            case Dir::UP:    ny--; break;
            case Dir::DOWN:  ny++; break;
            case Dir::LEFT:  nx--; break;
            case Dir::RIGHT: nx++; break;
            case Dir::NONE: default: break;
        }
        if (room.isWalkable(nx, ny)) { pos.x = nx; pos.y = ny; }
    }
};

class Sombra {
public:
    Pos pos{2,2};
    char glyph{SHADOW_CHAR};
    std::mt19937 rng{std::random_device{}()};

    void draw(int ox, int oy) const {
        attron(COLOR_PAIR(2));
        mvaddch(oy + pos.y, ox + pos.x, glyph);
        attroff(COLOR_PAIR(2));
    }

    void step(const Habitacion& room, const Detective& det) {
        std::uniform_int_distribution<int> coin(0, 9);
        int choice = coin(rng);
        int nx = pos.x, ny = pos.y;
        if (choice < 4) {
            static const int dx[4] = {0, 0, -1, 1};
            static const int dy[4] = {-1, 1, 0, 0};
            int i = coin(rng) % 4;
            nx += dx[i]; ny += dy[i];
        } else {
            int dx = (det.pos.x > pos.x) ? 1 : (det.pos.x < pos.x ? -1 : 0);
            int dy = (det.pos.y > pos.y) ? 1 : (det.pos.y < pos.y ? -1 : 0);
            nx += dx; ny += dy;
        }
        if (room.isWalkable(nx, ny)) { pos.x = nx; pos.y = ny; }
    }
};

// ------------------------------ JUEGO ----------------------------------------
class Juego {
public:
    GameState state{GameState::MENU};
    std::vector<Habitacion> niveles;
    int nivelActual{0};

    Detective det;
    Sombra sombra;
    std::vector<Pista> pistas;

    std::mt19937 rng{std::random_device{}()};

    void init() {
        niveles.emplace_back(PLAY_AREA_W, PLAY_AREA_H);
        resetNivel(0);
    }

    void resetNivel(int idx) {
        nivelActual = idx;
        det = Detective{};
        det.pos = {1,1};
        sombra = Sombra{};
        sombra.pos = {PLAY_AREA_W-2, PLAY_AREA_H-2};
        generarPistas(6);
    }

    void generarPistas(int cantidad) {
        pistas.clear();
        std::uniform_int_distribution<int> rx(1, niveles[nivelActual].w-2);
        std::uniform_int_distribution<int> ry(1, niveles[nivelActual].h-2);
        for (int i = 0; i < cantidad; ++i) {
            int x, y; int guard = 0;
            bool conflict;
            do {
                x = rx(rng); y = ry(rng);
                conflict = false;
                for (auto& p : pistas) {
                    if (p.pos.x == x && p.pos.y == y) { conflict = true; break; }
                }
                guard++; if (guard > 500) break;
            } while (!niveles[nivelActual].isWalkable(x,y) || (x==det.pos.x && y==det.pos.y) || conflict);
            pistas.emplace_back(x, y, (char)('A' + (i%26)));
        }
    }

    void run() {
        while (state != GameState::EXIT) {
            switch (state) {
                case GameState::MENU:        pantallaMenu(); break;
                case GameState::INSTRUCTIONS:pantallaInstrucciones(); break;
                case GameState::PLAYING:     loopJuego(); break;
                case GameState::VICTORY:     pantallaVictoria(); break;
                case GameState::GAME_OVER:   pantallaGameOver(); break;
                default: state = GameState::EXIT; break;
            }
        }
    }

private:
    void pantallaMenu() {
clear();
drawCentered(1, "      _               _                          _     __                  ", 4);
drawCentered(2, "   ___FJ     ____    FJ_      ____      ____    FJ_    LJ  _    _   ____   ", 4);
drawCentered(3, "  F __  L   F __ J  J  _|    F __ J    F ___J. J  _|      J |  | L F __ J  ", 4);
drawCentered(4, " | |--| |  | _____J | |-'   | _____J  | |---LJ | |-'   FJ J J  F L| _____J ", 4);
drawCentered(5, " F L__J J  F L___--.F |__-. F L___--. F L___--.F |__-.J  LJ\ \/ /FF L___--.", 4);
drawCentered(6, "J\____,__LJ\______/F\_____/J\______/FJ\______/F\_____/J__L \\__//J\______/F", 4);
drawCentered(7, " J____,__F J______F J_____F J______F  J______F J_____F|__|  \__/  J______F ", 4);
                        
drawCentered(9, "   ____     _ ___        LJ    ___ _                                       ", 4);
drawCentered(10, "  F __ J   J '__ J       FJ   F __` L                                     ", 4);
drawCentered(11, " | _____J  | |__| |     J  L | |--| |                                     ", 4);
drawCentered(12, " F L___--. F L  J J     J  L F L__J J                                     ", 4);
drawCentered(13, "J\______/FJ__L  J__L    J__LJ\____,__L                                    ", 4);
drawCentered(14, " J______F |__L  J__|    |__| J____,__F     __                             ", 4);
drawCentered(15, "  _ _____      ___ _    _ ___      ____    LJ    ____     _ ___           ", 4);
drawCentered(16, " J '_  _ `,   F __` L  J '__ J    F ___J        F __ J   J '__ J          ", 4);
drawCentered(17, " | |_||_| |  | |--| |  | |__| |  | '----_  FJ  | |--| |  | |__| |         ", 4);
drawCentered(18, " F L LJ J J  F L__J J  F L  J J  )-____  LJ  L F L__J J  F L  J           ", 4);
drawCentered(19, "J__L LJ J__LJ\____,__LJ__L  J__LJ\______/FJ__LJ\______/FJ__L  J_L         ", 4);
drawCentered(20, "|__L LJ J__| J____,__F|__L  J__| J______F |__| J______F |__L  __|         ", 4);
drawCentered(22, " ****   *QUE NO TE ATRAPE LA SOMBRA!*    ****", 4);
drawCentered(23, " ****                                    ****", 4);
drawCentered(24, " ********************************************", 4);
drawCentered(25, " ********************************************", 4);
drawCentered(26, "[J] Jugar [I] Instrucciones [S] Salir", 5);
refresh();
        int ch;
        while (state == GameState::MENU) {
            ch = getch();
            if (ch == 'j' || ch == 'J') {
                resetNivel(0);
                state = GameState::PLAYING;
            } else if (ch == 'i' || ch == 'I') {
                state = GameState::INSTRUCTIONS;
            } else if (ch == 's' || ch == 'S' || ch == 27) {
                state = GameState::EXIT;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void pantallaInstrucciones() {
        clear();
        drawCentered(3, "INSTRUCCIONES", 5);
        drawCentered(5, "Recolectá todas las pistas y evitá la SOMBRA.");
        drawCentered(6,  "        ##############            ", 3);                
        drawCentered(7,  "      ##################          ", 3);            
        drawCentered(8,  "    ######          ######        ", 3);           
        drawCentered(9,  "    ####              ####        ", 3);                       
        drawCentered(10,  "    ####              ####        ", 3);           
        drawCentered(11,  "    ####              ####        ", 3);           
        drawCentered(12,  "    ####             #####        ", 3);          
        drawCentered(13,  "      ##################          ", 3);           
        drawCentered(14,  "          #############           ", 3);         
        drawCentered(15,  "                    #####         ", 3);       
        drawCentered(16,  "                      #####       ", 3);       
        drawCentered(17,  "                        ####      ", 3);         
        drawCentered(18,  "                         ####     ", 3);        
        drawCentered(19,  "                            ####  ", 3);        
                                                  
                                             

        drawCentered(22, "Movimiento: Flechas | Volver al Menú: Q");
        drawCentered(23, "Si tomás todas las pistas: VICTORIA.");
        drawCentered(24, "Si la sombra te alcanza: DERROTA.");
        drawCentered(25,"[ESPACIO] Volver al menú");
        refresh();
        int ch;
        while (state == GameState::INSTRUCTIONS) {
            ch = getch();
            if (ch == ' ' || ch == 'q' || ch == 'Q') state = GameState::MENU;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void pantallaVictoria() {
        clear();
        drawCentered(8, "***** YOU WIN !!! *****", 5);
        drawCentered(10,"Reuniste todas las pistas.");
    drawCentered(LINES - 3, "¡FELICIDADES, GANASTE! Pulsa ENTER para volver al menú", 5);

    int c;
    do { c = getch(); } while (c != '\n' && c != KEY_ENTER);
        drawCentered(12,"[ENTER] Jugar de nuevo   [Q] Menú");
        refresh();
        int ch;
        while (state == GameState::VICTORY) {
            ch = getch();
            if (ch == '\n' || ch == KEY_ENTER) { resetNivel(0); state = GameState::PLAYING; }
            if (ch == 'q' || ch == 'Q') state = GameState::MENU;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void pantallaGameOver() {
        clear();
        drawCentered(8, "GAME OVER", 2);

    int c;
    do { c = getch(); } while (c != '\n' && c != KEY_ENTER);
        drawCentered(10,"La sombra te atrapó.");

drawCentered(11,"´´´´´´´´´´´´´´´´´´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´`");
drawCentered(12,"´´´´´´´´´´´´´´´´´¶¶¶¶¶¶´´´´´´´´´´´´´¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´");
drawCentered(13,"´´´´´´´´´´´´´´¶¶¶¶´´´´´´´´´´´´´´´´´´´´´´´¶¶¶¶´´´´´´´´´´´´´´");
drawCentered(14,"´´´´´´´´´´´´´¶¶¶´´´´´´´´´´´´´´´´´´´´´´´´´´´´´¶¶´´´´´´´´´´´´");
drawCentered(15,"´´´´´´´´´´´´¶¶´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´¶¶´´´´´´´´´´´");
drawCentered(16,"´´´´´´´´´´´¶¶´´´´´´´´´´´´´´´´´´´´´`´´´´´´´´´´´¶¶´´´´´´´´´´`");
drawCentered(17,"´´´´´´´´´´¶¶´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´¶¶´´´´´´´´´´´");
drawCentered(18,"´´´´´´´´´´¶¶´¶¶´´´´´´´´´´´´´´´´´´´´´´´´´´´´´¶¶´¶¶´´´´´´´´´´");
drawCentered(19,"´´´´´´´´´´¶¶´¶¶´´´´´´´´´´´´´´´´´´´´´´´´´´´´´¶¶´´¶´´´´´´´´´´");
drawCentered(20,"´´´´´´´´´´¶¶´¶¶´´´´´´´´´´´´´´´´´´´´´´´´´´´´´¶¶´´¶´´´´´´´´´´");
drawCentered(21,"´´´´´´´´´´¶¶´´¶¶´´´´´´´´´´´´´´´´´´´´´´´´´´´´¶¶´¶¶´´´´´´´´´´");
drawCentered(22,"´´´´´´´´´´¶¶´´¶¶´´´´´´´´´´´´´´´´´´´´´´´´´´´¶¶´´¶¶´´´´´´´´´´");
drawCentered(23,"´´´´´´´´´´´¶¶´¶¶´´´¶¶¶¶¶¶¶¶´´´´´¶¶¶¶¶¶¶¶´´´¶¶´¶¶´´´´´´´´´´´");
drawCentered(24,"´´´´´´´´´´´´¶¶¶¶´¶¶¶¶¶¶¶¶¶¶´´´´´¶¶¶¶¶¶¶¶¶¶´¶¶¶¶¶´´´´´´´´´´´");
drawCentered(25,"´´´´´´´´´´´´´¶¶¶´¶¶¶¶¶¶¶¶¶¶´´´´´¶¶¶¶¶¶¶¶¶¶´¶¶¶´´´´´´´´´´´´´");
drawCentered(26,"´´´´´´´´´´´´´¶¶´´¶¶¶¶¶¶¶¶´´´´´´´¶¶¶¶¶¶¶¶¶´´¶¶´´´´´´´´´´´´´´");
drawCentered(27,"´´´´´´´´´´´´¶¶´´´¶¶¶¶¶¶¶´´´¶¶¶´´´¶¶¶¶¶¶¶´´´¶¶´´´´´´´´´´´´´´");
drawCentered(28,"´´´´´´´´´´´´¶¶´´´´´¶¶¶´´´´¶¶¶¶¶´´´´¶¶¶´´´´´¶¶´´´´´´´´´´´´´´");
drawCentered(29,"´´´´´´´´´´´´´¶¶´´´´´´´´´´¶¶¶¶¶¶¶´´´´´´´´´´¶¶´´´´´´´´´´´´´´´");
drawCentered(30,"´´´´´´´´´´´´´¶¶¶¶¶´´´´´´´¶¶¶¶¶¶¶´´´´´´´¶¶¶¶´´´´´´´´´´´´´´´´");

        drawCentered(33,"[ENTER] Reintentar   [Q] Menú");
        refresh();
        int ch;
        while (state == GameState::GAME_OVER) {
            ch = getch();
            if (ch == '\n' || ch == KEY_ENTER) { resetNivel(nivelActual); state = GameState::PLAYING; }
            if (ch == 'q' || ch == 'Q') state = GameState::MENU;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    Dir readInput() {
        int ch = getch();
        switch (ch) {
            case KEY_UP:    return Dir::UP;
            case KEY_DOWN:  return Dir::DOWN;
            case KEY_LEFT:  return Dir::LEFT;
            case KEY_RIGHT: return Dir::RIGHT;
            case 'q': case 'Q': state = GameState::MENU; return Dir::NONE;
            default: return Dir::NONE;
        }
    }

    void loopJuego() {
        timeout(0);
        while (state == GameState::PLAYING) {
            auto& room = niveles[nivelActual];
            Dir d = readInput();
            det.move(d, room);

            for (auto& p : pistas) {
                if (!p.tomada && p.pos.x == det.pos.x && p.pos.y == det.pos.y) {
                    p.tomada = true;
                    det.pistasTomadas++;
                }
            }

            sombra.step(room, det);
            if (sombra.pos.x == det.pos.x && sombra.pos.y == det.pos.y) {
                state = GameState::GAME_OVER;
            }

            bool all = std::all_of(pistas.begin(), pistas.end(), [](const Pista& p){return p.tomada;});
            if (all) state = GameState::VICTORY;

            clear();
            room.draw(PLAY_OFFSET_X, PLAY_OFFSET_Y);
            for (auto& p : pistas) p.draw(PLAY_OFFSET_X, PLAY_OFFSET_Y);
            sombra.draw(PLAY_OFFSET_X, PLAY_OFFSET_Y);
            det.draw(PLAY_OFFSET_X, PLAY_OFFSET_Y);
            refresh();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        timeout(-1);
    }
};

// ------------------------------ MAIN -----------------------------------------
int main() {
    initscr();
    cbreak(); noecho(); keypad(stdscr, TRUE); curs_set(0);
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);   // Detective
    init_pair(2, COLOR_RED, COLOR_BLACK);    // Sombra
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); // Pistas
    init_pair(4, COLOR_GREEN, COLOR_BLACK);  // Título
    init_pair(5, COLOR_WHITE, COLOR_BLACK);  // HUD/textos

    if (COLS < TERM_WIDTH || LINES < TERM_HEIGHT) {
        clear();
        mvprintw(1, 2, "Resolución insuficiente (%dx%d). Se requiere %dx%d.", COLS, LINES, TERM_WIDTH, TERM_HEIGHT);
        mvprintw(3, 2, "Ajustá el tamaño de la terminal y presioná ENTER para volver al menú.");
        refresh();
        while (getch() != '\n') {}
        endwin();
        return 0;
    }

    Juego juego;
    juego.init();
    juego.run();

    endwin();
    return 0;
}