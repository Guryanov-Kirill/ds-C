#include "cycleList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

List* new()
{
    List* list = calloc(1, sizeof(List));
    if (list != NULL) {
        return list;
    } else {
        return NULL;
    }
}

bool insertListElement(List* list, int index, int value)
{
    if (index < 0 || list == NULL) {
        return false;
    }

    ListNode* newNode = malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return false;
    }
    newNode->value = value;

    if (list->tail == NULL) {
        if (index != 0) {
            free(newNode);
            return false;
        }
        newNode->next = newNode;
        list->tail = newNode;
        return true;
    }

    if (index == 0) {
        newNode->next = list->tail->next;
        list->tail->next = newNode;
        return true;
    }

    ListNode* current = list->tail->next;
    int idx = 0;

    do {
        if (idx == index - 1) {
            newNode->next = current->next;
            current->next = newNode;

            if (current == list->tail) {
                list->tail = newNode;
            }
            return true;
        }
        idx++;
        current = current->next;
    } while (current != list->tail->next && idx <= index);

    free(newNode);
    return false;
}

bool pop(List* list, int index)
{
    if (index < 0 || list == NULL || list->tail == NULL) {
        return false;
    }

    if (list->tail->next == list->tail) {
        if (index != 0)
            return false;
        free(list->tail);
        list->tail = NULL;
        return true;
    }

    if (index == 0) {
        ListNode* head = list->tail->next;
        list->tail->next = head->next;
        free(head);
        return true;
    }

    ListNode* current = list->tail->next;
    int idx = 0;

    do {
        if (idx == index - 1) {
            ListNode* popNode = current->next;
            current->next = popNode->next;

            if (popNode == list->tail) {
                list->tail = current;
            }

            free(popNode);
            return true;
        }
        idx++;
        current = current->next;
    } while (current != list->tail->next && idx <= index);

    return false;
}

int get(List* list, int index)
{
    if (list == NULL || list->tail == NULL || index < 0) {
        return errorCode;
    }

    ListNode* current = list->tail->next;
    int idx = 0;

    do {
        if (idx == index) {
            return current->value;
        }
        idx++;
        current = current->next;
    } while (current != list->tail->next && idx <= index);

    return errorCode;
}

void printList(List* list)
{
    if (list == NULL || list->tail == NULL) {
        printf("Empty list\n");
        return;
    }

    ListNode* current = list->tail->next;

    printf("%d", current->value);
    current = current->next;

    while (current != list->tail->next) {
        printf(" %d", current->value);
        current = current->next;
    }
    printf("\n");
}

bool deleteList(List* list)
{
    if (list == NULL) {
        return false;
    }

    if (list->tail != NULL) {
        ListNode* current = list->tail->next;
        list->tail->next = NULL;

        while (current != NULL) {
            ListNode* next = current->next;
            free(current);
            current = next;
        }
    }

    free(list);
    return true;
}