#include <stdio.h>
#include <stdlib.h>

typedef struct list_node
{
    int data;
    struct list_node *link;
} *list_ptr;


list_ptr* insert_front(list_ptr pptr, list_ptr node)
{
    if (!(pptr))
    {
        pptr = node;
        node->link = node;
    }

    else
    {
        node->link = pptr->link;
        pptr->link = node;
    }
    return pptr;
}

list_ptr* insert_rear(list_ptr pptr, list_ptr node)
{
    if (!(pptr))
    {
        pptr = node;
        node->link = node;
    }
    else
    {
        node->link = pptr->link;
        pptr->link = node;
        pptr = node;
        // printf("%d\n", (*pptr)->data );
    }
    //printf("%d\n", (*pptr)->link->data);
    return pptr;
}

int length(list_ptr ptr)
{
    list_ptr temp;
    int count = 0;
    if (ptr)
    {
        temp = ptr;
        do
        {
            count++;
            temp = temp->link;
        } while (temp != ptr);
    }
    return count;
}

void print_list(list_ptr phead)
{
    list_ptr p;
    // for (; phead; phead = phead->link)
    //     printf("%d\n", phead->data);
    // printf("\n");
    int count = 0;

    if (phead == NULL)
        return;

    p = phead->link;
    do
    {
        printf("%d -> ", p->data);
        p = p->link;
        count++;
    } while (p != phead);

    if (count != 1)
        printf("%d\n", p->data);
}

int main(void)
{

    list_ptr ptr;
    list_ptr node = (list_ptr)malloc(sizeof(struct list_node));
    node->link = NULL;

    int i;
    node->data = 2;
    ptr = insert_rear(*ptr, node);
    node->data = 4;
    ptr = insert_rear(*ptr, node);
    node->data = 6;
    ptr = insert_rear(*ptr, node);

    printf("%d\n", (*ptr)->data);
    printf("length: %d\n", length(*ptr));
    printf("%d\n", (*ptr)->link->data);
    return 0;
}