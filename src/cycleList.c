#include "cycleList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

List* new()
{
    return(calloc(1, sizeof(List)));
}

int insertListElement(List* list, int index, int value)
{
    if (index < 0 || list == NULL) {
        return EINVAL;
    }

    ListNode* newNode = malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return EINVAL;
    }
    newNode->value = value;

    if (list->tail == NULL) {
        if (index != 0) {
            free(newNode);
            return ENOMEM;
        }
        newNode->next = newNode;
        list->tail = newNode;
        return 0;
    }

    if (index == 0) {
        newNode->next = list->tail->next;
        list->tail->next = newNode;
        return 0;
    }

    ListNode* current = list->tail->next;
    int currentIndex = 0;

    do {
        if (currentIndex == index - 1) {
            newNode->next = current->next;
            current->next = newNode;

            if (current == list->tail) {
                list->tail = newNode;
            }
            return 0;
        }
        currentIndex++;
        current = current->next;
    } while (current != list->tail->next && currentIndex <= index);

    free(newNode);
    return EINVAL;
}

int pop(List* list, int index)
{
    if (index < 0 || list == NULL || list->tail == NULL) {
        return EINVAL;
    }

    if (list->tail->next == list->tail) {
        if (index != 0)
            return EINVAL;
        free(list->tail);
        list->tail = NULL;
        return 0;
    }

    if (index == 0) {
        ListNode* head = list->tail->next;
        list->tail->next = head->next;
        free(head);
        return 0;
    }

    ListNode* current = list->tail->next;
    int currentIndex = 0;

    do {
        if (currentIndex == index - 1) {
            ListNode* popNode = current->next;
            current->next = popNode->next;

            if (popNode == list->tail) {
                list->tail = current;
            }

            free(popNode);
            return 0;
        }
        currentIndex++;
        current = current->next;
    } while (current != list->tail->next && currentIndex <= index);

    return EINVAL;
}

int get(List* list, int index)
{
    if (list == NULL || list->tail == NULL || index < 0) {
        return ENOMEM;
    }

    ListNode* current = list->tail->next;
    int currentIndex = 0;

    do {
        if (currentIndex == index) {
            return current->value;
        }
        currentIndex++;
        current = current->next;
    } while (current != list->tail->next && currentIndex <= index);

    return ENOMEM;
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

int deleteList(List* list)
{
    if (list == NULL) {
        return EINVAL;
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
    return 0;
}