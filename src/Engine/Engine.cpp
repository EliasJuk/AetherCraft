#include "Engine.hpp"

#include "../Game/Game.hpp"

#include <iostream>

void Engine::run(Game& game) {
  std::cout << "Aether Engine iniciado!\n";
  game.start();

  while (running) {
    game.update();

    running = false; // temporario: evita loop infinito por enquanto
  }

  std::cout << "Engine finalizada.\n";
}