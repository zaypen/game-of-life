#include "StateManager.h"

bool StateManager::handleEvent(sf::Event& event) {
    return withActiveState<bool>([=](std::shared_ptr<State>& state) {
        return state->handleEvent(event);
    }, false);
}

void StateManager::update() {
    withActiveState([](std::shared_ptr<State>& state) {
        state->update();
    });
}

void StateManager::render() {
    withActiveState([](std::shared_ptr<State>& state) {
        state->render();
    });
}

void StateManager::pushState(State* state) {
    withActiveState([](std::shared_ptr<State>& state) {
        state->pause();
    });
    states.push_back(std::shared_ptr<State>(state));
}

void StateManager::popState() {
    withActiveState([=](std::shared_ptr<State>& state) {
        states.pop_back();
        state.reset();
    });
    withActiveState([](std::shared_ptr<State>& state) {
        state->resume();
    });
}

void StateManager::replaceState(State* state) {
    withActiveState([=](std::shared_ptr<State>& state) {
        states.pop_back();
        state.reset();
    });
    states.push_back(std::shared_ptr<State>(state));
}

template<typename T>
T StateManager::withActiveState(Action<T> action, T fallback) {
    if (hasState()) {
        return action(states.back());
    };
    return fallback;
}

void StateManager::withActiveState(Action<void> action) {
    if (hasState()) {
        action(states.back());
    };
}
