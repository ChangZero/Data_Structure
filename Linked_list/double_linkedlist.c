#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct node *node_ptr;
typedef struct node
{
    node_ptr llink;
    element item;
    node_ptr rlink;
} node;

node_ptr head, tail;

void dinsert(node_ptr node, element item)
{
    node_ptr newnode = (node_ptr)malloc(sizeof(node_ptr));
    newnode->llink = node;
    newnode->rlink = node->rlink;
    node->rlink->llink = newnode;
    node->rlink = newnode;
}

void dinsert_rear(node_ptr node, element item)
{
    node_ptr newnode = (node_ptr)malloc(sizeof(node_ptr));
    newnode->item = item;
    newnode->rlink = node;
    newnode->llink = node->llink;
    node->llink->rlink = newnode;
    node->llink = newnode;
}

void ddelete(node_ptr node, node_ptr deleted)
{
    if (node == deleted)
        printf("Deletion of head and node not permitted\n");
    else
    {
        deleted->llink->rlink = deleted->rlink;
        deleted->rlink->llink = deleted->llink;
        free(deleted);
    }
}

void print_dlist(node_ptr phead)
{
    node_ptr p;
    int count = 0;
    for (p = phead->rlink; p != phead; p = p->rlink)
    {
        if (count == 0)
            printf("%d ", p->item);
        else
            printf("->%d ", p->item);
        count++;
    }
    printf("\n");
}

int main(void)
{

    head = (node_ptr)malloc(sizeof(node));

    tail = (node_ptr)malloc(sizeof(node));

    head->next = tail;

    head->prev = head;

    tail->next = tail;

    tail->prev = head;
    int i;
    node_ptr ptr = NULL;
    node_ptr node = (node_ptr)malloc(sizeof(node));
    printf("hello\n");
    dinsert(ptr, 1);
    // print_dlist(ptr);
    printf("hello\n");
    return 0;
}
