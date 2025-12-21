#include "sortedList.h"
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

List* new()
{
    List* list = calloc(1, sizeof(List));
    return list;
}

bool insertListElement(List* list, int value)
{
    if (list == NULL) {
        return false;
    }

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return false;
    }
    newNode->value = value;
    newNode->next = NULL;

    if ((list->head == NULL) || (value <= list->head->value)) {
        newNode->next = list->head;
        list->head = newNode;
        return true;
    }

    ListNode* current = list->head;
    while ((current->next != NULL) && (current->next->value < value)) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return true;
}

bool deleteListElement(List* list, int elementIndex)
{
    if (elementIndex < 0 || list->head == NULL) {
        return false;
    }

    if (elementIndex == 0) {
        ListNode* popNode = list->head;
        list->head = popNode->next;
        free(popNode);
        return true;
    }
    ListNode* current = list->head;
    int index = 0;
    while ((current != NULL) && (current->next != NULL)) {
        if (index == elementIndex - 1) {
            ListNode* popNode = current->next;
            current->next = popNode->next;
            free(popNode);
            return true;
        }
        current = current->next;
        index++;
    }
    return false;
}

int get(List* list, int elementIndex)
{
    if (list->head == NULL || elementIndex < 0 || list == NULL) {
        return -1;
    }
    ListNode* current = list->head;
    int index = 0;
    while (current != NULL) {
        if (elementIndex == index) {
            return current->value;
        }
        current = current->next;
        index++;
    }
    return -1;
}

bool printList(List* list)
{
    if (list == NULL) {
        return false;
    }

    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
    printf("\n");
    return true;
}

bool deleteList(List* list)
{
    if (list == NULL) {
        return false;
    }
    while (list->head != NULL) {
        deleteListElement(list, 0);
    }
    free(list);
    return true;
}