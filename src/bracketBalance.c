#include <stdio.h>
#include <string.h>

int bracketBalance(char* testString)
{
    int lenString = strlen(testString);
    int open = 0;
    int close = 0;
    for (int i = 0; i <= lenString; i++) {
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
    if (close == open) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    char inputString[50];
    printf("Введите строку (без пробелов): ");
    scanf("%49s", inputString);
    int test = bracketBalance(inputString);
    if (test == 1) {
        printf("Баланс соблюден\n");
    } else {
        printf("Баланс не соблюден\n");
    }
}
