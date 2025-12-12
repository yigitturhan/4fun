#include "Piece.h"
#include "PieceDefinitions.h"
#include "Board.h"

Piece::Piece(PieceType type) {
    this->type = type;
    this->x = -1;
    this->y = -1;
    this->rotation = 0;
}

void Piece::rotateCW(const Board& board) {
    int new_rotation = (rotation + 1) % 4;
    if (this->type == PieceType::O) return;
    auto kicks = PieceDefinitions::srsKicks[this->type][this->rotation];
    for (int i = 0; i < kicks.size(); i++){
        int test_x = this->x + kicks[i].first;
        int test_y = this->y + kicks[i].second;
        Piece tempPiece(this->type);
        tempPiece.rotation = new_rotation;
        tempPiece.setPosition(this->x, this->y);
        if (!board.checkCollision(tempPiece, kicks[i].first, kicks[i].second)){
            this->rotation = new_rotation;
            this->x += kicks[i].first;
            this->y += kicks[i].second;
            return;
        }
    }
}

void Piece::rotateCCW(const Board& board) {
    int new_rotation = (rotation + 3) % 4;
    if (this->type == PieceType::O) return;
    auto kicks = PieceDefinitions::srsKicks[this->type][this->rotation];
    for (int i = 0; i < kicks.size(); i++){
        int test_x = this->x + kicks[i].first;
        int test_y = this->y + kicks[i].second;
        Piece tempPiece(this->type);
        tempPiece.rotation = new_rotation;
        tempPiece.setPosition(this->x, this->y);
        if (!board.checkCollision(tempPiece, kicks[i].first, kicks[i].second)){
            this->rotation = new_rotation;
            this->x += kicks[i].first;
            this->y += kicks[i].second;
            return;
        }

    }
}

const std::vector<std::pair<int,int>>& Piece::getBlocks() const {
    return PieceDefinitions::shapes[this->type][this->rotation];
}

PieceType Piece::getType() const {
    return type;
}

int Piece::getX() const {
    return x;
}

int Piece::getY() const {
    return y;
}

int Piece::getRotation() const {
    return rotation;
}

void Piece::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}