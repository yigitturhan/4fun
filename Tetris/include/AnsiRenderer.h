#ifndef ANSIRENDERER_H
#define ANSIRENDERER_H

#include "RendererInterface.h"

class AnsiRenderer : public RendererInterface {
public:
    void clear() override;
    void render(const Board& board,
                const Piece& active,
                const Piece& hold,
                const PieceQueue& queue,
                const ScoreManager& score) override;
};

#endif
