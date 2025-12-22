#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    struct StackNode* head;
};

Stack* new()
{
    Stack* stack = malloc(sizeof(*stack));
    if (stack != NULL) {
        stack->head = NULL;
    }
    return stack;
}

void push(struct Stack* stack, int value, int* errorCode)
{
    struct StackNode* node = malloc(sizeof(struct StackNode));
    if (node == NULL) {
        *errorCode = 1;
        return;
    }
    *errorCode = 0;
    node->value = value;
    node->next = stack->head;
    stack->head = node;
    return;
}

int pop(struct Stack* stack, int* errorCode)
{
    if (stack->head != NULL) {
        struct StackNode* oldNode = stack->head;
        int result = oldNode->value;
        stack->head = oldNode->next;
        free(oldNode);
        *errorCode = 0;
        return result;
    } else {
        *errorCode = 1;
        return 0;
    }
}

int peek(struct Stack* stack, int* errorCode)
{
    if (stack->head != NULL) {
        *errorCode = 0;
        return stack->head->value;
    } else {
        *errorCode = 1;
        return 0;
    }
}

void stackFree(struct Stack* stack)
{
    int errorCode = 0;
    while (stack->head != NULL) {
        pop(stack, &errorCode);
    }
}
