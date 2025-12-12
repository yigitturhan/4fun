#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

class ScoreManager {
public:
    ScoreManager();

    void addLinesCleared(int count);
    void addSoftDrop(int amount);
    void addHardDrop(int amount);

    int getScore() const;
    int getLevel() const;

private:
    int score;
    int level;
};

#endif
