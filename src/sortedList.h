#pragma once
#include <stdbool.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    struct ListNode* head;
} List;

List* new();

bool insertListElement(List* list, int value);

bool deleteListElement(List* list, int index);

int get(List* list, int index);

bool printList(List* list);

bool deleteList(List* list);