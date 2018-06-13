#include "InputManager.h"

InputManager::InputManager(World& world, Window& window, Renderer& renderer) : world(world), window(window),
                                                                               renderer(renderer), originX(0),
                                                                               originY(0), leftButtonPressed(false) {
}

void InputManager::keyPressed(const Event::KeyEvent &event) {
    switch (event.code) {
        case Keyboard::Escape:
            window.close();
            break;
        case Keyboard::Space:
            world.setPaused(!world.isPaused());
            renderer.setEditing(world.isPaused());
            break;
        case Keyboard::A:
            world.setInterval(world.getInterval() + 100);
            break;
        case Keyboard::D:
            world.setInterval(world.getInterval() - 100);
            break;
        case Keyboard::W:
            renderer.zoom(-0.1f);
            break;
        case Keyboard::S:
            renderer.zoom(0.1f);
            break;
        case Keyboard::F:
            toggleCursor();
            break;
        case Keyboard::F5:
            fillRandomly();
            break;
        default:
            break;
    }
}

void InputManager::keyReleased(const Event::KeyEvent &event) {

}

void InputManager::mouseButtonPressed(const Event::MouseButtonEvent &event) {
    leftButtonPressed = event.button == Mouse::Button::Left ?: false;
    originX = leftButtonPressed ? event.x : originX;
    originY = leftButtonPressed ? event.y : originY;
    updateMouseCursor();
}

void InputManager::mouseButtonReleased(const Event::MouseButtonEvent &event) {
    leftButtonPressed = event.button != Mouse::Button::Left ?: false;
    updateMouseCursor();
}

void InputManager::updateMouseCursor() {
    window.setMouseCursorGrabbed(leftButtonPressed);
}

void InputManager::mouseMoved(const Event::MouseMoveEvent &event) {
    if (world.isPaused()) {
        renderer.mouseMoved(Mouse::getPosition(window));
    }
    if (leftButtonPressed) {
        renderer.move(-(event.x - originX) / 1.f, -(event.y - originY) / 1.f);
        originX = event.x;
        originY = event.y;
    }
}

void InputManager::mouseWheelScrolled(const Event::MouseWheelScrollEvent &event) {
    if (event.wheel == Mouse::Wheel::VerticalWheel) {
        renderer.zoom(event.delta * 0.01f);
    } else {
        auto di = event.delta == 0 ? 0 : event.delta > 0 ? 100 : -100;
        world.setInterval(world.getInterval() - di);
    }
}

void InputManager::toggleCursor() {
    if (renderer.isEditing() && renderer.isCursorValid()) {
        auto cursor = renderer.getCursor();
        auto x = static_cast<uint32_t>(cursor.x), y = static_cast<uint32_t>(cursor.y);
        world.setCell(x, y, world.getCell(x, y) ? uint8_t(0) : uint8_t(1));
    }
}

void InputManager::fillRandomly() {
    for (uint32_t y = 0; y < world.getHeight(); y++) {
        for (uint32_t x = 0; x < world.getWidth(); x++) {
            world.setCell(x, y, static_cast<uint8_t>(rand() % 2));
        }
    }
}
