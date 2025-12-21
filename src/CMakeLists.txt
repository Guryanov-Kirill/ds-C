add_library(stack stack.c stack.h)

add_executable(bracketBalance
    bracketBalance.c
)

target_link_libraries(bracketBalance PRIVATE stack)
