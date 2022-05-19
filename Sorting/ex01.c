#include<stdio.h>
#include<stdlib.h>
typedef int element;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(element list[], int n)
{
    int i, j;
    int flag = 1;
    element next;
    for (i = n - 1; flag > 0;i--){
        flag = 0;
        for (j = 0; j < i;j++)
            if(list[j] > list[j+1]){
                swap(&list[j], &list[j + 1]);
                flag = 1;
            }
    }
}

void insertion_sort(element a[], int n)
{
    int i, j;
    element next;
    for (i = 1; i <= n - 1;i++){
        next = a[i];
        for (j = i - 1; j >= 0 && next.key < a[j].key;j--)
            a[j + 1] = a[j];
        a[j + 1] = next;
    }
}

void shell_sort(int array[], int size)
{
    int i, j, k;
    for (i = size / 2; i > 0; i/=2){
        for (j = 0; j < i;j++){
            for (k = i + j; k < size; k+=i){
                int l = array[k];
                int m = k;
                while(m>i-1 && array[m-1] >1){
                    array[m] = array[m - 1];
                    m -= i;
                }
                array[m] = l;
            }
        }
    }
}