#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode* next;
};

struct List {
    struct ListNode* head;
};

ListNode* new()
{
    List* list = calloc(1, sizeof(List));
    return list;
}

bool push(List* list, int index, int value)
{
    if (index < 0) {
        return false;
    }
    if (index == 0) {
        ListNode* newNode = malloc(sizeof(ListNode));
        newNode->value = value;

        if (list->head == NULL) {
            newNode->next = newNode;
            list->head = newNode;
        } else {
            ListNode* last = list->head;
            while (last->next != list->head) {
                last = last->next;
            }
            newNode->next = list->head;
            list->head = newNode;
            last->next = newNode;
        }
        return true;
    }

    int idx = 0;
    ListNode* current = list->head;
    if (current == NULL)
        return false;

    do {
        if (idx == index - 1) {
            ListNode* newNode = malloc(sizeof(ListNode));
            newNode->value = value;
            newNode->next = current->next;
            current->next = newNode;
            return true;
        }
        idx++;
        current = current->next;
    } while (current != list->head);

    return false;
}

bool pop(List* list, int index)
{
    if (index < 0 || list->head == NULL) {
        return false;
    }
    if (index == 0) {
        if (list->head->next == list->head) {
            free(list->head);
            list->head = NULL;
        } else {
            ListNode* last = list->head;
            while (last->next != list->head) {
                last = last->next;
            }
            ListNode* popNode = list->head;
            list->head = popNode->next;
            last->next = list->head;
            free(popNode);
        }
        return true;
    }

    ListNode* current = list->head;
    int idx = 0;
    do {
        if (idx == index - 1) {
            ListNode* popNode = current->next;
            current->next = popNode->next;
            free(popNode);
            return true;
        }
        current = current->next;
        idx++;
    } while (current != list->head);

    return false;
}

int get(List* list, int index)
{
    if (list->head == NULL || index < 0 || list == NULL) {
        return -1;
    }
    ListNode* current = list->head;
    int idx = 0;
    do {
        if (index == idx) {
            return current->value;
        }
        current = current->next;
        idx++;
    } while (current != list->head);
    return -1;
}

void printList(List* list)
{
    if ((list == NULL) && (list->head == NULL)) {
        return;
    }

    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
    printf("\n");
}

bool deleteList(List* list)
{
    if (list == NULL) {
        return false;
    }
    while (list->head != NULL) {
        pop(list, 0);
    }
    free(list);
    return true;
}