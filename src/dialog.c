int main()
{
    List* list = newList();
    int choice;

    do {
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            break;

        case 1:
            int value;
            scanf("%d", &value);
            insertSorted(list, value);
            break;

        case 2:
            int index;
            scanf("%d", &index);
            deleteValue(list, index);
            break;

        case 3:
            printList(list);
            break;
        }
    } while (choice != 0);
    deleteList(list);
    return 0;
}