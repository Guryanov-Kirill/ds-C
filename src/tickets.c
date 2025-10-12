#include <stdio.h>

int main(void)
{
    int ticketsSum[28] = { 0 };

    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                ticketsSum[a + b + c]++;
            }
        }
    }
    int col = 0;
    for (int i; i < 28; i++) {
        col += ticketsSum[i] * ticketsSum[i];
    }
    printf("Количество счастливых билетиков: %d\n", col);
    return 0;
}