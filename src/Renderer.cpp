#include "Renderer.h"

Renderer::Renderer(RenderTarget& window, World& world): renderTarget(window), world(world), circle(8) {
    circle.setFillColor(Color(250, 250, 250));
}

void Renderer::Render() {
    renderTarget.clear(Color::Black);
    for (uint32_t y = 0; y < world.GetHeight(); y++) {
        for (uint32_t x = 0; x < world.GetWidth(); x++) {
            if (world.GetCell(x, y)) {
                circle.setPosition(x * 20 + 2, y * 20 + 2);
                renderTarget.draw(circle);
            }
        }
    }
}
