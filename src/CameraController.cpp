#include "CameraController.h"

#include "RenderManager.h"

bool CameraController::handleWindowResized(const sf::Event::SizeEvent& event) {
    auto size = sf::Vector2f(event.width, event.height);
    camera.fit(size, true);
    return true;
}

bool CameraController::handleKeyPressed(const sf::Event::KeyEvent& event) {
    switch (event.code) {
        case sf::Keyboard::Q:
            camera.zoom(0.01f);
            return true;
        case sf::Keyboard::E:
            camera.zoom(-0.01f);
            return true;
        case sf::Keyboard::W:
            camera.move(sf::Vector2f{0.f, -5.f});
            return true;
        case sf::Keyboard::S:
            camera.move(sf::Vector2f{0.f, 5.f});
            return true;
        case sf::Keyboard::A:
            camera.move(sf::Vector2f{-5.f, 0.f});
            return true;
        case sf::Keyboard::D:
            camera.move(sf::Vector2f{5.f, 0.f});
            return true;
        default:
            return false;
    }
}

bool CameraController::handleMouseMoved(const sf::Event::MouseMoveEvent& event) {
    if (leftMouseButtonPressed) {
        camera.move(sf::Vector2f(-(event.x - originX) / 1.f, -(event.y - originY) / 1.f));
        originX = event.x;
        originY = event.y;
        return true;
    }
    return false;
}

bool CameraController::handleMouseButtonPressed(const sf::Event::MouseButtonEvent& event) {
    leftMouseButtonPressed = event.button == sf::Mouse::Button::Left ?: false;
    if (leftMouseButtonPressed) {
        originX = leftMouseButtonPressed ? event.x : originX;
        originY = leftMouseButtonPressed ? event.y : originY;
    }
    updateMouseCursor();
    return event.button == sf::Mouse::Button::Left;
}

bool CameraController::handleMouseButtonReleased(const sf::Event::MouseButtonEvent& event) {
    leftMouseButtonPressed = event.button != sf::Mouse::Button::Left ?: false;
    updateMouseCursor();
    return event.button != sf::Mouse::Button::Left;
}

bool CameraController::handleMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent& event) {
    if (event.wheel == sf::Mouse::Wheel::VerticalWheel) {
        camera.zoom(event.delta * 0.01f);
        return true;
    }
    return false;
}

void CameraController::updateMouseCursor() {
    auto& renderMgr = RenderManager::get();
    renderMgr.window().setMouseCursorGrabbed(leftMouseButtonPressed);
}
