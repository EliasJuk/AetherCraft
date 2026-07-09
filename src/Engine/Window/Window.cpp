#include "Window.hpp"

#include <iostream>

bool Window::initialize() {
  if (!glfwInit()) {
    std::cout << "Erro ao iniciar GLFW\n";
    return false;
  }

  handle = glfwCreateWindow(
    1280,
    720,
    "AetherCraft",
    nullptr,
    nullptr
  );

  if (!handle) {
    std::cout << "Erro ao criar janela\n";
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(handle);
  glfwSwapInterval(1);

  std::cout << "Janela GLFW inicializada.\n";
  return true;
}

void Window::shutdown() {
  if (handle) {
    glfwDestroyWindow(handle);
    handle = nullptr;
  }

  glfwTerminate();

  std::cout << "Janela finalizada.\n";
}

void Window::pollEvents() {
  glfwPollEvents();
}

void Window::swapBuffers() {
  glfwSwapBuffers(handle);
}

bool Window::shouldClose() const {
  return handle && glfwWindowShouldClose(handle);
}

void Window::requestClose() {
  if (handle) {
    glfwSetWindowShouldClose(handle, true);
  }
}