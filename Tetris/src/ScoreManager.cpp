#include "ScoreManager.h"

ScoreManager::ScoreManager() {
    score = 0;
    level = 1;
}

void ScoreManager::addLinesCleared(int count) {
    int points = 0;
    
    switch(count) {
        case 1:
            points = 100 * level;
            break;
        case 2:
            points = 300 * level;
            break;
        case 3:
            points = 500 * level;
            break;
        case 4:
            points = 800 * level;
            break;
        default:
            points = 0;
            break;
    }
    
    score += points;
    static int totalLinesCleared = 0;
    totalLinesCleared += count;
    
    int newLevel = (totalLinesCleared / 10) + 1;
    if (newLevel > level) {
        level = newLevel;
    }
}

void ScoreManager::addSoftDrop(int amount) {
    score += amount * 1;
}

void ScoreManager::addHardDrop(int amount) {
    score += amount * 2;
}

int ScoreManager::getScore() const {
    return score;
}

int ScoreManager::getLevel() const {
    return level;
}
