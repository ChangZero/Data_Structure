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

void init()
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
    strcpy(fev.name, "Feb");
    push(top, fev);
    strcpy(march.name, "Mar");
    push(top, march);
    strcpy(apr.name, "Apr");
    push(top, apr);
    strcpy(may.name, "May");
    push(top, may);
    strcpy(jun.name, "June");
    push(top, jun);
    strcpy(jul.name, "July");
    push(top, jul);
    strcpy(aug.name, "Aug");
    push(top, aug);
    strcpy(sep.name, "Sep");
    push(top, sep);
    strcpy(oct.name, "Oct");
    push(top, oct);
    strcpy(nov.name, "Nov");
    push(top, nov);
	strcpy(dec.name, "Dec");
    push(top, dec);
    
    
    for(i=0; i<12;i++){
		element popdata = pop(top);
    	printf("%s\n", popdata.name);
    }
    return 0;
}
