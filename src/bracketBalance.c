#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isCorrectPairOfBracket(char open, char close){
    if ((open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}')){
        return true;
    }
    return false;
}
int main(void)
{
    struct Stack bracketStack = new();
    printf("Введите строку для проверки(<= 50)\n");
    char buffer[50];
    if (scanf("%49s", buffer) == 1){
        int lenght = strlen(buffer);
        for (int i = 0; i < lenght; i++){
            if ((buffer[i] == '(') || (buffer[i] == '{') || (buffer[i] == '[')){
                push(&bracketStack, buffer[i]);
            }
            if ((buffer[i] == ')') || (buffer[i] == '}') || (buffer[i] == ']')){
                if (isCorrectPairOfBracket(peek(&bracketStack), buffer[i])){
                    pop(&bracketStack);
                }
            }
        }
        if (peek(&bracketStack) == -1){
            printf("Баланс есть\n");
        } else{
            printf("Баланса нет\n");
        }
    } else {
        printf("Ошибка ввода\n");
    }
    stackFree(&bracketStack);
    return 0;
}
