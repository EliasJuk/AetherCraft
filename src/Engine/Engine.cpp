#include "Engine.hpp"

#include "../Game/Game.hpp"

#include <iostream>

Engine::Engine()
  : running(false){

  }

bool Engine::initialize() {
  std::cout << "Inicializando Engine...\n";
  running = true;

  return true;
}

void Engine::shutdown() {
  std::cout << "Finalizando Engine...\n";
}

void Engine::run(Game& game) {
  if (!initialize()) {
    return;
  }

  game.start();

  while (running) {
    game.update();

    stop(); // temporario: depois quem fecha sera a janela/input
  }

  shutdown();
}

void Engine::stop() {
  running = false;
}