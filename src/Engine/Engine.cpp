#include "Engine.hpp"

#include "../Game/Game.hpp"

#include <iostream>

void Engine::run(Game& game) {
  std::cout << "Aether Engine iniciado!\n";

  game.start();

  while (running) {
    game.update();

    stop(); // temporario: depois quem fecha sera a janela/input
  }

  std::cout << "Engine finalizada.\n";
}

void Engine::stop() {
  running = false;
}