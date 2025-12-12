#include "GameManager.h"
#include "InputHandler.h"
#include "NcursesRenderer.h"
#include <chrono>
#include <thread>

int main() {
    const int EVENT_NONE = 0;
    const int EVENT_QUIT = 9;
    
    InputHandler input;
    NcursesRenderer renderer;
    
    GameManager game;
    game.start();
    
    auto lastTime = std::chrono::high_resolution_clock::now();
    bool running = true;
    
    while (running) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = currentTime - lastTime;
        double deltaTime = elapsed.count();
        lastTime = currentTime;
        
        int event = input.pollEvent();
        
        if (event == EVENT_QUIT) {
            running = false;
            continue;
        }
        
        if (event != EVENT_NONE) {
            game.handleInput(event);
        }
        
        game.update(deltaTime);
        
        renderer.render(game.board, 
                       game.activePiece, 
                       game.holdPiece, 
                       game.queue, 
                       game.scoreManager,
                       game.state);  // ← state eklendi
        
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    
    return 0;
}