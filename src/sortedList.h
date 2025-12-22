#pragma once
#include <errno.h>
#include <stdbool.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    struct ListNode* head;
} List;

List* new();

int insertListElement(List* list, int value);

int deleteListElement(List* list, int index);

int get(List* list, int index);

int printList(List* list);

int deleteList(List* list);