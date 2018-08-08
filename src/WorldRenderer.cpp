#include "WorldRenderer.h"

const static uint32_t CellWidth = 20;

WorldRenderer::WorldRenderer(World& world) : world(world) {
}

sf::Vector2u WorldRenderer::size() {
    return world.getSize() * CellWidth;
}

void WorldRenderer::render(sf::RenderTarget& target) {
    RectangleShape worldShape;
    worldShape.setFillColor(Color(60, 130, 190, 192));
    CircleShape cellShape;
    cellShape.setRadius(8);
    cellShape.setFillColor(Color::White);
    uint32_t width = world.getWidth() * CellWidth, height = world.getHeight() * CellWidth;
    worldShape.setSize(Vector2f(width, height));
    target.draw(worldShape);
    for (uint32_t y = 0; y < world.getHeight(); y++) {
        for (uint32_t x = 0; x < world.getWidth(); x++) {
            if (world.getCell(x, y).getState() == Cell::Alive) {
                cellShape.setPosition(x * CellWidth + 2, y * CellWidth + 2);
                target.draw(cellShape);
            }
        }
    }
}
