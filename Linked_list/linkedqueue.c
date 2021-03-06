#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUES 10
typedef struct
{
    char name[100];
} element;

typedef struct queue
{
    element item;
    struct queue *link;
} * queue_ptr;

queue_ptr front[MAX_QUEUES];
queue_ptr rear[MAX_QUEUES];

void init()
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
    insert(front, rear, jan);
    strcpy(fev.name, "Feb");
    insert(front, rear, fev);
    strcpy(march.name, "Mar");
    insert(front, rear, march);
    strcpy(apr.name, "Apr");
    insert(front, rear, apr);
    strcpy(may.name, "May");
    insert(front, rear, may);
    strcpy(jun.name, "June");
    insert(front, rear, jun);
    strcpy(jul.name, "July");
    insert(front, rear, jul);
    strcpy(aug.name, "Aug");
    insert(front, rear, aug);
    strcpy(sep.name, "Sep");
    insert(front, rear, sep);
    strcpy(oct.name, "Oct");
    insert(front, rear, oct);
    strcpy(nov.name, "Nov");
    insert(front, rear, nov);
	strcpy(dec.name, "Dec");
    insert(front, rear, dec);
    
    
    for(i=0; i<12;i++){
		element popdata = delete(front);
    	printf("%s\n", popdata.name);
    }
    return 0;
}
