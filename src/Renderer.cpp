#include "Renderer.h"

#include <algorithm>
#include <cmath>

using namespace std;

static uint16_t GridWidth = 20;

Renderer::Renderer(World& world, RenderTarget& renderTarget, FrameClock& frameClock) : world(world), renderTarget(renderTarget),
                                                               font(), frameOverlay(frameClock, font),
                                                               view(), scale(1.f), maxScale(1.f), rectangle(), circle(),
                                                               square(), cursor(0, 0), editing(false), frameOverlayVisible(false) {
    font.loadFromFile("resources/Arial.ttf");
    uint32_t width = world.getWidth() * GridWidth, height = world.getHeight() * GridWidth;
    rectangle.setSize(Vector2f(width, height));
    rectangle.setFillColor(Color(60, 130, 190, 192));
    square.setSize(Vector2f(16.f, 16.f));
    square.setFillColor(Color::Transparent);
    square.setOutlineColor(Color::White);
    square.setOutlineThickness(2);
    circle.setRadius(8);
    circle.setFillColor(Color::White);
}

void Renderer::initialize(const Vector2u &size) {
    uint32_t width = world.getWidth() * GridWidth, height = world.getHeight() * GridWidth;
    float hScale = static_cast<float>(width) / size.x, vScale = static_cast<float>(height) / size.y;
    scale = maxScale = max(hScale, vScale);
    // Put center and inside of window
    view.reset(FloatRect(Vector2f((width - size.x * scale) / 2, (height - size.y * scale) / 2),
                         Vector2f(size.x, size.y) * scale));
}

void Renderer::resizeWindow(const Event::SizeEvent &event) {
    view.setSize(Vector2f(event.width, event.height) * scale);
}

void Renderer::mouseMoved(Vector2i position) {
    auto worldPosition = renderTarget.mapPixelToCoords(position, view);
    auto x = floor(worldPosition.x / GridWidth), y = floor(worldPosition.y / GridWidth);
    cursor = Vector2i(static_cast<int>(x), static_cast<int>(y));
    worldPosition = Vector2f(x * GridWidth + 2, y * GridWidth + 2);
    square.setPosition(worldPosition);
}

void Renderer::move(float dx, float dy) {
    view.move(dx * scale, dy * scale);
}

void Renderer::zoom(float ds) {
    auto size = view.getSize() / scale;
    scale += ds;
    scale = max(.1f, min(maxScale, scale));
    view.setSize(size * scale);
}

void Renderer::render() {
    auto fixed = renderTarget.getView();
    renderTarget.clear(Color::Transparent);
    renderTarget.setView(view);
    renderTarget.draw(rectangle);
    for (uint32_t y = 0; y < world.getHeight(); y++) {
        for (uint32_t x = 0; x < world.getWidth(); x++) {
            if (world.getCell(x, y).getState() == Cell::Alive) {
                circle.setPosition(x * GridWidth + 2, y * GridWidth + 2);
                renderTarget.draw(circle);
            }
        }
    }
    if (editing && isCursorValid()) {
        renderTarget.draw(square);
    }
    renderTarget.setView(fixed);
    if (frameOverlayVisible) {
        renderTarget.draw(frameOverlay);
    }
}
