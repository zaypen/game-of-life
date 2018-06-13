#ifndef GAME_OF_LIFE_RENDERER_H
#define GAME_OF_LIFE_RENDERER_H

#include <SFML/Graphics.hpp>
#include "World.h"

using namespace sf;

class Renderer {
public:
    explicit Renderer(World& world, RenderTarget& renderTarget);

    void initialize(const Vector2u &size);
    void resizeWindow(const Event::SizeEvent &event);
    void mouseMoved(Vector2i position);
    void move(float dx, float dy);
    void zoom(float ds);
    void render();

    Vector2i getCursor() const {
        return cursor;
    };

    bool isCursorValid() const {
        return cursor.x > -1 && cursor.x < world.getWidth() && cursor.y > -1 && cursor.y < world.getHeight();
    }

    bool isEditing() const {
        return editing;
    }

    void setEditing(bool editing) {
        Renderer::editing = editing;
    }

private:
    World& world;
    RenderTarget& renderTarget;
    View view;
    float scale, maxScale;
    RectangleShape rectangle;
    CircleShape circle;
    RectangleShape square;
    Vector2i cursor;
    bool editing;
};


#endif //GAME_OF_LIFE_RENDERER_H
