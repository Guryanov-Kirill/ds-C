#include <stdio.h>

// Функция для разворота участка массива
void reverseArray(int arr[], int start, int end) {
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

// Функция для перестановки участков массива
void rearrangeArray(int arr[], int m, int n) {
  reverseArray(arr, 0, m - 1);
  reverseArray(arr, m, m + n - 1);
  reverseArray(arr, 0, m + n - 1);
}

// Функция для вывода массива
void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int m = 5, n = 5;
  printf("Исходный массив:\n");
  printArray(arr, m + n);

  rearrangeArray(arr, m, n);

  printf("Изменённый массив:\n");
  printArray(arr, m + n);
  return 0;
}