#include "Window.hpp"

#include <iostream>

bool Window::initialize() {
  std::cout << "Janela inicializada.\n";
  closeRequested = false;

  return true;
}

void Window::shutdown() {
  std::cout << "Janela finalizada.\n";
}

bool Window::shouldClose() const {
  return closeRequested;
}

void Window::requestClose() {
  closeRequested = true;
}