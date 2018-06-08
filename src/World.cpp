#include "World.h"

#include <utility>

#define ALIVE (1)
#define DEAD (0)

uint8_t Survive(uint8_t alive, int64_t lives) {
    if (alive) {
        if (lives == 2 || lives == 3) {
            return ALIVE;
        } else {
            return DEAD;
        }
    } else if (lives == 3) {
        return ALIVE;
    }
    return DEAD;
}

void World::Update() {
    auto buffer = vector<uint8_t>(static_cast<uint64_t>(width * height));
    for (auto index = 0; index < width * height; index++) {
        auto alive = cells[index];
        auto x = static_cast<int16_t>(index % width), y = static_cast<int16_t>(index / width);
        int64_t lives = AliveNeighbor(x, y);
        buffer[index] = Survive(alive, lives);
    }
    swap(cells, buffer);
}

uint8_t World::AliveNeighbor(int16_t x, int16_t y) {
    uint8_t count = 0;
    for (auto oy = -1; oy < 2; oy++) {
        for (auto ox = -1; ox < 2; ox++) {
            auto dx = x + ox, dy = y + oy;
            auto valid = (ox != 0 || oy != 0) && dx > -1 && dx < width && dy > -1 && dy < height;
            if (valid && cells[dy * width + dx] != 0) {
                count++;
            }
        }
    }
    return count;
}

