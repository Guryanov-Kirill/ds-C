#include "list.h"
#include <assert.h>
#include <stdio.h>

void test_create_and_delete_list()
{
    List* list = newList();
    assert(list != NULL);
    assert(list->head == NULL);

    bool result = deleteList(list);
    assert(result == true);
}

void test_insert_and_get()
{
    List* list = newList();

    // Вставка в пустой список
    assert(insertList(list, 10) == true);
    assert(get(list, 0) == 10);

    // Вставка в начало (меньший элемент)
    assert(insertList(list, 5) == true);
    assert(get(list, 0) == 5);
    assert(get(list, 1) == 10);

    // Вставка в середину
    assert(insertList(list, 7) == true);
    assert(get(list, 0) == 5);
    assert(get(list, 1) == 7);
    assert(get(list, 2) == 10);

    // Вставка в конец (больший элемент)
    assert(insertList(list, 15) == true);
    assert(get(list, 3) == 15);

    deleteList(list);
}