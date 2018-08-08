#ifndef GAME_OF_LIFE_WORLD_STATE_H
#define GAME_OF_LIFE_WORLD_STATE_H

#include "State.h"
#include "World.h"
#include "WorldRenderer.h"
#include "Camera.h"
#include "CameraController.h"
#include "Updater.h"

class WorldState : public State {
public:
    explicit WorldState(World& world);

    void update() override;

    void render() override;

    bool handleEvent(const sf::Event& event) override;

protected:
    bool handleKeyPressed(const sf::Event::KeyEvent& event) override;

    void toggleFrameHud();

protected:
    World& world;
    Camera camera;
    CameraController cameraController;
    WorldRenderer worldRenderer;
    Updater updater;
};


#endif //GAME_OF_LIFE_WORLD_STATE_H
