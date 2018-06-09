#include "Renderer.h"

#include <algorithm>
#include <cmath>

using namespace std;

static uint16_t GridWidth = 20;

Renderer::Renderer(World& world, RenderTarget& renderTarget) : world(world), renderTarget(renderTarget),
                                                               view(), scale(1.f), maxScale(1.f), rectangle(), circle(),
                                                               square(), cursor(0, 0), editing(false) {
    uint32_t width = world.GetWidth() * GridWidth, height = world.GetHeight() * GridWidth;
    rectangle.setSize(Vector2f(width, height));
    rectangle.setFillColor(Color(60, 130, 190, 192));
    square.setSize(Vector2f(16.f, 16.f));
    square.setFillColor(Color::Transparent);
    square.setOutlineColor(Color::White);
    square.setOutlineThickness(2);
    circle.setRadius(8);
    circle.setFillColor(Color::White);
}

void Renderer::Initialize(const Vector2u& size) {
    uint32_t width = world.GetWidth() * GridWidth, height = world.GetHeight() * GridWidth;
    float hScale = static_cast<float>(width) / size.x, vScale = static_cast<float>(height) / size.y;
    scale = maxScale = max(hScale, vScale);
    // Put center and inside of window
    view.reset(FloatRect(Vector2f((width - size.x * scale) / 2, (height - size.y * scale) / 2),
                         Vector2f(size.x, size.y) * scale));
}

void Renderer::ResizeWindow(const Event::SizeEvent& event) {
    view.setSize(Vector2f(event.width, event.height) * scale);
}

void Renderer::MouseMoved(Vector2i position) {
    auto worldPosition = renderTarget.mapPixelToCoords(position, view);
    auto x = floor(worldPosition.x / GridWidth), y = floor(worldPosition.y / GridWidth);
    cursor = Vector2i(static_cast<int>(x), static_cast<int>(y));
    worldPosition = Vector2f(x * GridWidth + 2, y * GridWidth + 2);
    square.setPosition(worldPosition);
}

void Renderer::Move(float dx, float dy) {
    view.move(dx * scale, dy * scale);
}

void Renderer::Zoom(float ds) {
    auto size = view.getSize() / scale;
    scale += ds;
    scale = max(.1f, min(maxScale, scale));
    view.setSize(size * scale);
}

void Renderer::Render() {
    auto fixed = renderTarget.getView();
    renderTarget.clear(Color::Transparent);
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
    renderTarget.setView(fixed);
}
