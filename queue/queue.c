/**
 * Author: Jacob Rice
 * Description: queue array implementation in C using chars
 * Date: 01/12/2024
*/
#include "queue.h"

/* creates and returns a new q (variable args) */
Queue newQueue(int argc, ...) 
{
    Queue q;
    // create the new array for q
    char *arr = malloc(sizeof(char) * ARR_SZ);

    va_list vaList;

    // if the user provides values to add
    if(argc > 0) 
    {
        va_start(vaList, argc);

        int last = 0;
        for(int i=0; i<argc; i++) 
        {
            last++;
            arr[i] = (char)va_arg(vaList, int);
        }

        va_end(vaList);

        // for some reason last ends up as i+1
        q.back = last-1;
    }
    // user provides 0 as only arg (-1 is back for empty) 
    else
    {
        q.back = -1;
    }

    q.arr = arr;
    q.maxSize = ARR_SZ;

    return q;
}

/* adds a new char to the back of the queue */
void enqueue(char data, Queue *q) 
{   
    // if queue is full realloc 100 spaces in arr
    if(q->back + 1 >= q->maxSize)
    {
        q->maxSize += 100;
        q->arr = realloc(q->arr, sizeof(char) * q->maxSize);

        // null ptr
        if(q->arr == NULL)
        {
            printf("ERROR: realloc failed.\n");
            exit(1);
        }
    }

    // if queue is empty
    if(isEmpty(*q))
    {   
        q->arr[0] = data;
        q->back = 0;
        return;
    }

    q->arr[q->back+1] = data;
    q->back++;
}

/* removes the front value in the queue and return it */
char dequeue(Queue *q)
{   
    if(isEmpty(*q))
    {
        printf("ERROR: queue is empty. Returning '?'.\n");
        return '?';
    }

    char data = q->arr[0];

    for(int i=0; i<=q->back; i++)
    {
        q->arr[i] = q->arr[i+1];
    }

    q->back--;

    return data;
}

/* returns the front of the queue without removing it */
char front(Queue q)
{
    if(isEmpty(q))
    {
        printf("ERROR: queue is empty. Returning '?'.\n");
        return '?';
    }

    return q.arr[0];
}

/* returns 1 if queue is empty else 0 */
int isEmpty(Queue q) { return q.back == -1 ? 1 : 0; }

/* prints the queue front to back */
void printQ(Queue q) 
{
    if(isEmpty(q))
    {
        printf("ERROR: queue is empty.\n");
        return;
    }

    for(int i=0; i<=q.back; i++)
    {
        printf("%c ", (char)q.arr[i]);
    }

    printf("\n");
}