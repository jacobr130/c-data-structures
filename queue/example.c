/**
 * Author: Jacob Rice
 * Description: compile w/ gcc -o example example.c queue.c
 * Date: 01/12/2024
*/
#include "queue.h"

int main(int argc, char* argv[])
{
    Queue q1 = newQueue(3, 'a', 'b', 'c');
    printQ(q1);

    // enqueue
    enqueue('d', &q1);
    printQ(q1);

    // dequeue
    printf("dequeue: %c\n", dequeue(&q1));
    printf("dequeue: %c\n", dequeue(&q1));
    printQ(q1);

    // front
    printf("front: %c\n", front(q1));

    printf("dequeue: %c\n", dequeue(&q1));
    printf("dequeue: %c\n", dequeue(&q1));
    printQ(q1);

    // enqueueing way too many values
    for(int i=0; i<=300; i++)
    {
        enqueue('?', &q1);
    }

    printQ(q1);

    printf("\n");
    return 0;
}