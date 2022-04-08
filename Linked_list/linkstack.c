#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACKS 10
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

void init()
{
    for (int i = 0; i < MAX_STACKS; i++)
        top[i] = NULL;
}

void push(stack_ptr *ptop, element item)
{
    stack_ptr temp = (stack_ptr)malloc(sizeof(stack_ptr));

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

int main(void)
{
    element data;
    strcpy(data.name, "JUN");
    push(top, data);

    element popdata = pop(top);
    printf("%s\n", popdata.name);
    return 0;
}
