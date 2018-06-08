#include "Renderer.h"

Renderer::Renderer(RenderTarget& window, World& world): renderTarget(window), world(world), circle(8) {
    circle.setFillColor(Color(250, 250, 250));
}

void Renderer::Render() {
    renderTarget.clear(Color::Black);
    for (int16_t y = 0; y < 30; y++) {
        for (int16_t x = 0; x < 40; x++) {
            if (world.GetCell(x, y)) {
                circle.setPosition(x * 20 + 10, y * 20 + 10);
                renderTarget.draw(circle);
            }
        }
    }
}
