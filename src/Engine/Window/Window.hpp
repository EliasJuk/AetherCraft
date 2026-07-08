#pragma once

class Window {
  public:
    bool initialize();
    void shutdown();

    bool shouldClose() const;
    void requestClose();

  private:
    bool closeRequested = false;
};