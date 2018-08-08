#ifndef GAME_OF_LIFE_GAME_ENGINE_H
#define GAME_OF_LIFE_GAME_ENGINE_H


#include <SFML/Window/Event.hpp>

class GameEngine {
public:
    void run();

protected:
    bool handleEvent(sf::Event event);
};


#endif //GAME_OF_LIFE_GAME_ENGINE_H
