#include "InitState.h"
#include "StateManager.h"
#include "World.h"
#include "WorldState.h"

InitState::InitState(): world(30u, 40u) {}

void InitState::update() {
    auto& stateMgr = StateManager::get();
    world.setCell(0, 1, Cell(Cell::Alive));
    world.setCell(1, 2, Cell(Cell::Alive));
    world.setCell(2, 0, Cell(Cell::Alive));
    world.setCell(2, 1, Cell(Cell::Alive));
    world.setCell(2, 2, Cell(Cell::Alive));
    world.setCell(2, 3, Cell(Cell::Alive));
    stateMgr.pushState(new WorldState(world));
}
