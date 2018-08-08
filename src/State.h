#ifndef GAME_OF_LIFE_STATE_H
#define GAME_OF_LIFE_STATE_H

#include <SFML/Window.hpp>
#include "EventHandler.h"

class State : public EventHandler {
public:

    State() = default;

    State(const State&) = delete;

    State(const State&&) = delete;

    virtual void pause() {}

    virtual void resume() {}

    virtual void update() {}

    virtual void render() {}
};


#endif //GAME_OF_LIFE_STATE_H
