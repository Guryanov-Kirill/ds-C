#include <stdio.h>
#include <stdlib.h>
#define BITS 32

void bin(int number, char* binar)
{
    for (int i = BITS - 1;i >= 0; i--){
        int bit = number & 1;
        if (bit == 1){
            binar[BITS - 1 - i] = '1';
        } else {
            binar[BITS - 1 - i] = '0';
        }
        number >>= 1;
    }
    binar[BITS] = '\0';
}

void binSum(char *num1, char *num2, char *sum){
    int carry = 0;
    for (int i = BITS - 1; i >= 0; i--){
        int sumBit = (num1[i] - '0') + (num2[i] - '0') + carry;
        sum[i] = (sumBit % 2) + '0';
        carry = sumBit / 2;
    }
}

int int10(char *sum){
    int number = 0;
    for (int i = 0; i < BITS; i++){
        number = (number << 1) | (sum[i] - '0');
    }
    return number;
}

int main(){
    int num1, num2;
    char bin1[BITS + 1], bin2[BITS + 1], sumBin[BITS + 1];
    printf("Введите первое число: ");
    scanf("%d", &num1);
    printf("Введите второе число: ");
    scanf("%d", &num2);
    
    bin(num1, bin1);
    printf("Первое число в двоичной сисеме: %s\n", bin1);

    bin(num2, bin2);
    printf("Второе число в двоичной системе: %s\n", bin2);
    
    binSum(bin1, bin2, sumBin);
    printf("Сумма в двоичной системе: %s\n", sumBin);
    
    int sum = int10(sumBin);
    printf("Сумма в десятичной системе: %d\n", sum);
    
    return 0;
}