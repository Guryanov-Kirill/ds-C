cmake_minimum_required(VERSION 3.25)

project(tests C)

enable_testing()

add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(src)
