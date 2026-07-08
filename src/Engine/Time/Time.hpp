#pragma once

class Time {
  public:
    void update();

    float getDeltaTime() const;
    double getTotalTime() const;

  private:
    float deltaTime = 0.0f;
    double totalTime = 0.0;
};