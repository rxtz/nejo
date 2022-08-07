cmake_minimum_required(VERSION 3.21)
project(nejo)

set(CMAKE_CXX_STANDARD 23)

find_package(raylib REQUIRED)

add_executable(nejo
  src/main.cpp
  src/assets.cpp
  src/car.cpp
  src/controls.cpp)
target_link_libraries(${PROJECT_NAME} raylib)
