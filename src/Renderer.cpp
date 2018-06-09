#include "Renderer.h"

#include <algorithm>
#include <cmath>

using namespace std;

static uint16_t GridWidth = 20;

Renderer::Renderer(World &world, RenderTarget &renderTarget) : world(world), renderTarget(renderTarget),
                                                               view(), scale(1.f), rectangle(), circle(), square(),
                                                               cursor(0, 0), editing(false) {
    view.reset(FloatRect(0, 0, world.GetWidth() * GridWidth, world.GetHeight() * GridWidth));
    rectangle.setSize(Vector2f(world.GetWidth() * GridWidth, world.GetHeight() * GridWidth));
    rectangle.setFillColor(Color(60, 130, 190, 192));
    square.setSize(Vector2f(16.f, 16.f));
    square.setFillColor(Color(0, 0, 0, 0));
    square.setOutlineColor(Color(250, 250, 250, 128));
    square.setOutlineThickness(2);
    circle.setRadius(8);
    circle.setFillColor(Color(250, 250, 250));
}

void Renderer::MouseMoved(Vector2i position) {
    auto worldPosition = renderTarget.mapPixelToCoords(position, view);
    auto x = floor(worldPosition.x / GridWidth), y = floor(worldPosition.y / GridWidth);
    cursor = Vector2i(static_cast<int>(x), static_cast<int>(y));
    worldPosition = Vector2f(x * GridWidth + 2, y * GridWidth + 2);
    square.setPosition(worldPosition);
}

void Renderer::Move(float dx, float dy) {
    view.move(dx, dy);
}

void Renderer::Zoom(float ds) {
    auto center = view.getCenter() / scale, size = view.getSize() / scale;
    scale += ds;
    scale = max(.1f, min(10.f, scale));
    view.setCenter(center * scale);
    view.setSize(size * scale);
}

void Renderer::Render() {
    auto previousView = renderTarget.getView();
    renderTarget.setView(view);
    renderTarget.draw(rectangle);
    for (uint32_t y = 0; y < world.GetHeight(); y++) {
        for (uint32_t x = 0; x < world.GetWidth(); x++) {
            if (world.GetCell(x, y)) {
                circle.setPosition(x * GridWidth + 2, y * GridWidth + 2);
                renderTarget.draw(circle);
            }
        }
    }
    if (editing && IsCursorValid()) {
        renderTarget.draw(square);
    }
    renderTarget.setView(previousView);
}
