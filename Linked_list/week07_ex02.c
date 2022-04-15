#include <stdio.h>

#include <stdlib.h>

typedef struct Node *NodePointer;

typedef struct Node
{
    int data;
    NodePointer prev;
    NodePointer next;
} Node;

NodePointer head, tail;

void insert_rear(int data)
{

    NodePointer i, element;

    i = head->next;

    while (i != tail)

        i = i->next;

    element = (NodePointer)malloc(sizeof(Node));
    element->data = data;
    i->prev->next = element;
    element->prev = i->prev;
    i->prev = element;
    element->next = i;
}

void insert_front(int data)
{
    NodePointer i, element;
    i = head;
    element = (NodePointer)malloc(sizeof(Node));
    element->data = data;
    element->prev = i;
    element->next = i->next;
    i->next->prev = element;
    i->next = element;
}

void insert_middle(int data, int std)
{
    NodePointer i, element;

    element = (NodePointer)malloc(sizeof(Node));
    for (i = head->next; i->next != tail; i = i->next)
    {
        if (i->prev->data == std)
        {
            break;
        }
    }
    element->data = data;
    i->prev->next = element;
    element->prev = i->prev;
    i->prev = element;
    element->next = i;
}
void show()
{

    NodePointer i;

    i = head->next;

    while (i != tail)
    {
        if (i->next == tail)
        {
            printf("%d", i->data);
            break;
        }
        printf("%d-> ", i->data);
        i = i->next;
    }
    printf("\n");
}

int main(void)
{
    head = (NodePointer)malloc(sizeof(Node));
    tail = (NodePointer)malloc(sizeof(Node));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
    int i;
    for (i = 2; i <= 20; i += 2)
    {
        insert_rear(i);
    }
    show();
    insert_front(1);
    show();
    insert_rear(21);
    show();
    insert_middle(11, 18);
    show();

    return 0;
}
