#include <stdio.h>
#define MAX_SIZE 10
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// 삽입 정렬
void print_list(int list[])
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}
int insertion_sort(int list[], int n)
{
    int i, j, key;
    int count = 0;
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
        print_list(list);
        count++;
    }
    return count;
}

int bubble_sort(int list[], int n)
{
    int i, j, temp;
    int count = 0;
    int flag = 1;
    for (i = n - 1; flag > 0; i--)
    {
        flag = 0;
        // 0 ~ (i-1)까지 반복
        for (j = 0; j < i; j++)
        {
            // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                flag = 1;
                count++;
                print_list(list);
            }
        }
    }
    return count;
}

int shell_sort(int array[], int size)
{
    int i, j, k, l, m;
    int count = 0;
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
        count++;
        print_list(array);
    }
    return count;
}

void quicksort(int list[], int left, int right)
{
    int pivot, i, j;
    int temp;
    if(left< right){
        i = left;
        j = right + 1;
        pivot = list[left];
        do{
            do{
                i++;
            }
            while (list[i] < pivot);
            do{
                j--;
            }
            while (list[j] > pivot);
            if (i < j)
            {
                swap(&list[i], &list[j]);
            }
        } while (i < j);
        swap(&list[left], &list[j]);
        quicksort(list, left, j - 1);
        quicksort(list, j + 1, right);
    }
}

int main()
{
    int i;
    int list1[MAX_SIZE] = {11, 10, 33, 22, 55, 9, 99, 81, 15, 27};
    int list2[MAX_SIZE] = {11, 10, 33, 22, 55, 9, 99, 81, 15, 27};
    int list3[MAX_SIZE] = {11, 10, 33, 22, 55, 9, 99, 81, 15, 27};
    int list4[MAX_SIZE] = {11, 10, 33, 22, 55, 9, 99, 81, 15, 27};
    printf("------Origianl Data------\n");
    print_list(list1);
    //버블 정렬 수행
    printf("\n------bubble Sorted data------\n");
    printf("swap : %d\n", bubble_sort(list1, MAX_SIZE));


    //삽입 정렬 수행
    printf("\n------insertion Sorted data------\n");
    printf("swap : %d\n", insertion_sort(list2, MAX_SIZE));

    //쉘 정렬 수행
    int size = sizeof(list3) / sizeof(int);
    printf("\n------shell Sorted data------\n");
    printf("swap : %d\n", shell_sort(list3, size));


    //quick sort
    printf("\n-----quick sorted data------\n");
    quicksort(list4, 0, 9);
    print_list(list4);

    return 0;
}