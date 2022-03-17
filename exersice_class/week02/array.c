#include<stdio.h>
int main(void)
{
    int list[3];
    int i,sum=0;
    for(i=0;i<3;i++)
    {
        printf("%d번째 값 입력",i+1);
        scanf("%d", &list[i]);
    }

    for(i=0;i<3;i++)
        sum += list[i];

    printf("합은: %d\n", sum);

    return 0;
}