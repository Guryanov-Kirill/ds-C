#include <stdio.h>
#include <stdlib.h>

int partialQuotient(int a, int b)
{
    int sign = 1;
    if (a * b < 0) {
        sign = -1;
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
    return quotient * sign;
}

int main()
{
    int a, b = 0;
    printf("Введите a и b: ");
    scanf("%d %d", &a, &b);
    if (b == 0) {
        printf("Ошибка деление на ноль");
    } else {
        int result = partialQuotient(a, b);
        printf("Неполное частное от деления %d на %d: %d\n", a, b, result);
    }
    return 0;
}