#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H

#include <cstdlib>

class Cell {
public:
    enum CellState {
        Dead,
        Alive,
        Count
    };

    static Cell random() {
        return Cell(static_cast<CellState>(rand() % Count));
    }

public:
    Cell() : Cell(Dead) {}

    explicit Cell(CellState state) : state(state) {}

    CellState getState() {
        return state;
    }

    void setState(CellState state) {
        this->state = state;
    }

protected:
    CellState state;
};


#endif //GAME_OF_LIFE_CELL_H
