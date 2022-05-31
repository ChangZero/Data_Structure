#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 10000
typedef struct
{
    int key;
} element;

typedef struct
{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType heap_up, heap_down, heap_rand;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// print
void print_list(int list[], int size)
{
    printf("( ");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf(")\n");
}

// insertion sort
void insertion_sort(int list[], int n)
{
    int i, j, key;
    // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
    for (i = 1; i < n; i++)
    {
        key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

        // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
        // j 값은 음수가 아니어야 되고
        // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
        for (j = i - 1; j >= 0 && list[j] > key; j--)
        {
            list[j + 1] = list[j]; // 레코드의 오른쪽으로 이동
        }

        list[j + 1] = key;
    }
}

// shell sort
void shell_sort(int array[], int size)
{
    int i, j, k, l, m;
    for (i = size / 2; i > 0; i /= 2)
    {
        for (j = 0; j < i; j++)
        {
            for (k = i + j; k < size; k += i)
            {
                l = array[k];
                m = k;
                while (m > i - 1 && array[m - i] > l)
                {
                    array[m] = array[m - i];
                    m -= i;
                }
                array[m] = l;
            }
        }
    }
}

// quick sort
void quick_sort(int list[], int left, int right)
{
    int pivot, i, j;
    int temp;
    if (left < right)
    {
        i = left;
        j = right + 1;
        pivot = list[left];
        do
        {
            do
            {
                i++;
            } while (list[i] < pivot);
            do
            {
                j--;
            } while (list[j] > pivot);
            if (i < j)
            {
                swap(&list[i], &list[j]);
            }
        } while (i < j);
        swap(&list[left], &list[j]);
        quick_sort(list, left, j - 1);
        quick_sort(list, j + 1, right);
    }
}

// heap sort
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

void heap_sort(element list[], int n)
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
    int size, i, idx1, idx2;
    double n, y, duration;
    clock_t start, finish;
    element item;

    srand(time(NULL));

    printf("input: N=");
    scanf("%d", &size);

    

    int *arr_up = (int *)malloc(sizeof(int) * size);
    int *arr_down = (int *)malloc(sizeof(int) * size);
    int *arr_rand = (int *)malloc(sizeof(int) * size);

    for (i = 0; i < size; i++)
    {
        arr_up[i] = i + 1;
        arr_rand[i] = i + 1;
    }

    for (i = size; i > 0; i--)
    {
        arr_down[size - i] = i;
    }

    for (i = 0; i < size / 2; i++)
    {
        idx1 = rand() % size;
        idx2 = rand() % size;
        swap(&arr_rand[idx1], &arr_rand[idx2]);
    }

    printf("-------초기 배열 입력------\n");
    printf("오름차순 ");
    print_list(arr_up, size);
    printf("내림차순 ");
    print_list(arr_down, size);
    printf("랜덤배열 ");
    print_list(arr_rand, size);
    printf("------------------------------\n");

    // inserttion
    // arr_up
    start = clock();
    insertion_sort(arr_up, size);
    finish = clock();
    duration = (double)(finish - start);
    printf("---insertion sort arr_up---\n");
    printf("duration = %0lf\n", duration);
    // arr_down
    start = clock();
    insertion_sort(arr_down, size);
    finish = clock();
    duration = (double)(finish - start);
    printf("---insertion sort arr_down---\n");
    printf("duration = %0lf\n", duration);
    // arr_rand
    start = clock();
    insertion_sort(arr_rand, size);
    finish = clock();
    duration = (double)(finish - start);
    printf("---insertion sort arr_rand---\n");
    printf("duration = %0lf\n", duration);

    // print
    printf("오름차순 ");
    print_list(arr_up, size);
    printf("내림차순 ");
    print_list(arr_down, size);
    printf("랜덤배열 ");
    print_list(arr_rand, size);

    printf("------------------------------\n");

    for (i = 0; i < size; i++)
    {
        arr_up[i] = i + 1;
        arr_rand[i] = i + 1;
    }

    for (i = size; i > 0; i--)
    {
        arr_down[size - i] = i;
    }

    for (i = 0; i < size / 2; i++)
    {
        idx1 = rand() % size;
        idx2 = rand() % size;
        swap(&arr_rand[idx1], &arr_rand[idx2]);
    }

    // shell sort
    // arr_up
    start = clock();
    shell_sort(arr_up, size);
    finish = clock();
    duration = (double)(finish - start);
    printf("---shell sort arr_up---\n");
    printf("duration = %0lf\n", duration);
    // arr_down
    start = clock();
    shell_sort(arr_down, size);
    finish = clock();
    duration = (double)(finish - start);
    printf("---shell sort arr_down---\n");
    printf("duration = %0lf\n", duration);
    // arr_rand
    start = clock();
    shell_sort(arr_rand, size);
    finish = clock();
    duration = (double)(finish - start);
    printf("---shell sort arr_rand---\n");
    printf("duration = %0lf\n", duration);

    // print
    printf("오름차순 ");
    print_list(arr_up, size);
    printf("내림차순 ");
    print_list(arr_down, size);
    printf("랜덤배열 ");
    print_list(arr_rand, size);

    printf("------------------------------\n");

    for (i = 0; i < size; i++)
    {
        arr_up[i] = i + 1;
        arr_rand[i] = i + 1;
    }

    for (i = size; i > 0; i--)
    {
        arr_down[size - i] = i;
    }

    for (i = 0; i < size / 2; i++)
    {
        idx1 = rand() % size;
        idx2 = rand() % size;
        swap(&arr_rand[idx1], &arr_rand[idx2]);
    }

    // quick sort
    // arr_up
    start = clock();
    quick_sort(arr_up, 0, size - 1);
    finish = clock();
    duration = (double)(finish - start);
    printf("---quick sort arr_up---\n");
    printf("duration = %0lf\n", duration);
    // arr_down
    start = clock();
    quick_sort(arr_down, 0, size - 1);
    finish = clock();
    duration = (double)(finish - start);
    printf("---quick sort arr_down---\n");
    printf("duration = %0lf\n", duration);
    // arr_rand
    start = clock();
    quick_sort(arr_rand, 0, size - 1);
    finish = clock();
    duration = (double)(finish - start);
    printf("---quick sort arr_rand---\n");
    printf("duration = %0lf\n", duration);

    // print
    printf("오름차순 ");
    print_list(arr_up, size);
    printf("내림차순 ");
    print_list(arr_down, size);
    printf("랜덤배열 ");
    print_list(arr_rand, size);

    printf("------------------------------\n");

    for (i = 0; i < size; i++)
    {
        arr_up[i] = i + 1;
        arr_rand[i] = i + 1;
    }

    for (i = size; i > 0; i--)
    {
        arr_down[size - i] = i;
    }

    for (i = 0; i < size / 2; i++)
    {
        idx1 = rand() % size;
        idx2 = rand() % size;
        swap(&arr_rand[idx1], &arr_rand[idx2]);
    }

    // heap sort
    // arr_up
    init(&heap_up);
    for (i = 0; i < size; i++)
    {
        item.key = arr_up[i];
        insert_max_heap(&heap_up, item);
    }
    start = clock();
    heap_sort(heap_up.heap, size);
    finish = clock();
    duration = (double)(finish - start);
    printf("---heap sort arr_up---\n");
    printf("duration = %0lf\n", duration);
    // arr_down
    init(&heap_down);
    for (i = 0; i < size; i++)
    {
        item.key = arr_down[i];
        insert_max_heap(&heap_down, item);
    }
    start = clock();
    heap_sort(heap_down.heap, size);
    finish = clock();
    duration = (double)(finish - start);
    printf("---heap sort arr_down---\n");
    printf("duration = %0lf\n", duration);
    // arr_rand
    init(&heap_rand);
    for (i = 0; i < size; i++)
    {
        item.key = arr_rand[i];
        insert_max_heap(&heap_rand, item);
    }
    start = clock();
    heap_sort(heap_rand.heap, size);
    finish = clock();
    duration = (double)(finish - start);
    printf("---heap sort arr_rand---\n");
    printf("duration = %0lf\n", duration);

    printf("오름차순 ( ");
    for (i = 1; i <= size; i++)
    {
        printf("%d ", heap_up.heap[i]);
    }
    printf(")\n");
    printf("내림차순 ( ");
    for (i = 1; i <= size; i++)
    {
        printf("%d ", heap_down.heap[i]);
    }
    printf(")\n");
    printf("랜덤배열 ( ");
    for (i = 1; i <= size; i++)
    {
        printf("%d ", heap_rand.heap[i]);
    }
    printf(")\n");
    return 0;
}
