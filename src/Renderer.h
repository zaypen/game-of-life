#ifndef GAME_OF_LIFE_RENDER_H
#define GAME_OF_LIFE_RENDER_H

#include <functional>
#include <SFML/Graphics.hpp>

typedef std::function<void(sf::RenderTarget&)> Render;

class Renderer {
public:
    virtual void render(sf::RenderTarget& target) = 0;

    Render operator()() {
        return [=](sf::RenderTarget& target) {
            render(target);
        };
    }
};

#endif //GAME_OF_LIFE_RENDER_H
