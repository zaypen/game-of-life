#ifndef GAME_OF_LIFE_WORLD_H
#define GAME_OF_LIFE_WORLD_H

#include <cstdint>
#include <cassert>
#include <vector>
#include <SFML/System/Clock.hpp>

using namespace std;
using namespace sf;

class World {
public:
    explicit World(uint32_t width, uint32_t height) : width(width), height(height), cells(width * height),
                                                      clock(), interval(500), paused(false) {};

public:
    void update();

    uint32_t getWidth() const {
        return width;
    }

    uint32_t getHeight() const {
        return height;
    }

    uint8_t getCell(uint32_t x, uint32_t y) {
        assert(y * width + x < width * height);
        return cells[y * width + x];
    }

    void setCell(uint32_t x, uint32_t y, uint8_t alive = 1) {
        assert(y * width + x < width * height);
        cells[y * width + x] = alive;
    };

    uint32_t getInterval() const {
        return interval;
    };

    void setInterval(uint32_t interval) {
        World::interval = max(100u, min(1000u, interval));
    };

    bool isPaused() const {
        return paused;
    }

    void setPaused(bool paused) {
        World::paused = paused;
    }

protected:
    uint8_t aliveNeighbor(uint32_t x, uint32_t y);

protected:
    uint32_t width, height;
    vector<uint8_t> cells;
    Clock clock;
    uint32_t interval;

protected:
    bool paused;
};


#endif //GAME_OF_LIFE_WORLD_H
