#pragma once

#define errorCode -111111

struct StackNode {
    int value;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* head;
};

typedef struct Stack Stack;

// Создание нового стека
Stack* new();

// Добавление элемента
void push(Stack* stack, int value, int* errorCode);

// Удаление верхнего элемента
int pop(Stack* stack, int* errorCode);

// Вывод верхнего элемента
int peek(Stack* stack, int* errorCode);

// Удаление всего стека (очистка памяти)
void stackFree(Stack* stack);