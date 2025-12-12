#ifndef PIECEDEFINITIONS_H
#define PIECEDEFINITIONS_H

#include <vector>
#include <map>
#include "Piece.h"

namespace PieceDefinitions {
    extern std::map<PieceType, std::vector<std::vector<std::pair<int,int>>>> shapes;
    extern std::map<PieceType, std::vector<std::vector<std::pair<int,int>>>> srsKicks;
}

#endif
