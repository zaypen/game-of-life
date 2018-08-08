#ifndef GAME_OF_LIFE_RENDER_MANAGER_H
#define GAME_OF_LIFE_RENDER_MANAGER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Singleton.h"
#include "FrameClock.h"
#include "FrameOverlay.h"
#include "Renderer.h"

class RenderManager : public Singleton<RenderManager> {
public:
    explicit RenderManager();

    void reset(sf::VideoMode videoMode);

    sf::Window& window() { return this->renderWindow; }

    inline void clear() { this->renderWindow.clear(); }

    inline void render(const Render& render) { render(this->renderWindow); }

    inline void beginFrame() { this->clock.beginFrame(); }

    inline void endFrame() {
        if (this->frameHudVisible) this->renderWindow.draw(frameOverlay);
        this->renderWindow.display();
        this->clock.endFrame();
    }

    inline bool isFrameHudVisible() { return this->frameHudVisible; }
    inline void setFrameHudVisible(bool visible) { this->frameHudVisible = visible; }

private:
    sf::RenderWindow renderWindow;
    sf::Font font;
    sfx::FrameClock clock;
    FrameOverlay frameOverlay;
    bool frameHudVisible;
};

#endif //GAME_OF_LIFE_RENDER_MANAGER_H
