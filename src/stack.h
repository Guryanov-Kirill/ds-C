#pragma once

struct StackNode {
    int value;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* head;
};

typedef struct Stack Stack;

// Создание нового стека
struct Stack new(void);

// Добавление элемента
void push(struct Stack* stack, int value, int* errorCode);

// Удаление верхнего элемента
int pop(struct Stack* stack, int* errorCode);

// Вывод верхнего элемента
int peek(struct Stack* stack, int* errorCode);

// Удаление всего стека (очистка памяти)
void stackFree(struct Stack* stack);