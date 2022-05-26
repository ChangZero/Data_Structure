#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void radix_sort(int a[], int size, int base)
{
    int ex, i, j, max = a[0];
    for (i = 1; i < size; i++)
        if (a[i] > max)
            max = a[i];
    for (ex = 1; ex <= max; ex *= base)
    {
        int output[size], count[base];
        memset(count, 0, sizeof(count));
        for (i = 0; i < size; i++)
            count[(a[i] / ex) % base]++;
        for (i = 1; i < base; i++)
            count[i] += count[i - 1];
        for (i = size - 1; i > -1; i--)
        {
            j = (a[i] / ex) % base;
            output[count[j] - 1] = a[i];
            count[j]--;
        }
        for (i = 0; i < size; i++)
            a[i] = output[i];
    }
}
int main()
{
    // char *inputarr[] = {"48081", "97342", "90287", "90583", "53202", "65215", "78397", "48001", "00972", "65315", "41983", "90283", "81554", "38107"};
    // int arr[14] = {0, };
    // int i;

    // for (i = 0; i < 14; i++){
    //     int num = atoi(inputarr[i]);
    //     arr[i] = num;
    // }
    // int size = sizeof(arr) / sizeof(int);
    // radix_sort(arr, size, 14);
    // for (int i = 0; i < size; i++)
    //     printf("%d ", arr[i]);

    int i, num;
    int arr[14] = {0, };

    printf("input data\n");
    for (i = 0; i < 14; i++)
    {
        char input[6];
        scanf("%s", input);
        arr[i] = atoi(input);
    }

    int size = sizeof(arr) / sizeof(int);

    printf("radix sort: ");
    radix_sort(arr, size, 14);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}