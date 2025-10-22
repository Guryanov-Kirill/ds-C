struct StackNode {
    int value;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* head;
};

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