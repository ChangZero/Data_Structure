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

int main()
{
    init(&heap1);
    element item;
    item.key = 10;
    insert_max_heap(&heap1, item);
    item.key = 5;
    insert_max_heap(&heap1, item);
    item.key = 30;
    insert_max_heap(&heap1, item);
    item.key = 25;
    insert_max_heap(&heap1, item);
    item.key = 20;
    insert_max_heap(&heap1, item);
    item.key = 3;
    insert_max_heap(&heap1, item);

    while (heap1.heap_size > 0)
    {
        if (heap1.heap_size == 1)
        {
            item = delete_max_heap(&heap1);
            printf("%d", item.key);
        }
        else
        {
            item = delete_max_heap(&heap1);
            printf("%d -> ", item.key);
        }
    }

    return 0;
}