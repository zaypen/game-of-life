#include "InputManager.h"

InputManager::InputManager(World& world, Window& window, Renderer& renderer) : world(world), window(window),
                                                                               renderer(renderer), originX(0),
                                                                               originY(0), mousePressed(false) {
    normal.loadFromSystem(Cursor::Arrow);
    hand.loadFromSystem(Cursor::Hand);
}

void InputManager::KeyPressed(const Event::KeyEvent& event) {
    switch (event.code) {
        case Keyboard::Escape:
            window.close();
            break;
        case Keyboard::Space:
            world.SetPaused(!world.IsPaused());
            break;
        default:
            break;
    }
}

void InputManager::KeyReleased(const Event::KeyEvent& event) {

}

void InputManager::MouseButtonPressed(const Event::MouseButtonEvent& event) {
    mousePressed = event.button == Mouse::Button::Left ?: false;
    originX = mousePressed ? event.x : originX;
    originY = mousePressed ? event.y : originY;
    window.setMouseCursor(mousePressed ? hand : normal);
    window.setMouseCursorGrabbed(mousePressed);
}

void InputManager::MouseButtonReleased(const Event::MouseButtonEvent& event) {
    mousePressed = event.button != Mouse::Button::Left ?: false;
    window.setMouseCursor(mousePressed ? hand : normal);
    window.setMouseCursorGrabbed(mousePressed);
}

void InputManager::MouseMoved(const Event::MouseMoveEvent& event) {
    if (!mousePressed) return;
    renderer.Move(-(event.x - originX) / 1.f, -(event.y - originY) / 1.f);
    originX = event.x;
    originY = event.y;
}

void InputManager::MouseWheelScrolled(const Event::MouseWheelScrollEvent& event) {
    if (event.wheel == Mouse::Wheel::VerticalWheel) {
        renderer.Zoom(event.delta * 0.01f);
    }
}
