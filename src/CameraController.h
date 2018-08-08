#ifndef GAME_OF_LIFE_CAMERA_CONTROLLER_H
#define GAME_OF_LIFE_CAMERA_CONTROLLER_H

#include "EventHandler.h"
#include "Camera.h"

class CameraController : public EventHandler {
public:
    explicit CameraController(Camera& camera) : camera(camera), leftMouseButtonPressed(false),
                                                originX(0), originY(0) {}

protected:
    bool handleWindowResized(const sf::Event::SizeEvent& event) override;

    bool handleKeyPressed(const sf::Event::KeyEvent& event) override;

    bool handleMouseMoved(const sf::Event::MouseMoveEvent& event) override;

    bool handleMouseButtonPressed(const sf::Event::MouseButtonEvent& event) override;

    bool handleMouseButtonReleased(const sf::Event::MouseButtonEvent& event) override;

    bool handleMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent& event) override;

    void updateMouseCursor();

private:
    Camera& camera;
    bool leftMouseButtonPressed;
    int32_t originX, originY;
};


#endif //GAME_OF_LIFE_CAMERA_CONTROLLER_H
