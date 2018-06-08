#ifndef GAME_OF_LIFE_RENDERER_H
#define GAME_OF_LIFE_RENDERER_H

#include <SFML/Graphics.hpp>
#include "World.h"

using namespace sf;

class Renderer {
public:
    explicit Renderer(RenderTarget& window, World& world);

    void Render();

private:
    RenderTarget& renderTarget;
    World& world;
    CircleShape circle;
};


#endif //GAME_OF_LIFE_RENDERER_H
