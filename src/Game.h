#ifndef GAME_OF_LIFE_GAME_H
#define GAME_OF_LIFE_GAME_H


#include <cstdint>
#include <SFML/Graphics.hpp>
#include "World.h"
#include "InputManager.h"
#include "Renderer.h"

using namespace sf;

class Game {
public:
    Game() : Game(40, 30) {}
    Game(uint32_t width, uint32_t height);

    void Run();

private:
    void HandleEvents();

private:
    World world;
    RenderWindow renderWindow;
    Renderer renderer;
    InputManager input;
};


#endif //GAME_OF_LIFE_GAME_H
