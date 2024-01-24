/**
 * Author: Jacob Rice
 * Description: for colored output and clear
 * Date: 01/24/2024
*/
#include <stdio.h>

/* text colors */
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PROMPT_CURSOR "\033[37;4m> "

/* clears the terminal screen */
void clrscr() { printf("\e[1;1H\e[2J\n"); }
