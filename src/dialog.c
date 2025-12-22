#include "sortedList.h"
#include <stdio.h>

enum state {
    EXIT = 0,
    ADD = 1, 
    DELETE = 2,
    PRINT = 3
};

int main()
{
    List* list = new();
    int choice = 0;

    do {
        scanf("%d", &choice);
        switch (choice) {
        case EXIT:
            break;

        case ADD:
            int value = 0;
            scanf("%d", &value);
            insertListElement(list, value);
            break;

        case DELETE:
            int index = 0;
            scanf("%d", &index);
            deleteListElement(list, index);
            break;

        case PRINT:
            printList(list);
            break;
        }
    } while (choice != EXIT);
    deleteList(list);
    return 0;
}