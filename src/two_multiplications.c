#include <stdio.h>

// x^4 + x^3 + x^2 + x + 1 = (x * x + x) * (x * x + 1) + 1 = (y + x) * (y + 1) + 1 (y = x^2)

double formula(double x)
{
    int y = x * x;
    return (y + x) * (y + 1) + 1;
}
int main(void)
{
    double x = 0;
    printf("Введите x: ");
    scanf("%lf", &x);
    double result = formula(x);
    printf("Значение выражения x^4 + x^3 + x^2 + x + 1 = %lf\n", result);
    return 0;
}
