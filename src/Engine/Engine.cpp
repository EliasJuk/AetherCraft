#include "Engine.hpp"

#include "../Game/Game.hpp"

#include <iostream>

Engine::Engine()
  : running(false),
    clock(20.0f) {

}

bool Engine::initialize() {
  std::cout << "Inicializando Engine...\n";

  if (!window.initialize()) {
    return false;
  }

  running = true;
  return true;
}

void Engine::shutdown() {
  window.shutdown();

  std::cout << "Finalizando Engine...\n";
}

void Engine::run(Game& game) {
  if (!initialize()) {
    return;
  }

  game.start();

  while (running && !window.shouldClose()) {
    engineTime.update();

    clock.update(engineTime.getDeltaTime());

    while (clock.shouldTick()) {
      game.tick(clock.getTickDeltaTime());
    }
    
    game.update(engineTime.getDeltaTime());

    // stop(); // temporário
  }

  shutdown();
}

void Engine::stop() {
  running = false;
}