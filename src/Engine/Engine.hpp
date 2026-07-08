#pragma once

class Game;

class Engine {
  public:
    void run(Game& game);

  private:
    bool running = true;
};