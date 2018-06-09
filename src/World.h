#ifndef GAME_OF_LIFE_WORLD_H
#define GAME_OF_LIFE_WORLD_H

#include <cstdint>
#include <cassert>
#include <vector>

using namespace std;

class World {
public:
    explicit World(uint32_t width, uint32_t height) : width(width), height(height), cells(width * height),
                                                      paused(false) {};

public:
    void Update();

    uint32_t GetWidth() const {
        return width;
    }

    uint32_t GetHeight() const {
        return height;
    }

    uint8_t GetCell(uint32_t x, uint32_t y) {
        assert(y * width + x < width * height);
        return cells[y * width + x];
    }

    void SetCell(uint32_t x, uint32_t y, uint8_t alive = 1) {
        assert(y * width + x < width * height);
        cells[y * width + x] = alive;
    };

    bool IsPaused() const {
        return paused;
    }

    void SetPaused(bool paused) {
        World::paused = paused;
    }

protected:
    uint8_t AliveNeighbor(uint32_t x, uint32_t y);

protected:
    uint32_t width, height;
    vector<uint8_t> cells;
    bool paused;
};


#endif //GAME_OF_LIFE_WORLD_H
