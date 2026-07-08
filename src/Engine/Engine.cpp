#include "Engine.hpp"

#include "../Game/Game.hpp"

#include <iostream>

void Engine::run(Game& game) {
  std::cout << "Aether Engine iniciado!\n";

  game.start();

  std::cout << "Engine finalizada.\n";
}