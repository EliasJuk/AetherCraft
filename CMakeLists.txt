cmake_minimum_required(VERSION 3.20)
project(Aether)

find_package(glfw3 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(Aether
  src/main.cpp
  src/Engine/Engine.cpp
  src/Game/Game.cpp
  src/Engine/Window/Window.cpp
  src/Engine/Time/Time.cpp
  src/Engine/Clock/Clock.cpp
)

target_link_libraries(Aether PRIVATE glfw)