/**
 * Author: Jacob Rice
 * Description: compile w/ gcc -o example example.c linked-list.c
 * Date: 01/12/2024
*/
#include "linked-list.h"

/* main */
int main(int argc, char* argv[])
{   
    // initialize a new linked list
    struct LinkedList list = newLinkedList(0);

    // array to linked list
    int arr[5] = {1, 2, 3, 4, 5};
    list = array_to_list(arr, sizeof(arr) / sizeof(int));
    printForward(list);

    // initializing a new list
    struct LinkedList empty_list = newLinkedList(0);
    printForward(empty_list);   // gives error if list is empty

    struct LinkedList initialized_list = newLinkedList(6, 1, 2, 3, 4, 5, 6);
    printForward(initialized_list);

    // append
    append(6, &list);   
    printForward(list);

    // prepend
    prepend(0, &list);
    printForward(list);

    // get value at
    printf("%d\n", getValueAt(3, &list));
    printf("%d\n", getValueAt(4, &list));
    printf("%d\n", getValueAt(10, &list));  // out of range error

    // delete value at
    deleteAt(3, &list);
    printForward(list);

    // insert value at
    insertAt(3, 3, &list);
    printForward(list);

    // index of
    printf("index of 3: %d\tindex of 6: %d\n", indexOf(3, &list), indexOf(6, &list));

    // is empty
    printf("%d\n", isEmpty(&list));
    printf("%d\n", isEmpty(&empty_list));

    // clear
    clear(&list);
    printForward(list);
    
    printf("\n");
    return 0;
}