/**
 * Author: Jacob Rice
 * Description: Linked list C implementation using integers
 * Date: 1/10/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* prototypes 
 * all functions manipulating a list take in the address
 * of the list to be altered because when you pass an actual
 * list, a copy is made and the original remains unchanged
*/
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

/* shorthand for node memory size */
#define NODE_SIZE sizeof(struct Node)

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

/* creates a new linked list. argc is list length. takes int args */
struct LinkedList newLinkedList(int argc, ...) {
    struct LinkedList list;
    list.size = argc;

    va_list vaList;

    if(argc > 0) {
        va_start(vaList, argc);
        
        // need to start with head and tail because of append()
        struct Node *first = malloc(NODE_SIZE);
        first->data = va_arg(vaList, int);

        struct Node *second = malloc(NODE_SIZE);
        second->data = va_arg(vaList, int);

        list.head = first;
        list.tail = second;
        list.head->next = list.tail;

        int count = 0;
        for(int i=0; i<argc-2; i++) {
            append(va_arg(vaList, int), &list);
        }
    }
    else {
        list.head = NULL;
        list.tail = NULL;
    }

    return list;
}

/* takes an array and converts it to a linked list */
struct LinkedList array_to_list(int *arr, size_t arr_size) {
    struct LinkedList list;
    list.size = arr_size;

    // create the head node
    struct Node *head = malloc(NODE_SIZE);
    list.head = head;
    list.head->data = arr[0];
    list.head->next = NULL;

    // the node to be incremented 
    struct Node *cur = list.head;

    // string the rest of the values together (stops before tail)
    for(int i=1; i<arr_size-1;i++) {
        struct Node *new = malloc(NODE_SIZE);
        new->data = arr[i];
        new->next = NULL;

        cur->next = new;
        cur = new;
    }

    // add the tail node to the list
    struct Node *tail = malloc(NODE_SIZE);
    list.tail = tail;
    list.tail->data = arr[arr_size-1];
    cur->next = list.tail;
    list.tail->next = NULL;

    return list;
}

/* appends a value to a linked list 
 * have to pass a pointer to the address
 * because structs get copied when passed
*/
void append(int data, struct LinkedList *list) {
    // null pointer check
    if(list == NULL) {
        printf("ERROR: null pointer; linked list is NULL.\n");
        return;
    }

    struct Node *new = malloc(NODE_SIZE);
    new->data = data;
    new->next = NULL;

    list->tail->next = new;
    list->tail = new;
    list->size++;
}

/* prepends a value to a linked list */
void prepend(int data, struct LinkedList *list) {
    // null pointer check
    if(list == NULL) {
        printf("ERROR: null pointer; linked list is NULL.\n");
        return;
    }

    struct Node *new = malloc(NODE_SIZE);
    new->data = data;
    new->next = list->head;
    list->head = new;
    list->size++;
}

/* returns the value in a list at the given index */
int getValueAt(int index, struct LinkedList *list) {
    // null pointer check
    if(list == NULL) {
        printf("ERROR: null pointer; linked list is NULL.\n");
        return -1;
    }

    // return -1 if index is out of range
    if(index >= list->size) {
        printf("ERROR: list index out of range for index %d.\n", index);
        return -1;
    }

    struct Node *cur = malloc(NODE_SIZE);
    cur = list->head;

    // walk the list to index
    for(int i=0; i<index; i++) {
        cur = cur->next;
    }

    return cur->data;
}

/* removes the value in a list at the given index */
void deleteAt(int index, struct LinkedList *list) {
    // null pointer check
    if(list == NULL) {
        printf("ERROR: null pointer; linked list is NULL.\n");
        return;
    }

    // return if index is out of range
    if(index >= list->size) {
        printf("ERROR: list index out of range for index %d.\n", index);
        return;
    }

    struct Node *cur = malloc(NODE_SIZE);
    cur = list->head;

    // walk the list to before index
    for(int i=0; i<index-1; i++) {
        cur = cur->next;
    }

    // jump over the deleted node
    cur->next = cur->next->next;
}

/* inserts a value to a linked list at the given index */
void insertAt(int index, int data, struct LinkedList *list) {
    // null pointer check
    if(list == NULL) {
        printf("ERROR: null pointer; linked list is NULL.\n");
        return;
    }

    // index can't be greater than 1 more than last index
    if(index > list->size) {
        printf("ERROR: index out of range for index %d.\n", index);
    }

    struct Node *new = malloc(NODE_SIZE);
    new->data = data;
    new->next = NULL;

    struct Node *cur = malloc(NODE_SIZE);
    cur = list->head;

    for(int i=0; i<index-1; i++) {
        cur = cur->next;
    }

    new->next = cur->next;
    cur->next = new;
}

/* returns the index of the first matching node */
int indexOf(int data, struct LinkedList *list) {
    // null pointer check
    if(list == NULL) {
        printf("ERROR: null pointer; linked list is NULL.\n");
        return -1;
    }

    struct Node *cur = malloc(NODE_SIZE);
    cur = list->head;

    for(int i=0; i<list->size; i++) {
        if(cur->data == data) {
            return i;
        }
        cur = cur->next;
    }

    // if node cannot be found
    return -1;
}

/* returns 1 if list is empty else 0 */
int isEmpty(struct LinkedList *list) {
    // null pointer check
    if(list == NULL) {
        printf("ERROR: null pointer; linked list is NULL.\n");
        return -1;
    }

    return list->head == NULL ? 1 : 0;
}

/* clears all nodes from the given list */
void clear(struct LinkedList *list) {
    // null pointer check
    if(list == NULL) {
        printf("ERROR: null pointer; linked list is NULL.\n");
        return;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/* walks a linked list forwards printing each value */
void printForward(struct LinkedList list) {
    if(list.head == NULL) {
        printf("ERROR: linked list is empty.\n");
        return;
    }

    struct Node *cur = malloc(NODE_SIZE);
    cur = list.head;

    // print up to tail
    while(cur->next != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    // print tail
    printf("%d\n", list.tail->data);
}