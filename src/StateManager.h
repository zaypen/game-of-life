#ifndef GAME_OF_LIFE_STATE_MANAGER_H
#define GAME_OF_LIFE_STATE_MANAGER_H

#include <functional>
#include "Singleton.h"
#include "State.h"

class StateManager : public Singleton<StateManager> {
public:
    bool handleEvent(sf::Event& event);

    void update();

    void render();

    void pushState(State* state);

    void popState();

    void replaceState(State* state);

    bool hasState() { return !states.empty(); }

protected:
    template<typename T>
    using Action = std::function<T(std::shared_ptr<State>&)>;

    template<typename T>
    T withActiveState(Action<T> action, T fallback);

    void withActiveState(Action<void> action);

private:
    std::vector<std::shared_ptr<State>> states;
};

#endif //GAME_OF_LIFE_STATE_MANAGER_H
