#include "InputHandler.h"
#include <ncurses.h>

InputHandler::InputHandler() {
    // ncurses'i başlat
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    
    // Renk desteğini başlat
    start_color();
    
    // Renk çiftlerini tanımla
    init_pair(1, COLOR_CYAN, COLOR_BLACK);      // I parçası
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);    // O parçası
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);   // T parçası
    init_pair(4, COLOR_GREEN, COLOR_BLACK);     // S parçası
    init_pair(5, COLOR_RED, COLOR_BLACK);       // Z parçası
    init_pair(6, COLOR_BLUE, COLOR_BLACK);      // J parçası
    init_pair(7, COLOR_WHITE, COLOR_BLACK);     // L parçası
    init_pair(8, COLOR_WHITE, COLOR_BLACK);     // Genel
}

int InputHandler::pollEvent() {
    const int EVENT_NONE = 0;
    const int EVENT_MOVE_LEFT = 1;
    const int EVENT_MOVE_RIGHT = 2;
    const int EVENT_SOFT_DROP = 3;
    const int EVENT_HARD_DROP = 4;
    const int EVENT_ROTATE_CW = 5;
    const int EVENT_ROTATE_CCW = 6;
    const int EVENT_HOLD = 7;
    const int EVENT_PAUSE = 8;
    const int EVENT_QUIT = 9;
    
    int ch = getch();
    
    switch(ch) {
        case KEY_LEFT:
        case 'a':
        case 'A':
            return EVENT_MOVE_LEFT;
            
        case KEY_RIGHT:
        case 'd':
        case 'D':
            return EVENT_MOVE_RIGHT;
            
        case KEY_DOWN:
        case 's':
        case 'S':
            return EVENT_SOFT_DROP;
            
        case ' ':
            return EVENT_HARD_DROP;
            
        case KEY_UP:
        case 'w':
        case 'W':
        case 'x':
        case 'X':
            return EVENT_ROTATE_CW;
            
        case 'z':
        case 'Z':
            return EVENT_ROTATE_CCW;
            
        case 'c':
        case 'C':
            return EVENT_HOLD;
            
        case 'p':
        case 'P':
            return EVENT_PAUSE;
            
        case 'q':
        case 'Q':
        case 27:
            return EVENT_QUIT;
            
        case ERR:
        default:
            return EVENT_NONE;
    }
}