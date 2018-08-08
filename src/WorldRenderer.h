#ifndef GAME_OF_LIFE_WORLD_RENDERER_H
#define GAME_OF_LIFE_WORLD_RENDERER_H

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Renderer.h"

class WorldRenderer : public Renderer {
public:
    explicit WorldRenderer(World& world);

    sf::Vector2u size();

    void render(sf::RenderTarget& target) override;

private:
    World& world;
};


#endif //GAME_OF_LIFE_WORLD_RENDERER_H
