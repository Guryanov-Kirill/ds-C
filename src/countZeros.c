#include <stdio.h>

int countZeros(int array[], int size)
{
    int zeroCount = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] == 0) {
            zeroCount++;
        }
    }
    return zeroCount;
}

int main()
{
    int exampleArray[] = { 1, 0, 2, 0, 3, 0 };
    int arraySize = sizeof(exampleArray) / sizeof(exampleArray[0]);
    int zeros = countZeros(exampleArray, arraySize);
    printf("Количество нулей в массиве: %d\n", zeros);
    return 0;
}