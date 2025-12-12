#include "PieceQueue.h"
#include <algorithm>
#include <random>

PieceQueue::PieceQueue() {
    generateBag();
}

void PieceQueue::generateBag() {
    std::vector<PieceType> bag = {
        PieceType::I,
        PieceType::O,
        PieceType::T,
        PieceType::S,
        PieceType::Z,
        PieceType::J,
        PieceType::L
    };

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(bag.begin(), bag.end(), g);

    for (auto type : bag) {
        queue.push(Piece(type));
    }
}

Piece PieceQueue::next() {
    Piece piece = queue.front();
    queue.pop();
    
    if (queue.size() < 7) {
        generateBag();
    }
    
    return piece;
}

Piece PieceQueue::peekNext() const {
    return queue.front();
}