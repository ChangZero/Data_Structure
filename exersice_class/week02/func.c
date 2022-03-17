#include<stdio.h>
void function3(int x)
{
    x++;
}
void function4(int* x)
{
    (*x)++;
}
int main(void)
{
    int a=3;
    printf("a=%d\n", a);
    function3(a);
    printf("a=%d\n", a);
    function4(&a);
    printf("a=%d\n", a);
    return 0;
}