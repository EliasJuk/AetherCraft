#include "Game.hpp"

#include <iostream>

void Game::start() {
  std::cout << "AetherCraft Game iniciado!\n";
}

void Game::update(float deltaTime) {
  std::cout << "Game Update | deltaTime: " << deltaTime << "\n";
}