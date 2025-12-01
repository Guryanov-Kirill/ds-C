#include <stdio.h>
#include <stdint.h>

int main() {
    double number;
    printf("Введите число: ");
    scanf("%lf", &number);

    union {
        double d;
        uint64_t bit;
    } u;
    u.d = number;
    int s = (u.bit >> 63) & 1;
    int extent = (u.bit >> 52) & 0x7FF;
    uint64_t mantissa = u.bit & 0xFFFFFFFFFFFFF;

    double m = 1.0 + (double)mantissa / (1ULL << 52);
    int p = extent - 1023;
    
    printf("Result: %c%.10f*2^%d\n", s ? '-' : '+', m, p);
    
    return 0;
}