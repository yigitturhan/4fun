#ifndef TIMER_H
#define TIMER_H

class Timer {
public:
    Timer();

    void update(double deltaTime);
    bool gravityTick();
    bool lockDelayExpired();
    void setLevel(int level);
    void resetLockCounter();

private:
    double gravityCounter;
    double lockCounter;
    int currentLevel;
};

#endif
