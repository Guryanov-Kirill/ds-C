#include "sortedList.h"
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

List* new()
{
    return calloc(1, sizeof(List));
}

int insertListElement(List* list, int value)
{
    if (list == NULL) {
        return EINVAL;
    }

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return ENOMEM;
    }
    newNode->value = value;
    newNode->next = NULL;

    if ((list->head == NULL) || (value <= list->head->value)) {
        newNode->next = list->head;
        list->head = newNode;
        return 0;
    }

    ListNode* current = list->head;
    while ((current->next != NULL) && (current->next->value < value)) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

int deleteListElement(List* list, int elementIndex)
{
    if (elementIndex < 0 || list->head == NULL) {
        return EINVAL;
    }

    if (elementIndex == 0) {
        ListNode* popNode = list->head;
        list->head = popNode->next;
        free(popNode);
        return 0;
    }
    ListNode* current = list->head;
    int index = 0;
    while ((current != NULL) && (current->next != NULL)) {
        if (index == elementIndex - 1) {
            ListNode* popNode = current->next;
            current->next = popNode->next;
            free(popNode);
            return 0;
        }
        current = current->next;
        index++;
    }
    return errno;
}

int get(List* list, int elementIndex)
{
    if (list->head == NULL || elementIndex < 0 || list == NULL) {
        return EINVAL;
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
    return ENODATA;
}

int printList(List* list)
{
    if (list == NULL) {
        return EINVAL;
    }

    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
    printf("\n");
    return 0;
}

int deleteList(List* list)
{
    if (list == NULL) {
        return EINVAL;
    }
    while (list->head != NULL) {
        deleteListElement(list, 0);
    }
    free(list);
    return 0;
}