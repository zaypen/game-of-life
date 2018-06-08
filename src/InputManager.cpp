#include "InputManager.h"

void InputManager::KeyPressed(const Event::KeyEvent& event) {
    switch (event.code) {
        case Keyboard::Escape:
            window.close();
            break;
        default:
            break;
    }
}

void InputManager::KeyReleased(const Event::KeyEvent& event) {

}
