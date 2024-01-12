/**
 * Author: Jacob Rice
 * Description: compile w/ gcc -o example example.c simple-stack.c ../../linked-list/linked-list.c
 * Date: 01/12/2024
*/
#include "simple-stack.h"

/* main */ 
int main(int argc, char *argv[])
{   
    // reversing a stack
    struct stack stack1 = newStack(6, 1, 2, 3, 4, 5, 6);
    printStack(stack1);

    printf("%d\n", pop(&stack1));
    printStack(stack1);
    
    struct stack stack2 = newStack(0);
    
    while(!isEmptyStack(&stack1)) {
        int data = pop(&stack1);
        push(data, &stack2);
    }

    printStack(stack2);

    printf("\n");
    return 0;
}