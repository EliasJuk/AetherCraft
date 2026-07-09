#pragma once

class Clock {
  public:
    explicit Clock(float ticksPerSecond = 20.0f);

    void update(float deltaTime);

    bool shouldTick();
    float getTickDeltaTime() const;

  private:
    float tickRate;
    float tickDeltaTime;
    float accumulator;
};