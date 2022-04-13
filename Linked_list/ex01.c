#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACKS 100
typedef struct
{
    char name[100];
} element;

typedef struct stack
{
    element item;
    struct stack *link;
} * stack_ptr;

stack_ptr top[MAX_STACKS];

void init_stack()
{
    int i;
    for (i = 0; i < MAX_STACKS; i++)
        top[i] = NULL;
}

void push(stack_ptr *ptop, element item)
{
    stack_ptr temp = (stack_ptr)malloc(sizeof(struct stack));

    temp->item = item;
    temp->link = *ptop;
    *ptop = temp;
}

element pop(stack_ptr *ptop)
{
    stack_ptr temp = *ptop;
    element item;
    if (temp == NULL)
    {
        fprintf(stderr, "The stack is empty\n");
        exit(1);
    }
    item = temp->item;
    *ptop = temp->link;
    free(temp);
    return item;
}

#define MAX_QUEUES 10

typedef struct queue
{
    element item;
    struct queue *link;
} * queue_ptr;

queue_ptr front[MAX_QUEUES];
queue_ptr rear[MAX_QUEUES];

void init_queue()
{
    int i;
    for (i = 0; i < MAX_QUEUES; i++)
    {
        front[i] = NULL;
        rear[i] = NULL;
    }
}

void insert(queue_ptr *pfront, queue_ptr *prear, element item)
{
    queue_ptr temp = (queue_ptr)malloc(sizeof(struct queue));

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
    int i;
    element jan;
    element fev;
    element march;
    element apr;
    element may;
    element jun;
    element jul;
    element aug;
    element sep;
    element oct;
    element nov;
    element dec;

    strcpy(jan.name, "Jan");
    push(top, jan);
    insert(front, rear, jan);

    strcpy(fev.name, "Feb");
    push(top, fev);
    insert(front, rear, fev);

    strcpy(march.name, "Mar");
    insert(front, rear, march);
    push(top, march);

    strcpy(apr.name, "Apr");
    push(top, apr);
    insert(front, rear, apr);

    strcpy(may.name, "May");
    push(top, may);
    insert(front, rear, may);

    strcpy(jun.name, "June");
    push(top, jun);
    insert(front, rear, jun);

    strcpy(jul.name, "July");
    push(top, jul);
    insert(front, rear, jul);

    strcpy(aug.name, "Aug");
    push(top, aug);
    insert(front, rear, aug);

    strcpy(sep.name, "Sep");
    push(top, sep);
    insert(front, rear, sep);

    strcpy(oct.name, "Oct");
    push(top, oct);
    insert(front, rear, oct);

    strcpy(nov.name, "Nov");
    push(top, nov);
    insert(front, rear, nov);

    strcpy(dec.name, "Dec");
    push(top, dec);
    insert(front, rear, dec);

    printf("stack result\n");
    for (i = 0; i < 12; i++)
    {
        element popdata = pop(top);
        printf("%s\n", popdata.name);
    }
    printf("\nqueue result\n");
    for (i = 0; i < 12; i++)
    {
        element popdata = delete (front);
        printf("%s\n", popdata.name);
    }

    return 0;
}