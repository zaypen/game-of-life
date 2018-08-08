#ifndef GAME_OF_LIFE_INIT_STATE_H
#define GAME_OF_LIFE_INIT_STATE_H

#include "State.h"
#include "World.h"

class InitState : public State {
public:
    InitState();

    void update() override;

private:
    World world;
};


#endif //GAME_OF_LIFE_INIT_STATE_H
