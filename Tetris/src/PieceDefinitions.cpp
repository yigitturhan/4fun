#include "PieceDefinitions.h"

namespace PieceDefinitions {
    // Tetromino shapes for all 7 pieces with 4 rotation states each
    // Coordinates are relative to piece origin (rotation center)
    // Format: shapes[PieceType][rotation_state] = vector of (x, y) pairs
    
    std::map<PieceType, std::vector<std::vector<std::pair<int,int>>>> shapes = {
        // I piece - Light Blue/Cyan
        // Rotates around center point
        {PieceType::I, {
            // State 0: Horizontal ----
            {{0, 1}, {1, 1}, {2, 1}, {3, 1}},
            // State 1: Vertical
            {{2, 0}, {2, 1}, {2, 2}, {2, 3}},
            // State 2: Horizontal (shifted)
            {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
            // State 3: Vertical (shifted)
            {{1, 0}, {1, 1}, {1, 2}, {1, 3}}
        }},
        
        // O piece - Yellow
        // Doesn't rotate (same in all states)
        {PieceType::O, {
            // State 0: Square
            {{1, 0}, {2, 0}, {1, 1}, {2, 1}},
            // State 1: Same
            {{1, 0}, {2, 0}, {1, 1}, {2, 1}},
            // State 2: Same
            {{1, 0}, {2, 0}, {1, 1}, {2, 1}},
            // State 3: Same
            {{1, 0}, {2, 0}, {1, 1}, {2, 1}}
        }},
        
        // T piece - Purple/Magenta
        {PieceType::T, {
            // State 0: T pointing up
            {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
            // State 1: T pointing right
            {{1, 0}, {1, 1}, {2, 1}, {1, 2}},
            // State 2: T pointing down
            {{0, 1}, {1, 1}, {2, 1}, {1, 2}},
            // State 3: T pointing left
            {{1, 0}, {0, 1}, {1, 1}, {1, 2}}
        }},
        
        // S piece - Green
        {PieceType::S, {
            // State 0: Horizontal S
            {{1, 0}, {2, 0}, {0, 1}, {1, 1}},
            // State 1: Vertical S
            {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
            // State 2: Horizontal S (shifted)
            {{1, 1}, {2, 1}, {0, 2}, {1, 2}},
            // State 3: Vertical S (shifted)
            {{0, 0}, {0, 1}, {1, 1}, {1, 2}}
        }},
        
        // Z piece - Red
        {PieceType::Z, {
            // State 0: Horizontal Z
            {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
            // State 1: Vertical Z
            {{2, 0}, {1, 1}, {2, 1}, {1, 2}},
            // State 2: Horizontal Z (shifted)
            {{0, 1}, {1, 1}, {1, 2}, {2, 2}},
            // State 3: Vertical Z (shifted)
            {{1, 0}, {0, 1}, {1, 1}, {0, 2}}
        }},
        
        // J piece - Blue
        {PieceType::J, {
            // State 0: J with tail on left
            {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
            // State 1: J rotated right
            {{1, 0}, {2, 0}, {1, 1}, {1, 2}},
            // State 2: J upside down
            {{0, 1}, {1, 1}, {2, 1}, {2, 2}},
            // State 3: J rotated left
            {{1, 0}, {1, 1}, {0, 2}, {1, 2}}
        }},
        
        // L piece - Orange
        {PieceType::L, {
            // State 0: L with tail on right
            {{2, 0}, {0, 1}, {1, 1}, {2, 1}},
            // State 1: L rotated right
            {{1, 0}, {1, 1}, {1, 2}, {2, 2}},
            // State 2: L upside down
            {{0, 1}, {1, 1}, {2, 1}, {0, 2}},
            // State 3: L rotated left
            {{0, 0}, {1, 0}, {1, 1}, {1, 2}}
        }}
    };

    // SRS (Super Rotation System) Kick Tables
    // When rotation fails, try these offset tests in order
    // Format: (x_offset, y_offset) where positive x is right, positive y is down
    
    std::map<PieceType, std::vector<std::vector<std::pair<int,int>>>> srsKicks = {
        // JLSTZ pieces use the same kick table
        // Kick table for 0->1 (spawn state to right)
        {PieceType::J, {
            // Test 0: No offset (already tried)
            {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}},  // 0->R
            {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},    // R->2
            {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}},     // 2->L
            {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}}  // L->0
        }},
        
        {PieceType::L, {
            {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}},  // 0->R
            {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},    // R->2
            {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}},     // 2->L
            {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}}  // L->0
        }},
        
        {PieceType::S, {
            {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}},  // 0->R
            {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},    // R->2
            {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}},     // 2->L
            {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}}  // L->0
        }},
        
        {PieceType::Z, {
            {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}},  // 0->R
            {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},    // R->2
            {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}},     // 2->L
            {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}}  // L->0
        }},
        
        {PieceType::T, {
            {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}},  // 0->R
            {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},    // R->2
            {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}},     // 2->L
            {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}}  // L->0
        }},
        
        // I piece has different kick table
        {PieceType::I, {
            {{0, 0}, {-2, 0}, {1, 0}, {-2, 1}, {1, -2}},   // 0->R
            {{0, 0}, {-1, 0}, {2, 0}, {-1, -2}, {2, 1}},   // R->2
            {{0, 0}, {2, 0}, {-1, 0}, {2, -1}, {-1, 2}},   // 2->L
            {{0, 0}, {1, 0}, {-2, 0}, {1, 2}, {-2, -1}}    // L->0
        }},
        
        // O piece doesn't need kicks (doesn't rotate)
        {PieceType::O, {
            {{0, 0}},
            {{0, 0}},
            {{0, 0}},
            {{0, 0}}
        }}
    };
}