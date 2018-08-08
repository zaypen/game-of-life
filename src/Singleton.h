#ifndef GAME_OF_LIFE_SINGLETON_H
#define GAME_OF_LIFE_SINGLETON_H

#include <cassert>

template<typename T>
class Singleton {
protected:
    Singleton() { instance = static_cast<T*>(this); };

public:
    Singleton(const Singleton<T>&) = delete;

    Singleton<T>& operator=(const Singleton<T>&) = delete;

    static T& get() {
        assert(instance && "Singleton is not initialized");
        return static_cast<T&>(*instance);
    }

private:
    static T* instance;
};

template<typename T>
T* Singleton<T>::instance = nullptr;

#endif //GAME_OF_LIFE_SINGLETON_H
