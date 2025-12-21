#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Функция для расставоения приоритетов операций
int getOperatorPrecedence(char sim)
{
    if ((sim == '+') || (sim == '-')) {
        return 1;
    }
    if ((sim == '*') || (sim == '/')) {
        return 2;
    }
    return 0;
}

// Проверяет операнд или нет
bool isOperand(char sim)
{
    if ((sim == '+') || (sim == '-') || (sim == '*') || (sim == '/')) {
        return true;
    }
    return false;
}

void printExit(char array[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}

int main()
{
    char sentence[50];
    printf("Введите выражение\n");
    if (scanf("%49[^\n]", sentence) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }
    int length = strlen(sentence);

    struct Stack oper = new();

    char exit[100];
    int sizeExit = 0;

    for (int i = 0; i < length; i++) {

        if (sentence[i] != ' ') {

            if (isOperand(sentence[i])) {
                char up = peek(&oper);

                // Выталкиваем элементы из стека
                // пока приоритет проверяемого символа не будет меньше приоритета верхнего элемента стека
                while ((up != -1) && (getOperatorPrecedence(sentence[i]) <= getOperatorPrecedence(up))) {
                    exit[sizeExit] = pop(&oper);
                    sizeExit++;
                    up = peek(&oper);
                }
                push(&oper, sentence[i]);

            } else {
                exit[sizeExit] = sentence[i];
                sizeExit++;
            }
        }
    }

    // Кладём в выходной массив оставшиеся в стеке операнды
    while (peek(&oper) != -1) {
        exit[sizeExit] = pop(&oper);
        sizeExit++;
    }

    stackFree(&oper);
    printExit(exit, sizeExit);
    return 0;
}