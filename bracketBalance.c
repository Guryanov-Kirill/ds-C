#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool bracketBalance(char* testString)
{
    int lenString = strlen(testString);
    int open = 0;
    int close = 0;
    for (int i = 0; i < lenString; i++) {
        if (testString[i] == '(') {
            open++;
        }
        if (testString[i] == ')') {
            close++;
        }
        if (close > open) {
            break;
        }
    }
    return (close == open);
}

int main(void)
{
    char inputString[50];
    printf("Введите строку (без пробелов): ");
    scanf("%49s", inputString);
    int test = bracketBalance(inputString);
    if (test == true) {
        printf("Баланс соблюден\n");
    } else {
        printf("Баланс не соблюден\n");
    }
    return 0;
}
