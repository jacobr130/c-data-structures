/**
 * Author: Jacob Rice
 * Description: queue header file
 * Date: 01/12/2024
*/
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/* initial size of queue array */
#define ARR_SZ 100

/* queue type */
typedef struct {
    // the array behind the scenes
    char *arr;
    // the back of the queue (front is arr[0])
    int back;
    // the queues capacity; for arr expansion
    int maxSize;
} Queue;

/* prototypes */
Queue newQueue(int, ...);
void enqueue(char, Queue*);
char dequeue(Queue*);
char front(Queue);
int isEmpty(Queue);
void printQ(Queue);