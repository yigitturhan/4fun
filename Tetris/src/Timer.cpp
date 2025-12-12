#include "Timer.h"

Timer::Timer() {
    gravityCounter = 0.0;
    lockCounter = 0.0;
}

void Timer::update(double deltaTime) {
    gravityCounter += deltaTime;
    lockCounter += deltaTime;
}

bool Timer::gravityTick() {
    double gravityInterval = 0.5;
    if (gravityCounter >= gravityInterval) {
        gravityCounter = 0.0;
        return true;
    }
    return false;
}

bool Timer::lockDelayExpired() {
    double lockDelay = 0.5;
    if (lockCounter >= lockDelay) {
        lockCounter = 0.0;
        return true;
    }
    return false;
}

void Timer::setLevel(int level) {
    currentLevel = level;
}

void Timer::resetLockCounter() {
    lockCounter = 0.0;
}