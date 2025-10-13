#include <stdio.h>

int main(void)
{
    int array[] = { 2, 4, 1, 5, 8, 3, 6 };
    int length = sizeof(array) / sizeof(array[0]);
    int t;
    int i = 1;

    while (i < length) {
        if (i == 0 || array[i] >= array[i - 1]) {
            i++;
        } else {
            t = array[i];
            array[i] = array[i - 1];
            array[i - 1] = t;
            i--;
        }
    }
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
}