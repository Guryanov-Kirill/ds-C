#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    struct StackNode* head;
};

struct Stack new(void)
{
    struct Stack stack = {
        .head = NULL
    };
    return stack;
}

bool push(struct Stack* stack, int value)
{
    struct StackNode* node = malloc(sizeof(struct StackNode));
    if (node == NULL) {
        return false;
    }
    node->value = value;
    node->next = stack->head;
    stack->head = node;
    return true
}

int pop(struct Stack* stack)
{
    if (stack->head != NULL) {
        struct StackNode* oldNode = stack->head;
        int result = oldNode->value;
        stack->head = oldNode->next;
        free(oldNode);
        return result;
    } else {
        return errorCode;
    }
}

int peek(struct Stack* stack)
{
    if (stack->head != NULL) {
        return stack->head->value;
    } else {
        return errorCode;
    }
}

void stackFree(struct Stack* stack)
{
    while (stack->head != NULL) {
        pop(stack);
    }
}
