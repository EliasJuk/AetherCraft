#include "Time.hpp"

void Time::update() {
  deltaTime = 1.0f / 60.0f;

  totalTime += deltaTime;
}

float Time::getDeltaTime() const {
  return deltaTime;
}

double Time::getTotalTime() const {
  return totalTime;
}