#include "number2.h"
#include <stdio.h>

void minNumber(int n)
{
    int digits[10] = { 0 };

    while (n > 0) {
        int d = n % 10;
        digits[d]++;
        n = n / 10;
    }
    int first_digit = -1;
    for (int i = 1; i <= 9; i++) {
        if (digits[i] > 0) {
            first_digit = i;
            break;
        }
    }

    if (first_digit != -1) {
        printf("%d", first_digit);
        digits[first_digit]--;
    }
    for (int i = 0; i <= 9; i++) {
        while (digits[i] > 0) {
            printf("%d", i);
            digits[i]--;
        }
    }
}

int main(void)
{
    int number = 95321;
    minNumber(number);
    printf("\n");
    number = 879437;
    minNumber(number);
        printf("\n");
    return 0;
}