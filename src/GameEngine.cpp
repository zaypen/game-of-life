#include "GameEngine.h"
#include "RenderManager.h"
#include "StateManager.h"
#include "InitState.h"

void GameEngine::run() {
    RenderManager renderMgr;
    StateManager stateMgr;
    auto& window = renderMgr.window();
    stateMgr.pushState(new InitState());
    while (window.isOpen()) {
        renderMgr.beginFrame();
        for (sf::Event event{}; window.pollEvent(event);) { stateMgr.handleEvent(event) || handleEvent(event); }
        stateMgr.update();
        renderMgr.clear();
        stateMgr.render();
        renderMgr.endFrame();
    }
}

bool GameEngine::handleEvent(sf::Event event) {
    auto& renderMgr = RenderManager::get();
    auto& window = renderMgr.window();
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
    }
    return true;
}
