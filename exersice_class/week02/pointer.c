#include<stdio.h>
int main(void)
{
    int num = 3;
    int* pnum;

    pnum = &num;

    printf("num=%d\n", num);
    printf("&num=%d\n",&num);
    printf("*pnum=%d\n", *pnum);
    printf("pnum=%d\n", pnum);
    printf("&pnum=%d\n", &pnum);
    return 0;
}