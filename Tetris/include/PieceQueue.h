#ifndef PIECEQUEUE_H
#define PIECEQUEUE_H

#include <queue>
#include "Piece.h"

class PieceQueue {
public:
    PieceQueue();

    Piece next();
    Piece peekNext() const;

private:
    std::queue<Piece> queue;
    void generateBag();
};

#endif
