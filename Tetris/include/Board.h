#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Piece.h"

class Board {
public:
    Board(int width = 10, int height = 22);

    bool isCellEmpty(int x, int y) const;
    bool checkCollision(const Piece& piece, int offX, int offY) const;
    void placePiece(const Piece& piece);
    int clearFullLines();

    friend class NcursesRenderer;
    friend class AnsiRenderer;

private:
    int width, height;
    std::vector<std::vector<int>> grid;
    void createGrid();
    bool isLineFull(int y) const;
};

#endif
