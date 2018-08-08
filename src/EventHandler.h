#ifndef GAME_OF_LIFE_EVENT_HANDLER_H
#define GAME_OF_LIFE_EVENT_HANDLER_H

#include <SFML/Window/Event.hpp>

class EventHandler {
public:
    virtual bool handleEvent(const sf::Event& event) {
        switch (event.type) {
            // Window events
            case sf::Event::Closed:
                return handleWindowClosed();
            case sf::Event::Resized:
                return handleWindowResized(event.size);
            // Keyboard events
            case sf::Event::KeyPressed:
                return handleKeyPressed(event.key);
            case sf::Event::KeyReleased:
                return handleKeyReleased(event.key);
            case sf::Event::TextEntered:
                return handleTextEntered(event.text);
            // Mouse events
            case sf::Event::MouseEntered:
                return handleMouseEntered();
            case sf::Event::MouseLeft:
                return handleMouseLeft();
            case sf::Event::MouseMoved:
                return handleMouseMoved(event.mouseMove);
            case sf::Event::MouseButtonPressed:
                return handleMouseButtonPressed(event.mouseButton);
            case sf::Event::MouseButtonReleased:
                return handleMouseButtonReleased(event.mouseButton);
            case sf::Event::MouseWheelScrolled:
                return handleMouseWheelScrolled(event.mouseWheelScroll);
            // Joystick events
            case sf::Event::JoystickButtonPressed:
            case sf::Event::JoystickButtonReleased:
            case sf::Event::JoystickMoved:
            case sf::Event::JoystickConnected:
            case sf::Event::JoystickDisconnected:
            // Touch evetns
            case sf::Event::SensorChanged:
            case sf::Event::TouchBegan:
            case sf::Event::TouchMoved:
            case sf::Event::TouchEnded:
            default:
                return false;
        }
    }

protected:
    virtual bool handleWindowClosed() {
        return false;
    }

    virtual bool handleWindowResized(const sf::Event::SizeEvent& event) {
        return false;
    }

    virtual bool handleKeyPressed(const sf::Event::KeyEvent& event) {
        return false;
    }

    virtual bool handleKeyReleased(const sf::Event::KeyEvent& event) {
        return false;
    }

    virtual bool handleTextEntered(const sf::Event::TextEvent& event) {
        return false;
    }

    virtual bool handleMouseEntered() {
        return false;
    }

    virtual bool handleMouseLeft() {
        return false;
    }

    virtual bool handleMouseMoved(const sf::Event::MouseMoveEvent& event) {
        return false;
    }

    virtual bool handleMouseButtonPressed(const sf::Event::MouseButtonEvent& event) {
        return false;
    }

    virtual bool handleMouseButtonReleased(const sf::Event::MouseButtonEvent& event) {
        return false;
    }

    virtual bool handleMouseWheelScrolled(const sf::Event::MouseWheelScrollEvent& event) {
        return false;
    }
};

#endif //GAME_OF_LIFE_EVENT_HANDLER_H
