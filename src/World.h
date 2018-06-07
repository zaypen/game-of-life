#ifndef GAME_OF_LIFE_WORLD_H
#define GAME_OF_LIFE_WORLD_H

#include <cstdint>
#include <cassert>
#include <vector>

using namespace std;

class World {
public:
    World(int16_t width, int16_t height);

    World() = delete;

private:

public:
    void Update();

    uint8_t GetCell(int16_t x, int16_t y) {
        assert(y * width + x < width * height);
        return cells[y * width + x];
    }

    void SetCell(int16_t x, int16_t y, uint8_t alive = 1) {
        assert(y * width + x < width * height);
        cells[y * width + x] = alive;
    };
protected:
    uint8_t AliveNeighbor(int16_t x, int16_t y);

protected:
    int16_t width, height;
    vector<uint8_t> cells;
};


#endif //GAME_OF_LIFE_WORLD_H
