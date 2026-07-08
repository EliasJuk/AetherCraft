#include "Engine.hpp"

#include "../Game/Game.hpp"

#include <iostream>

Engine::Engine()
  : running(false) {

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
    game.update();

    window.requestClose(); // temporário
  }

  shutdown();
}

void Engine::stop() {
  running = false;
}