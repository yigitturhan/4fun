#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class InputHandler {
public:
    InputHandler();

    int pollEvent(); // returns custom event code
};

#endif
