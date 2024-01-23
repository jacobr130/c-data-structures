/**
 * Author: Jacob Rice
 * Description: compile w/ gcc -o example example.c stack.c
 * Date: 01/12/2024
*/
#include "stack.h"

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