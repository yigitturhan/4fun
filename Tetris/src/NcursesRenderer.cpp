#include "NcursesRenderer.h"
#include <ncurses.h>

NcursesRenderer::NcursesRenderer() {
}

NcursesRenderer::~NcursesRenderer() {
}

void NcursesRenderer::clear() {
    ::clear();
}

void NcursesRenderer::render(const Board& board,
                             const Piece& active,
                             const Piece& hold,
                             const PieceQueue& queue,
                             const ScoreManager& score,
                             GameState state) {  // ← state parametresi eklendi
    clear();
    
    // GAME OVER KONTROLÜ
    // GAME OVER
if (state == GameState::GameOver) {
    int centerX = 20;
    int centerY = 8;
    
    attron(COLOR_PAIR(5) | A_BOLD);
    mvprintw(centerY,     centerX, " ####    ##   #    # ######       ##   #      #  #####.  ##");
    mvprintw(centerY + 1, centerX, "#    #  #  #  ##  ## #           #  #   #     #  #       #  #");
    mvprintw(centerY + 2, centerX, "#      #    # # ## # #####     #     #   #    #  #####.  #   #");
    mvprintw(centerY + 3, centerX, "#  ### ###### #    # #         #     #    #   #  #       # #");
    mvprintw(centerY + 4, centerX, "#    # #    # #    # #          #   #      # #   #       #   #");
    mvprintw(centerY + 5, centerX, " ####  #    # #    # ######      ##         #    #####   #    #");
    attroff(COLOR_PAIR(5) | A_BOLD);
    
    attron(COLOR_PAIR(8));
    mvprintw(centerY + 8, centerX + 23, "Final Score: %d", score.getScore());
    mvprintw(centerY + 9, centerX + 23, "Final Level: %d", score.getLevel());
    mvprintw(centerY + 11, centerX + 23, "Press Q to quit");
    attroff(COLOR_PAIR(8));
    
    refresh();
    return;
}
    
    // PAUSE KONTROLÜ (İleride eklersin)
    if (state == GameState::Paused) {
        int centerX = 25;
        int centerY = 10;
        
        attron(COLOR_PAIR(2) | A_BOLD);  // Sarı, bold
        mvprintw(centerY, centerX, "╔═══════════════════════╗");
        mvprintw(centerY + 1, centerX, "║                       ║");
        mvprintw(centerY + 2, centerX, "║    GAME PAUSED        ║");
        mvprintw(centerY + 3, centerX, "║                       ║");
        mvprintw(centerY + 4, centerX, "╚═══════════════════════╝");
        attroff(COLOR_PAIR(2) | A_BOLD);
        
        attron(COLOR_PAIR(8));
        mvprintw(centerY + 6, centerX, "  Press P to continue");
        mvprintw(centerY + 7, centerX, "  Press Q to quit");
        attroff(COLOR_PAIR(8));
        
        refresh();
        return;
    }
    
    // NORMAL OYUN RENDER'I
    int boardStartX = 2;
    int boardStartY = 2;
    int boardWidth = 10;
    int boardHeight = 20;
    
    mvprintw(boardStartY - 1, boardStartX, "+");
    for (int x = 0; x < boardWidth * 2; x++) {
        printw("-");
    }
    printw("+");
    
    for (int y = 2; y < 22; y++) {
        int screenY = boardStartY + (y - 2);
        mvprintw(screenY, boardStartX, "|");
        
        for (int x = 0; x < boardWidth; x++) {
            int cellValue = board.grid[y][x];
            
            if (cellValue > 0) {
                attron(COLOR_PAIR(cellValue));
                printw("[]");
                attroff(COLOR_PAIR(cellValue));
            } else {
                printw("  ");
            }
        }
        
        printw("|");
    }
    
    mvprintw(boardStartY + boardHeight, boardStartX, "+");
    for (int x = 0; x < boardWidth * 2; x++) {
        printw("-");
    }
    printw("+");
    
    const auto& blocks = active.getBlocks();
    int pieceColor = static_cast<int>(active.getType()) + 1;
    attron(COLOR_PAIR(pieceColor));
    
    for (const auto& block : blocks) {
        int worldX = active.getX() + block.first;
        int worldY = active.getY() + block.second;
        
        if (worldY >= 2 && worldY < 22 && worldX >= 0 && worldX < boardWidth) {
            int screenX = boardStartX + 1 + (worldX * 2);
            int screenY = boardStartY + (worldY - 2);
            mvprintw(screenY, screenX, "[]");
        }
    }
    attroff(COLOR_PAIR(pieceColor));
    
    int infoX = boardStartX + (boardWidth * 2) + 5;
    
    mvprintw(2, infoX, "Score: %d", score.getScore());
    mvprintw(3, infoX, "Level: %d", score.getLevel());
    
    mvprintw(5, infoX, "Next:");
    Piece nextPiece = queue.peekNext();
    const auto& nextBlocks = nextPiece.getBlocks();
    int nextColor = static_cast<int>(nextPiece.getType()) + 1;
    attron(COLOR_PAIR(nextColor));
    for (const auto& block : nextBlocks) {
        mvprintw(6 + block.second, infoX + (block.first * 2), "[]");
    }
    attroff(COLOR_PAIR(nextColor));
    
    mvprintw(11, infoX, "Hold:");
    if (hold.getX() != -100) {
        const auto& holdBlocks = hold.getBlocks();
        int holdColor = static_cast<int>(hold.getType()) + 1;
        attron(COLOR_PAIR(holdColor));
        for (const auto& block : holdBlocks) {
            mvprintw(12 + block.second, infoX + (block.first * 2), "[]");
        }
        attroff(COLOR_PAIR(holdColor));
    }
    
    mvprintw(17, infoX, "Controls:");
    mvprintw(18, infoX, "Arrows: Move");
    mvprintw(19, infoX, "Space: Drop");
    mvprintw(20, infoX, "Z/X: Rotate");
    mvprintw(21, infoX, "C: Hold");
    mvprintw(22, infoX, "P: Pause");
    mvprintw(23, infoX, "Q: Quit");
    
    refresh();
}