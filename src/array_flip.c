#include <stdio.h>

// Функция для разворота участка массива
void reverseArray(int array[], int start, int end)
{
    while (start < end) {
        int temp = arr[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

// Функция для перестановки участков массива
void rearrangeArray(int array[], int m, int n)
{
    reverseArray(array, 0, m - 1);
    reverseArray(array, m, m + n - 1);
    reverseArray(array, 0, m + n - 1);
}

// Функция для вывода массива
void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int m = 5, n = 5;
    printf("Исходный массив:\n");
    printArray(array, m + n);

    rearrangeArray(array, m, n);

    printf("Изменённый массив:\n");
    printArray(array, m + n);
    return 0;
}