#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Board.h"
#include "Piece.h"
#include "PieceQueue.h"
#include "ScoreManager.h"
#include "Timer.h"

enum class GameState { Running, Paused, GameOver };

class GameManager {
public:
    GameManager();
    void start();
    void update(double deltaTime);
    void handleInput(int event);
    void reset();

    GameState state;
    Board board;
    Piece activePiece;
    Piece holdPiece;
    PieceQueue queue;
    ScoreManager scoreManager;
    Timer timer;

private:

    void spawnPiece();
    void lockPiece();
};

#endif
