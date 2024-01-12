/**
 * Author: Jacob Rice
 * Description: Queue array implementation in C using chars
 * Date: 1/11/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* the size of a stack's array starts at 100 */
#define ARR_SIZE 100

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

/* main */ 
int main(int argc, char *argv[])
{   
    // reversing a word
    struct stack hamood = newStack(6, 'h', 'a', 'm', 'o', 'o', 'd');
    printStack(&hamood);
    
    struct stack doomah = newStack(0);
    while(!isEmpty(&hamood)) { push(pop(&hamood), &doomah); }
    printStack(&doomah);

    printf("\n");
    return 0;
}

/* converts a given array to a stack */
struct stack arr_to_stack(char arr[], size_t arr_length) {
    struct stack newStack;

    newStack.arr = arr;
    newStack.top = arr_length;

    return newStack;
}

/* creates a new stack. pass 0 for empty 
 * in this case, argc is the size of the stack
 * the function takes a variable number of char arguments
 *  that are added to the stack
*/
struct stack newStack(int argc, ...) {
    struct stack newStack;
    va_list vaList;

    // 100 chars should be enough
    char *arr = malloc(ARR_SIZE * sizeof(char));

    // null ptr check
    if(arr == NULL) {
        printf("ERROR: shit is fubar. returning null stack.\n");

        newStack.arr = NULL;
        newStack.top = -1;

        return newStack;
    }

    // if the user provides chars, add them to the stack
    if(argc > 0) {
        va_start(vaList, argc);

        int count = 0;
        for(int i=0; i<argc; i++) {
            arr[i] = (char)va_arg(vaList, int);
            count++;
        }

        newStack.arr = arr;
        newStack.top = count;

        va_end(vaList);
    } 
    else {
        newStack.arr = arr;
        newStack.top = -1;  // top == -1 for empty stack
    }


    return newStack;
}

/* adds the given value to the top of the stack */
void push(char data, struct stack *stack) {
    stack->top++;
    stack->arr[stack->top] = data;
}

/* removes and returns the stack's top value */
char pop(struct stack *stack) {
    if(!isEmpty(stack)) {
        char data = stack->arr[stack->top];
        stack->top--;

        return data;
    }

    return -1;
}

/* returns the stack's top value without removing it */
char peek(struct stack *stack) { return stack->arr[stack->top]; }

/* returns 1 if the stack is empty else 0 */
int isEmpty(struct stack *stack) { return stack->top == -1 ? 1 : 0; }

/* prints the stack bottom to top */
void printStack(struct stack *stack) {
    for(int i=0; i<=stack->top; i++) {
        printf("%c", stack->arr[i]);
    }

    printf("\n");
}