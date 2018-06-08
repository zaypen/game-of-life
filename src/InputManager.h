#ifndef GAME_OF_LIFE_INPUT_MANAGER_H
#define GAME_OF_LIFE_INPUT_MANAGER_H

#include <SFML/Window.hpp>

using namespace sf;

class World;

class InputManager {
public:
    explicit InputManager(Window& window, World& world) : window(window), world(world) {}

    void KeyPressed(const Event::KeyEvent& event);
    void KeyReleased(const Event::KeyEvent& event);
private:
    Window& window;
    World& world;
};


#endif //GAME_OF_LIFE_INPUT_MANAGER_H
