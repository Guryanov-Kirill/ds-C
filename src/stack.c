#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack new(void)
{
    struct Stack stack = {
        .head = NULL
    };
    return stack;
}

void push(struct Stack* stack, int value)
{
    struct StackNode* node = malloc(sizeof(struct StackNode));
    node->value = value;
    node->next = stack->head;
    stack->head = node;
}

int pop(struct Stack* stack)
{
    if (stack->head != NULL) {
        struct StackNode* oldNode = stack->head;
        int res = oldNode->value;
        stack->head = oldNode->next;
        free(oldNode);
        return res;
    } else {
        return -1;
    }
}

int peek(struct Stack* stack)
{
    if (stack->head != NULL) {
        return stack->head->value;
    } else {
        return -1;
    }
}

void stackFree(struct Stack* stack)
{
    while (stack->head != NULL) {
        pop(stack);
    }
}
