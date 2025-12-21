#pragma once
#include <stdbool.h>

#define errorCode -111111

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    struct ListNode* tail;
} List;

List* new();
// Добавление элемента
bool insertListElement(List* list, int index, int value);
// Удаление элемента
bool pop(List* list, int index);
// Вывод элемента
int get(List* list, int index);
// Вывод всего списка
void printList(List* list);
// Удаление списка
bool deleteList(List* list);