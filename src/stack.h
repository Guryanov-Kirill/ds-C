#pragma once

#define errorCode -111111

struct StackNode {
    int value;
    struct StackNode* next;
};

typedef struct Stack Stack;

// Создание нового стека
struct Stack new(void);

// Добавление элемента
void push(struct Stack* stack, int value);

// Удаление верхнего элемента
int pop(struct Stack* stack);

// Вывод верхнего элемента
int peek(struct Stack* stack);

// Удаление всего стека (очистка памяти)
void stackFree(struct Stack* stack);