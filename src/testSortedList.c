#include "sortedList.h"
#include <assert.h>
#include <stdio.h>

bool test_create_and_delete_list()
{
    List* list = new();
    if (list != NULL) return false;
    if (list->head == NULL) return false;
    return deleteListAll(list);
}

bool test_insert_and_get()
{
    List* list = new();

    // Вставка в пустой список
    assert(insertList(list, 0, 10) == true);
    assert(get(list, 0) == 10);

    // Вставка в начало (меньший элемент)
    assert(insertList(list, 0, 5) == true);
    assert(get(list, 0) == 5);
    assert(get(list, 1) == 10);

    // Вставка в середину
    assert(insertList(list, 0, 7) == true);
    assert(get(list, 0) == 5);
    assert(get(list, 1) == 7);
    assert(get(list, 2) == 10);

    // Вставка в конец (больший элемент)
    assert(insertList(list, 0, 15) == true);
    assert(get(list, 3) == 15);

    deleteListAll(list);
}


int main()
{
    test_create_and_delete_list();
    test_insert_and_get();
    return 0;
}