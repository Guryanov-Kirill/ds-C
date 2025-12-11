#include <stdio.h>

int main()
{
    int n = -1;
    int numbers[100];
    int count = 0;
    while (n != 0) {
        printf("Введите число\n");
        scanf("%d", &n);
        numbers[count] = n;
        count++;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        int freq = 1;
        while (i + 1 < count && numbers[i] == numbers[i + 1]) {
            freq++;
            i++;
        }
        printf("%d %d\n", numbers[i], freq);
    }
    return 0;
}
