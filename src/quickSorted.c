#include <stdio.h>

int sort_array(int* array, int count)
{
    if (count <= 1) {
        return 0;
    }

    int movedCount = 0;

    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < count; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
            movedCount++;
        }
    }

    return movedCount;
}