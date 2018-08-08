#ifndef GAME_OF_LIFE_CLOCK_H
#define GAME_OF_LIFE_CLOCK_H

#include <functional>
#include <SFML/System.hpp>

typedef std::function<void()> Update;

class Updater {
public:
    explicit Updater() : interval(1000), paused(false) {}

    uint32_t getInterval() { return this->interval; }

    void setInterval(uint32_t interval) { this->interval = interval; }

    bool isPaused() const { return this->paused; }

    void setPaused(bool paused) { this->paused = paused; }

    void update(const Update& update) {
        if (paused) return;
        if (clock.getElapsedTime().asMilliseconds() >= interval) {
            update();
            clock.restart();
        }
    }

private:
    sf::Clock clock;
    uint32_t interval;
    bool paused;
};


#endif //GAME_OF_LIFE_CLOCK_H
