#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUES 10
typedef int element;

typedef struct queue
{
    element item;
    struct queue *link;
} * queue_ptr;

queue_ptr front[MAX_QUEUES];
queue_ptr rear[MAX_QUEUES];

void init()
{
    for (int i = 0; i < MAX_QUEUES; i++)
    {
        front[i] = NULL;
        rear[i] = NULL;
    }
}

void insert(queue_ptr *pfront, queue_ptr *prear, element item)
{
    queue_ptr temp = (queue_ptr)malloc(sizeof(queue_ptr));

    temp->item = item;
    temp->link = NULL;
    if (*pfront)
        (*prear)->link = temp;
    else
        *pfront = temp;
    *prear = temp;
}

element delete (queue_ptr *pfront)
{
    queue_ptr temp = *pfront;
    element item;

    item = temp->item;
    *pfront = temp->link;
    free(temp);
    return item;
}
int main(void)
{

    return 0;
}