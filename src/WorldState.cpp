#include "WorldState.h"
#include "RenderManager.h"

WorldState::WorldState(World& world) : world(world), worldRenderer(world), cameraController(camera), updater() {
    auto& renderMgr = RenderManager::get();
    auto& window = renderMgr.window();
    camera = Camera(sf::Vector2f(worldRenderer.size()));
    camera.fit(sf::Vector2f(window.getSize()), false);
    updater.setInterval(1000);
}

void WorldState::update() {
    updater.update([=]() {
        world.update();
    });
}

void WorldState::render() {
    auto& renderMgr = RenderManager::get();
    renderMgr.render(camera.with(worldRenderer()));
}

bool WorldState::handleEvent(const sf::Event& event) {
    return cameraController.handleEvent(event) || State::handleEvent(event);
}

bool WorldState::handleKeyPressed(const sf::Event::KeyEvent& event) {
    switch (event.code) {
        case sf::Keyboard::Space:
            updater.setPaused(!updater.isPaused());
            return true;
        case sf::Keyboard::Z:
            updater.setInterval(max(100u, min(1000u, updater.getInterval() - 100)));
            return true;
        case sf::Keyboard::X:
            updater.setInterval(max(100u, min(1000u, updater.getInterval() + 100)));
            return true;
        case sf::Keyboard::F12:
            toggleFrameHud();
            return true;
        default:
            return false;
    }
}

void WorldState::toggleFrameHud() {
    auto& renderMgr = RenderManager::get();
    renderMgr.setFrameHudVisible(!renderMgr.isFrameHudVisible());
}
