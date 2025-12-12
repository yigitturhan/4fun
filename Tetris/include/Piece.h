#ifndef PIECE_H
#define PIECE_H

#include <vector>

enum class PieceType { I, O, T, S, Z, J, L };

class Board;

class Piece {
public:
    Piece(PieceType type = PieceType::I);
    
    void rotateCW(const Board& board);
    void rotateCCW(const Board& board);
    const std::vector<std::pair<int,int>>& getBlocks() const;
    
    PieceType getType() const;
    int getX() const;
    int getY() const;
    int getRotation() const;
    
    void setPosition(int x, int y);

private:
    PieceType type;
    int x, y;
    int rotation;
};

#endif