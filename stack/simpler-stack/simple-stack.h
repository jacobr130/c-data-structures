/**
 * Author: Jacob Rice
 * Description: A header file for simple-stack
 * Date: 01/12/2024
*/
#include "../linked-list/linked-list.h"

struct stack {
    // the linked list behind the scenes
    struct LinkedList *list;
};

/* prototypes */
struct stack newStack(int argc, ...);
void push(int data, struct stack *stack);
int pop(struct stack *stack);
int peek(struct stack *stack);
int isEmptyStack(struct stack *stack);
void printStack(struct stack stack);
