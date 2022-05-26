#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct
{
    int key;
} element;

typedef struct
{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType heap1;

HeapType *create()
{
    return (HeapType *)malloc(sizeof(HeapType));
}

void init(HeapType *h)
{
    h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item)
{
    int i;
    i = ++(h->heap_size);
    while ((i != 1) && (item.key > h->heap[i / 2].key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType *h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size)
    {
        if ((child < h->heap_size) &&
            ((h->heap[child].key) < h->heap[child + 1].key))
        {
            child++;
        }
        if (temp.key >= h->heap[child].key)
        {
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void adjust(element list[], int root, int n)
{
    int child, rootkey;
    element temp;
    temp = list[root];
    rootkey = list[root].key;

    child = 2 * root;
    while (child <= n)
    {
        if ((child < n) && (list[child].key < list[child + 1].key))
            child++;
        if (rootkey > list[child].key)
            break;
        else
        {
            list[child / 2] = list[child];
            child *= 2;
        }
    }
    list[child / 2] = temp;
}

void heapsort(element list[], int n)
{
    int i, j;
    element temp;
    for (i = n / 2; i > 0; i--)
        adjust(list, i, n);
    for (i = n - 1; i > 0; i--)
    {
        temp = list[1];
        list[1] = list[i + 1];
        list[i + 1] = temp;
        adjust(list, 1, i);
    }
}

int main()
{
    int i;
    init(&heap1);
    element item;

    printf("input start\n");

    for (i = 0; i < 20; i++){
        int num;
        printf("number: ");
        scanf("%d", &num);
        item.key = num;
        insert_max_heap(&heap1, item);
    }

    printf("heap sort: ");
    heapsort(heap1.heap, 20);
    for (i = 1; i <= 20;i++){
        printf("%d  ", heap1.heap[i]);
    }

    return 0;
}