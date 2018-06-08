#include <iostream>
#include <SFML/Graphics.hpp>
#include "World.h"
#include "InputManager.h"
#include "Renderer.h"

using namespace sf;

int main() {
    World world(40, 30);
    world.SetCell(0, 1);
    world.SetCell(1, 2);
    world.SetCell(2, 0);
    world.SetCell(2, 1);
    world.SetCell(2, 2);
    world.SetCell(2, 3);
    Clock clock;
    RenderWindow window(VideoMode(800, 600), "Game of Life");
    Renderer renderer(window, world);
    InputManager input(window, world);
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    input.KeyPressed(event.key);
                    break;
                case Event::KeyReleased:
                    input.KeyReleased(event.key);
                    break;
                default:
                    break;
            }
        }
        if (clock.getElapsedTime().asMilliseconds() > 1000) {
            world.Update();
            clock.restart();
        }
        renderer.Render();
        window.display();
    }
    return 0;
}
