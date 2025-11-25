#pragma once
#include <stdbool.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    struct ListNode* tail;
} List;

List* new();

bool insertList(List* list, int index, int value);

bool pop(List* list, int index);

int get(List* list, int index);

void printList(List* list);

bool deleteList(List* list);