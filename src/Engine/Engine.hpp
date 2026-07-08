#pragma once

#include "Window/Window.hpp"
#include "Time/Time.hpp"

class Game;

class Engine {
  public:
    Engine();

    void run(Game& game);
    void stop();

  private:
    bool initialize();
    void shutdown();

  private:
    bool running;
    Window window;
    Time engineTime;
};