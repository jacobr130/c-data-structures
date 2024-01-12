/**
 * Author: Jacob Rice
 * Description: Linked list C header file
 * Date: 01/10/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* prototypes */
struct LinkedList newLinkedList(int argc, ...);
struct LinkedList array_to_list(int *arr, size_t arr_size);
void append(int data, struct LinkedList *list);
void prepend(int data, struct LinkedList *list);
int getValueAt(int index, struct LinkedList *list);
void deleteAt(int index, struct LinkedList *list);
void insertAt(int index, int data, struct LinkedList *list);
int indexOf(int data, struct LinkedList *list);
int isEmpty(struct LinkedList *list);
void clear(struct LinkedList *list);
void printForward(struct LinkedList list);

/* a single node of our linked list */
struct Node {
    int data;
    struct Node *next;
};

/* linked list struct */
struct LinkedList {
    struct Node *head;
    struct Node *tail;
    size_t size;
};