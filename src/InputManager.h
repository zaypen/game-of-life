#ifndef GAME_OF_LIFE_INPUT_MANAGER_H
#define GAME_OF_LIFE_INPUT_MANAGER_H

#include <SFML/Window.hpp>
#include "World.h"
#include "Renderer.h"

using namespace sf;

class InputManager {
public:
    explicit InputManager(World& world, Window& window, Renderer& renderer);

    void keyPressed(const Event::KeyEvent &event);
    void keyReleased(const Event::KeyEvent &event);

    void mouseButtonPressed(const Event::MouseButtonEvent &event);
    void mouseButtonReleased(const Event::MouseButtonEvent &event);
    void mouseMoved(const Event::MouseMoveEvent &event);
    void mouseWheelScrolled(const Event::MouseWheelScrollEvent &event);

protected:
    void toggleCursor();
    void fillRandomly();
    void updateMouseCursor();
private:
    World& world;
    Window& window;
    Renderer& renderer;
    int32_t originX, originY;
    bool leftButtonPressed;
};


#endif //GAME_OF_LIFE_INPUT_MANAGER_H
