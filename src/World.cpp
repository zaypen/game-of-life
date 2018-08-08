#include "World.h"

#include <utility>

Cell::CellState tick(Cell::CellState alive, uint32_t lives) {
    if (alive == Cell::Alive) {
        if (lives == 2 || lives == 3) {
            return Cell::Alive;
        } else {
            return Cell::Dead;
        }
    } else if (lives == 3) {
        return Cell::Alive;
    }
    return Cell::Dead;
}

World::World(uint32_t width, uint32_t height) : width(width), height(height), cells(width * height) {}

void World::update() {
    auto buffer = vector<Cell>(width * height);
    for (auto index = 0; index < width * height; index++) {
        auto alive = cells[index].getState();
        auto x = index % width, y = index / width;
        auto lives = aliveNeighbor(x, y);
        buffer[index] = Cell(tick(alive, lives));
    }
    swap(cells, buffer);
}

uint32_t World::aliveNeighbor(uint32_t x, uint32_t y) {
    uint32_t count = 0;
    for (auto oy = -1; oy < 2; oy++) {
        for (auto ox = -1; ox < 2; ox++) {
            auto dx = static_cast<int32_t>(x) + ox, dy = static_cast<int32_t>(y) + oy;
            auto valid = (ox != 0 || oy != 0) && dx > -1 && dx < width && dy > -1 && dy < height;
            if (valid && cells[dy * width + dx].getState() == Cell::Alive) {
                count++;
            }
        }
    }
    return count;
}
