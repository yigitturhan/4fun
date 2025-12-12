#ifndef RENDERERINTERFACE_H
#define RENDERERINTERFACE_H

#include "Board.h"
#include "Piece.h"
#include "PieceQueue.h"
#include "ScoreManager.h"
#include "GameManager.h"  // GameState için

class RendererInterface {
public:
    virtual ~RendererInterface() = default;

    virtual void clear() = 0;
    virtual void render(const Board& board,
                        const Piece& active,
                        const Piece& hold,
                        const PieceQueue& queue,
                        const ScoreManager& score,
                        GameState state) = 0;  // ← state eklendi
};

#endif