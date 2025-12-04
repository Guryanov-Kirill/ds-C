add_compile_options(-Wall -Wextra -Wpedantic)

add_library(list sortedList.c sortedList.h)

add_executable(testSortedList sortedList.c sortedList.h testSortedList.c)

target_link_libraries(testSortedList PRIVATE list)

add_test(NAME SortedListTests COMMAND testSortedList)
