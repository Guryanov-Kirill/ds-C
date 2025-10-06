#include <stdio.h>

extern int sortArray(int* array, int count);

int main()
{
    int array[100];
    int count = 0;

    while (scanf("%d", &array[count]) == 1 && count < 100) {
        count++;
    }

    int movedCount = sortArray(array, count);

    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return movedCount;
}