#ifndef GAME_OF_LIFE_CAMERA_H
#define GAME_OF_LIFE_CAMERA_H

#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "Renderer.h"

class Camera {
public:
    Camera() : Camera(sf::Vector2f(0, 0)) {}

    explicit Camera(const sf::Vector2f& size);

    void fit(const sf::Vector2f& viewportSize, bool keepScale = false);

    void move(const sf::Vector2f& offset);

    void zoom(float ds);

    Render with(const Render& render) {
        return [=](sf::RenderTarget& target) {
            target.setView(view);
            render(target);
            target.setView(target.getDefaultView());
        };
    };

private:
    float minimumScale(const sf::Vector2f& size);

private:
    sf::Vector2f size;
    sf::View view;
    float scale, minScale;
};

#endif //GAME_OF_LIFE_CAMERA_H
