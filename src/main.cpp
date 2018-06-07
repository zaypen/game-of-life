#include <iostream>
#include <SFML/Graphics.hpp>
#include "World.h"

using namespace sf;

int main() {
    World world(40, 30);
    world.SetCell(0, 1);
    world.SetCell(1, 1);
    world.SetCell(2, 1);
    CircleShape cell(8);
    cell.setFillColor(Color(250, 250, 250));
    Clock clock;
    RenderWindow window(VideoMode(800, 600), "Game of Life");
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        if (clock.getElapsedTime().asMilliseconds() > 1000) {
            world.Update();
            clock.restart();
        }
        window.clear(Color::Black);
        for (auto y = 0; y < 30; y++) {
            for (auto x = 0; x < 40; x++) {
                if (world.GetCell(x, y)) {
                    cell.setPosition(x * 20 + 10, y * 20 + 10);
                    window.draw(cell);
                }
            }
        }
        window.display();
    }
    return 0;
}
