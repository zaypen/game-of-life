#include "Game.h"

Game::Game(uint32_t width, uint32_t height) : world(width, height),
                                              renderWindow(),
                                              renderer(world, renderWindow),
                                              input(world, renderWindow, renderer) {
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    renderWindow.create(VideoMode(800, 600), "Game of Life", Style::Default, settings);
    renderWindow.setFramerateLimit(60);
    renderer.Initialize(renderWindow.getSize());
    world.SetCell(0, 1);
    world.SetCell(1, 2);
    world.SetCell(2, 0);
    world.SetCell(2, 1);
    world.SetCell(2, 2);
    world.SetCell(2, 3);
}

void Game::Run() {
    while (renderWindow.isOpen()) {
        HandleEvents();
        world.Update();
        renderer.Render();
        renderWindow.display();
    }
}

void Game::HandleEvents() {
    Event event{};
    while (renderWindow.pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                renderWindow.close();
                break;
            case Event::Resized:
                renderer.ResizeWindow(event.size);
                break;
            case Event::KeyPressed:
                input.KeyPressed(event.key);
                break;
            case Event::KeyReleased:
                input.KeyReleased(event.key);
                break;
            case Event::MouseButtonPressed:
                input.MouseButtonPressed(event.mouseButton);
                break;
            case Event::MouseButtonReleased:
                input.MouseButtonReleased(event.mouseButton);
                break;
            case Event::MouseMoved:
                input.MouseMoved(event.mouseMove);
                break;
            case Event::MouseWheelScrolled:
                input.MouseWheelScrolled(event.mouseWheelScroll);
            default:
                break;
        }
    }
}
