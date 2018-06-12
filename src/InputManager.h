#ifndef GAME_OF_LIFE_INPUT_MANAGER_H
#define GAME_OF_LIFE_INPUT_MANAGER_H

#include <SFML/Window.hpp>
#include "World.h"
#include "Renderer.h"

using namespace sf;

class InputManager {
public:
    explicit InputManager(World& world, Window& window, Renderer& renderer);

    void KeyPressed(const Event::KeyEvent& event);
    void KeyReleased(const Event::KeyEvent& event);

    void MouseButtonPressed(const Event::MouseButtonEvent& event);
    void MouseButtonReleased(const Event::MouseButtonEvent& event);
    void MouseMoved(const Event::MouseMoveEvent& event);
    void MouseWheelScrolled(const Event::MouseWheelScrollEvent& event);

protected:
    void ToggleCursor();
    void FillRandomly();
    void UpdateMouseCursor();
private:
    World& world;
    Window& window;
    Renderer& renderer;
    int32_t originX, originY;
    bool leftButtonPressed;
};


#endif //GAME_OF_LIFE_INPUT_MANAGER_H
