#include "sortedList.h"
#include <stdio.h>

int main()
{
    List* list = new();
    int choice = 0;

    do {
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            break;

        case 1:
            int value = 0;
            scanf("%d", &value);
            insertListElement(list, value);
            break;

        case 2:
            int index = 0;
            scanf("%d", &index);
            deleteListElement(list, index);
            break;

        case 3:
            printList(list);
            break;
        }
    } while (choice != 0);
    deleteList(list);
    return 0;
}