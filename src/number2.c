#include <stdio.h>
#include <stdbool.h>

int comparison(bool array1[], int len1, bool array2[], int len2) {
    int zero1 = 0;
    int zero2 = 0;

    while (len2 > zero2 && !array2[zero2]) {
        zero2++
    }
    while (len1 > zero1 && !array1[zero1]) {
        zero1++;
    }

    // Длина чисел без нулей
    int realLen1 = len1 - zero1;
    int realLen2 = len2 - zero2;

    if (realLen1 > realLen2) {
        return 1;
    }
    if (realLen2 > realLen1) {
        return -1;
    }
    if (realLen2 == realLen1) {
        for (int i = 0; i < realLen1; i++){
            if (array1[zero1 + i] && !array2[zero2 + i]){
                return 1;
            }
            if (!array1[zero1 + i] && array2[zero2 + i]){
                return -1;
            }
        }
    }
    return 0;
}

int main() {
    // Тест 1 number1 > number2
    bool number1[] = {true, false, true, false};
    int len1 = sizeof(number1) / sizeof(bool);
    bool number2[] = {false, true, true, false};
    int len2 = sizeof(number2) / sizeof(bool);
    int result = comparison(number1, len1, number2, len2);
    
    if (result == 1) {
        printf("number1 > number2\n");
    } else if (result == -1){
        printf("number2 > number1\n");
    } else {
        printf("number1 == number2\n");
    }
    
    // Тест 2 числа равны
    bool number3[] = {false, true, true, false};
    int len3 = sizeof(number3) / sizeof(bool);
    bool number4[] = {true, true, false};
    int len4 = sizeof(number4) / sizeof(bool);
    result = comparison(number3, len3, number4, len4);
    
    printf("\nПроверка равенства (number3 и number4):\n");
    if (result == 1) {
        printf("number3 > number4\n");
    } else if (result == -1){
        printf("number4 > number3\n");
    } else {
        printf("number3 == number4\n");
    }

    return 0;
}