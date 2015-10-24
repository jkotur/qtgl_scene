cmake_minimum_required(VERSION 2.8.11)

project("qtgl_scene")

enable_testing()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_executable(app
  src/main.cpp
  src/scene_window.h
  src/scene_window.cpp
)

set_property(TARGET app PROPERTY CXX_STANDARD 11)

target_link_libraries(app Qt5::Widgets)

