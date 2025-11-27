#include "list.h"
#include "stdio.h"
#include <stdlib.h>

int schitalochka(int n, int m)
{
    if (n <= 0 || m <= 0) {
        return -1;
    }

    List* warriors = new();

    for (int i = 0; i < n; i++) {
        insertList(warriors, i, i + 1);
    }
    ListNode* current = warriors->tail->next;
    int step = 1;
    while (warriors->tail->next != warriors->tail) {
        if (step == m - 1) {

            ListNode* victim = current->next;
            current->next = victim->next;

            if (warriors->tail == victim) {
                warriors->tail = current;
            }
            free(victim);
            current = current->next;
            step = 1;
        } else {
            current = current->next;
            step++;
        }
    }
    int k = warriors->tail->value;
    printf("Последним остался воин: %d\n", k);
    deleteList(warriors);
    return k;
}
int main()
{
    printf("Введите количество воинов: ");
    int n = 0;
    scanf("%d", &n);
    printf("Введите шаг убийства: ");
    int m = 0;
    scanf("%d", &m);
    schitalochka(n, m);
    return 0;
}