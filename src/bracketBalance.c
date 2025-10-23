#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check(char open, char close){
    if ((open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}')){
        return true;
    }
    return false;
}
int main(void)
{
    struct Stack myStack = new();
    printf("Введите строку для проверки\n");
    char str[50];
    scanf("%s", str);
    int lenght = strlen(str);
    for (int i = 0; i < lenght; i++){
        if ((str[i] == '(') || (str[i] == '{') || (str[i] == '[')){
            push(&myStack, str[i]);
        }
        if ((str[i] == ')') || (str[i] == '}') || (str[i] == ']')){
            if (check(peek(&myStack), str[i])){
                pop(&myStack);
            }
        }
    }
    if (peek(&myStack) == -1){
        printf("Баланс есть\n");
    } else{
        printf("Баланса нет\n");
    }
    stackFree(&myStack);
    return 0;
}
