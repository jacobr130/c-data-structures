/**
 * Author: Jacob Rice
 * Description: stack C header file
 * Date: 01/12/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* stack struct */
struct stack {
    // the array behind the scenes
    char *arr;
    // the index of the stack's top value
    int top;
};

/* prototypes */
struct stack arr_to_stack(char arr[], size_t arr_length);
struct stack newStack(int argc, ...);
void push(char data, struct stack *stack);
char pop(struct stack *stack);
char peek(struct stack *stack);
int isEmpty(struct stack *stack);
void reverse(struct stack *stack);
void printStack(struct stack *stack);
