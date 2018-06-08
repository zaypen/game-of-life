#include "InputManager.h"

void InputManager::KeyPressed(const Event::KeyEvent& event) {
    switch (event.code) {
        case Keyboard::Escape:
            window.close();
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
    window.setMouseCursorGrabbed(mousePressed);
}

void InputManager::MouseButtonReleased(const Event::MouseButtonEvent& event) {
    mousePressed = event.button != Mouse::Button::Left ?: false;
    window.setMouseCursorGrabbed(mousePressed);
}

void InputManager::MouseMoved(const Event::MouseMoveEvent& event) {
    if (!mousePressed) return;
    renderer.Move(-(event.x - originX) / 1.f, -(event.y - originY) / 1.f);
    originX = event.x;
    originY = event.y;
}

void InputManager::MouseWheelScrolled(const Event::MouseWheelScrollEvent& event) {
    renderer.Move(event.wheel == Mouse::Wheel::HorizontalWheel ? event.delta : 0,
                  event.wheel == Mouse::Wheel::VerticalWheel ? event.delta : 0);
}
