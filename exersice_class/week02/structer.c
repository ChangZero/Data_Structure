#include<stdio.h>
#include<string.h>
typedef struct{
    int num;
    char name[50];
}info;

int main(void)
{
    info i1;
    i1.num = 10;
    strcpy(i1.name,"jin");
    i1.num += 1;
    printf("il.num=%d, i1.name=%s\n",i1.num,i1.name);
    return 0;
}