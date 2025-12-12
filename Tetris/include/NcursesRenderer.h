#ifndef NCURSESRENDERER_H
#define NCURSESRENDERER_H

#include "RendererInterface.h"

class NcursesRenderer : public RendererInterface {
public:
    NcursesRenderer();
    ~NcursesRenderer();

    void clear() override;
    void render(const Board& board,
                const Piece& active,
                const Piece& hold,
                const PieceQueue& queue,
                const ScoreManager& score,
                GameState state) override;  // ← state eklendi
};

#endif