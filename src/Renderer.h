#ifndef GAME_OF_LIFE_RENDERER_H
#define GAME_OF_LIFE_RENDERER_H

#include <SFML/Graphics.hpp>
#include "World.h"

using namespace sf;

class Renderer {
public:
    explicit Renderer(World& world, RenderTarget& renderTarget);

    void Initialize(const Vector2u& size);
    void ResizeWindow(const Event::SizeEvent &event);
    void MouseMoved(Vector2i position);
    void Move(float dx, float dy);
    void Zoom(float ds);
    void Render();

    Vector2i GetCursor() const {
        return cursor;
    };

    bool IsCursorValid() const {
        return cursor.x > -1 && cursor.x < world.GetWidth() && cursor.y > -1 && cursor.y < world.GetHeight();
    }

    bool IsEditing() const {
        return editing;
    }

    void SetEditing(bool editing) {
        Renderer::editing = editing;
    }

private:
    World& world;
    RenderTarget& renderTarget;
    View view;
    float scale;
    RectangleShape rectangle;
    CircleShape circle;
    RectangleShape square;
    Vector2i cursor;
    bool editing;
};


#endif //GAME_OF_LIFE_RENDERER_H
