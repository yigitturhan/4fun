#include "Board.h"

Board::Board(int width, int height) {
    this->width = width;
    this->height = height;
    createGrid();
}

void Board::createGrid() {
    for (int i = 0; i < height; i++) {
        std::vector<int> row;
        for (int j = 0; j < width; j++) {
            row.push_back(0);
        }
        this->grid.push_back(row);
    }
}

bool Board::isCellEmpty(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return false;
    }
    return this->grid[y][x] == 0;
}

bool Board::checkCollision(const Piece& piece, int offX, int offY) const {
    const auto& blocks = piece.getBlocks();
    
    for (int i = 0; i < blocks.size(); i++) {
        int point_x = piece.getX() + blocks[i].first + offX;
        int point_y = piece.getY() + blocks[i].second + offY;
        
        if (!isCellEmpty(point_x, point_y)) {
            return true;
        }
    }
    return false;
}

void Board::placePiece(const Piece& piece) {
    const auto& blocks = piece.getBlocks();
    
    for (int i = 0; i < blocks.size(); i++) {
        int point_x = piece.getX() + blocks[i].first;
        int point_y = piece.getY() + blocks[i].second;
        
        if (point_x >= 0 && point_x < width && 
            point_y >= 0 && point_y < height) {
            grid[point_y][point_x] = static_cast<int>(piece.getType()) + 1;
        }
    }
}

bool Board::isLineFull(int y) const {
    for (int x = 0; x < this->width; x++) {
        if (this->grid[y][x] == 0) {
            return false;
        }
    }
    return true;
}

int Board::clearFullLines() {
    std::vector<std::vector<int>> newGrid;
    int clearedCount = 0;
    
    for (int y = 0; y < height; y++) {
        if (!isLineFull(y)) {
            newGrid.push_back(grid[y]);
        } else {
            clearedCount++;
        }
    }
    
    while (newGrid.size() < height) {
        std::vector<int> emptyRow(width, 0);
        newGrid.insert(newGrid.begin(), emptyRow);
    }
    
    grid = newGrid;
    return clearedCount;
}