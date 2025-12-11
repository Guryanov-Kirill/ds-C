#include "number2.h"
#include <stdio.h>
#include <stdlib.h>

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* reverse(struct Node* head)
{
    struct Node* temp = NULL;
    struct Node* current = head;
    while (current != NULL) {
        struct Node* n = newNode(current->data);
        n->next = temp;
        temp = n;
        current = current->next;
    }
    return temp;
}

void printList(struct Node* head)
{
    if (head == NULL) {
        printf("NULL");
    }
    while (head != NULL) {
        int n = head->data;
        printf("%d ", n);
        head = head->next;
    }
}

int main()
{
    struct Node* t1 = newNode(1);
    t1->next = newNode(2);
    t1->next->next = newNode(3);
    printList(t1);
    struct Node* result1 = reverse(t1);
    printList(res1);
}