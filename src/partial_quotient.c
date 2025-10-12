#include <stdio.h>
#include <stdlib.h>

int partialQuotient(int a, int b)
{
    int flag = 0;
    if (a * b < 0) {
        flag = 1;
    }
    if (b == 0) {
        return 0;
    }
    int quotient = 0;
    int absB = abs(b), absA = abs(a);
    while (absA >= absB) {
        absA -= absB;
        quotient++;
    }
    if (flag == 1) {
        return -quotient;
    } else {
        return quotient;
    }
}

int main()
{
    int a, b;
    printf("Введите a и b: ");
    scanf("%d %d", &a, &b);
    int result = partialQuotient(a, b);
    if (result == 0) {
        printf("Ошибка деление на ноль");
    } else {
        printf("Неполное частное от деления %d на %d: %d\n", a, b, result);
    }
    return 0;
}