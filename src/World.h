#ifndef GAME_OF_LIFE_WORLD_H
#define GAME_OF_LIFE_WORLD_H

#include <cstdint>
#include <cassert>
#include <vector>
#include <SFML/System.hpp>

#include "Cell.h"

using namespace std;
using namespace sf;

class World {
public:
    explicit World(uint32_t width, uint32_t height);

public:
    void update();

    uint32_t getWidth() const {
        return width;
    }

    uint32_t getHeight() const {
        return height;
    }

    Vector2u getSize() const {
        return {width, height};
    }

    Cell getCell(uint32_t x, uint32_t y) {
        assert(y * width + x < width * height);
        return cells[y * width + x];
    }

    void setCell(uint32_t x, uint32_t y, Cell cell = Cell(Cell::Alive)) {
        assert(y * width + x < width * height);
        cells[y * width + x] = cell;
    };

protected:
    uint32_t aliveNeighbor(uint32_t x, uint32_t y);

protected:
    uint32_t width, height;
    vector<Cell> cells;
};


#endif //GAME_OF_LIFE_WORLD_H
