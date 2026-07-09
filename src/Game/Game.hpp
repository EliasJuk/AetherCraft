#pragma once

class Game {
  public:
    void start();
    
    void update(float deltaTime);
    void tick(float tickDeltaTime);
};