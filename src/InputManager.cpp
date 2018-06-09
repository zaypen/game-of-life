#include "InputManager.h"

InputManager::InputManager(World& world, Window& window, Renderer& renderer) : world(world), window(window),
                                                                               renderer(renderer), originX(0),
                                                                               originY(0), leftButtonPressed(false) {
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
            renderer.SetEditing(world.IsPaused());
            break;
        case Keyboard::F:
            if (renderer.IsEditing() && renderer.IsCursorValid()) {
                auto cursor = renderer.GetCursor();
                auto x = static_cast<uint32_t>(cursor.x), y = static_cast<uint32_t>(cursor.y);
                world.SetCell(x, y, world.GetCell(x, y) ? uint8_t(0) : uint8_t(1));
            }
            break;
        default:
            break;
    }
}

void InputManager::KeyReleased(const Event::KeyEvent& event) {

}

void InputManager::MouseButtonPressed(const Event::MouseButtonEvent& event) {
    leftButtonPressed = event.button == Mouse::Button::Left ?: false;
    originX = leftButtonPressed ? event.x : originX;
    originY = leftButtonPressed ? event.y : originY;
    UpdateMouseCursor();
}

void InputManager::MouseButtonReleased(const Event::MouseButtonEvent& event) {
    leftButtonPressed = event.button != Mouse::Button::Left ?: false;
    UpdateMouseCursor();
}

void InputManager::UpdateMouseCursor() {
    window.setMouseCursor(leftButtonPressed ? hand : normal);
    window.setMouseCursorGrabbed(leftButtonPressed);
}

void InputManager::MouseMoved(const Event::MouseMoveEvent& event) {
    if (world.IsPaused()) {
        renderer.MouseMoved(Mouse::getPosition(window));
    }
    if (leftButtonPressed) {
        renderer.Move(-(event.x - originX) / 1.f, -(event.y - originY) / 1.f);
        originX = event.x;
        originY = event.y;
    }
}

void InputManager::MouseWheelScrolled(const Event::MouseWheelScrollEvent& event) {
    if (event.wheel == Mouse::Wheel::VerticalWheel) {
        renderer.Zoom(event.delta * 0.01f);
    } else {
        auto di = event.delta == 0 ? 0 : event.delta > 0 ? 100 : -100;
        world.SetInterval(world.GetInterval() - di);
    }
}
