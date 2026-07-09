#include "Clock.hpp"

Clock::Clock(float ticksPerSecond)
  : tickRate(ticksPerSecond),
    tickDeltaTime(1.0f / ticksPerSecond),
    accumulator(0.0f) {
}

void Clock::update(float deltaTime) {
  accumulator += deltaTime;
}

bool Clock::shouldTick() {
  if (accumulator >= tickDeltaTime) {
    accumulator -= tickDeltaTime;
    return true;
  }

  return false;
}

float Clock::getTickDeltaTime() const {
  return tickDeltaTime;
}