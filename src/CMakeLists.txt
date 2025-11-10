cmake_minimum_required(VERSION 3.25)

project(bracketBalanceC)

add_library(stack stack.c stack.h)

add_executable(bracketBalance bracketBalance.c)

target_link_libraries(bracketBalance PRIVATE stack)
