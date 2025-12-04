cmake_minimum_required(VERSION 3.25)

project(bracketBalanceC VERSION 1.0.0 LANGUAGES C)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_subdirectory(src)