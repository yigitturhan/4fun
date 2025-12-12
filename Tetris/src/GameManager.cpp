#include "GameManager.h"

GameManager::GameManager() {
    state = GameState::Running;
    board = Board(10, 22);
    queue = PieceQueue();
    scoreManager = ScoreManager();
    timer = Timer();
    
    holdPiece = Piece(PieceType::I);
    holdPiece.setPosition(-100, -100);
}

void GameManager::start() {
    state = GameState::Running;
    board = Board(10, 22);
    queue = PieceQueue();
    scoreManager = ScoreManager();
    timer = Timer();
    spawnPiece();
}

void GameManager::update(double deltaTime) {
    if (state != GameState::Running) return;
    
    timer.update(deltaTime);
    timer.setLevel(scoreManager.getLevel());
    
    if (timer.gravityTick()) {
        if (!board.checkCollision(activePiece, 0, 1)) {
            activePiece.setPosition(activePiece.getX(), activePiece.getY() + 1);
            timer.resetLockCounter();
        }
    }
    
    if (board.checkCollision(activePiece, 0, 1)) {
        if (timer.lockDelayExpired()) lockPiece();
    }
    else timer.resetLockCounter();
}

void GameManager::handleInput(int event) {
    if (state != GameState::Running) return;
    
    const int EVENT_MOVE_LEFT = 1;
    const int EVENT_MOVE_RIGHT = 2;
    const int EVENT_SOFT_DROP = 3;
    const int EVENT_HARD_DROP = 4;
    const int EVENT_ROTATE_CW = 5;
    const int EVENT_ROTATE_CCW = 6;
    const int EVENT_HOLD = 7;
    const int EVENT_PAUSE = 8;
    
    switch(event) {
        case EVENT_MOVE_LEFT:
            if (!board.checkCollision(activePiece, -1, 0)) {
                activePiece.setPosition(activePiece.getX() - 1, activePiece.getY());
                timer.resetLockCounter();
            }
            break;
            
        case EVENT_MOVE_RIGHT:
            if (!board.checkCollision(activePiece, 1, 0)) {
                activePiece.setPosition(activePiece.getX() + 1, activePiece.getY());
                timer.resetLockCounter();
            }
            break;
            
        case EVENT_SOFT_DROP:
            if (!board.checkCollision(activePiece, 0, 1)) {
                activePiece.setPosition(activePiece.getX(), activePiece.getY() + 1);
                scoreManager.addSoftDrop(1);  // 1 puan
                timer.resetLockCounter();
            }
            break;
            
        case EVENT_HARD_DROP:
            {
                int dropDistance = 0;
                while (!board.checkCollision(activePiece, 0, 1)) {
                    activePiece.setPosition(activePiece.getX(), activePiece.getY() + 1);
                    dropDistance++;
                }
                scoreManager.addHardDrop(dropDistance);
                lockPiece();
            }
            break;
            
        case EVENT_ROTATE_CW:
            activePiece.rotateCW(board);
            timer.resetLockCounter();
            break;
            
        case EVENT_ROTATE_CCW:
            activePiece.rotateCCW(board);
            timer.resetLockCounter();
            break;
            
        case EVENT_HOLD:
            break;
            
        case EVENT_PAUSE:
            if (state == GameState::Running) state = GameState::Paused;
            else if (state == GameState::Paused) state = GameState::Running;
            break;
    }
}

void GameManager::reset() {
    start();
}

void GameManager::spawnPiece() {
    activePiece = queue.next();
    int startX = (10 / 2) - 2;
    int startY = 0;
    activePiece.setPosition(startX, startY);
    if (board.checkCollision(activePiece, 0, 0)) state = GameState::GameOver;
}

void GameManager::lockPiece() {
    board.placePiece(activePiece);
    int linesCleared = board.clearFullLines();
    if (linesCleared > 0) scoreManager.addLinesCleared(linesCleared);
    spawnPiece();
}