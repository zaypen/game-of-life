#include "Game.h"

Game::Game(uint32_t width, uint32_t height) : world(width, height),
                                              renderWindow(),
                                              renderer(world, renderWindow),
                                              input(world, renderWindow, renderer) {
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    renderWindow.create(VideoMode(800, 600), "Game of Life", Style::Default, settings);
    renderWindow.setFramerateLimit(60);
    renderer.initialize(renderWindow.getSize());
    world.setCell(0, 1, Cell(Cell::Alive));
    world.setCell(1, 2, Cell(Cell::Alive));
    world.setCell(2, 0, Cell(Cell::Alive));
    world.setCell(2, 1, Cell(Cell::Alive));
    world.setCell(2, 2, Cell(Cell::Alive));
    world.setCell(2, 3, Cell(Cell::Alive));
}

void Game::run() {
    while (renderWindow.isOpen()) {
        handleEvents();
        world.update();
        renderer.render();
        renderWindow.display();
    }
}

void Game::handleEvents() {
    Event event{};
    while (renderWindow.pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                renderWindow.close();
                break;
            case Event::Resized:
                renderer.resizeWindow(event.size);
                break;
            case Event::KeyPressed:
                input.keyPressed(event.key);
                break;
            case Event::KeyReleased:
                input.keyReleased(event.key);
                break;
            case Event::MouseButtonPressed:
                input.mouseButtonPressed(event.mouseButton);
                break;
            case Event::MouseButtonReleased:
                input.mouseButtonReleased(event.mouseButton);
                break;
            case Event::MouseMoved:
                input.mouseMoved(event.mouseMove);
                break;
            case Event::MouseWheelScrolled:
                input.mouseWheelScrolled(event.mouseWheelScroll);
            default:
                break;
        }
    }
}
