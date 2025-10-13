#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 1;
    int count = 0;
    int t;
    for (int i = 0; i < 1000000; i++) {
        t = a + b;
        a = b;
        b = t;
        if (b <= 1000000) {
            if (b % 2 == 0) {
                count = count + b;
                printf("%d\n", b);
            }
        } else {
            break;
        }
    }
    printf("%d", count);
    return 0;
}