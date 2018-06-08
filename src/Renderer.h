#ifndef GAME_OF_LIFE_RENDERER_H
#define GAME_OF_LIFE_RENDERER_H

#include <SFML/Graphics.hpp>
#include "World.h"

using namespace sf;

class Renderer {
public:
    explicit Renderer(World& world, RenderTarget& renderTarget);

    void Move(float dx, float dy);
    void Render();

private:
    World& world;
    RenderTarget& renderTarget;
    View view;
    CircleShape circle;
};


#endif //GAME_OF_LIFE_RENDERER_H
