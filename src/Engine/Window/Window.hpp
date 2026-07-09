#pragma once

#include <GLFW/glfw3.h>

class Window {
public:
  bool initialize();
  void shutdown();

  void pollEvents();
  void swapBuffers();

  bool shouldClose() const;
  void requestClose();

private:
  GLFWwindow* handle = nullptr;
};