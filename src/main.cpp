#include "Engine/Engine.hpp"
#include "Game/Game.hpp"

int main() {
  Engine engine;
  Game game;

  engine.run(game);

  return 0;
}