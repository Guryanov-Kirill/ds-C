#pragma once
#include <stdint.h>
#include <errno.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    struct ListNode* tail;
} List;

List* new();
// Добавление элемента
int insertListElement(List* list, int index, int value);
// Удаление элемента
int pop(List* list, int index);
// Вывод элемента
int get(List* list, int index);
// Вывод всего списка
void printList(List* list);
// Удаление списка
int deleteList(List* list);