/**
 * Author: Jacob Rice
 * Description: Stack linked list implementation in C using ints
 * Date: 01/12/2024
*/
#include "simple-stack.h"

/* creates a new stack. 0 for empty */
struct stack newStack(int argc, ...) {
    struct stack newStack;

    // the linked list the stack will point to
    struct LinkedList *list = malloc(sizeof(struct LinkedList));
    *list = newLinkedList(0);

    va_list vaList;

    // append the values if provided
    if(argc > 0) {
        va_start(vaList, argc);

        for(int i=0; i<argc; i++) {
            append(va_arg(vaList, int), list);
        }

        va_end(vaList);
    }

    newStack.list = list;

    return newStack;
}

/* adds the given value to the top of the stack */
void push(int data, struct stack *stack) { append(data, stack->list); }

/* returns and removes the stack's top */
int pop(struct stack *stack) {
    // if stack is empty, return -1
    if(stack->list->head == NULL) {
        printf("Stack is empty. Returning -1.\n");
        return -1;
    }

    int data = stack->list->tail->data;;

    deleteAt(stack->list->size-1, stack->list);

    return data;
}

/* returns the top of the stack without removing */
int peek(struct stack *stack) { return stack->list->tail->data; }

/* returns 1 if stack is empty else 0 */
int isEmptyStack(struct stack *stack) { return isEmpty(stack->list); }

/* prints the stack bottom to top */
void printStack(struct stack stack) { printForward(*stack.list); }