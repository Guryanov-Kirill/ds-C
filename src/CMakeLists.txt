add_library(stack stack.c stack.h)

add_executable(sortStation sortStation.c)

target_link_libraries(sortStation PRIVATE stack)
