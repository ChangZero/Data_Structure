#include <stdio.h>
int fact(int n)
{
    if (n<=1)
        return 1;
    else
        return (n*fact(n-1));
}

int main(void)
{
    int nFactValue = 0;
    nFactValue = fact(5);
    printf("%d", nFactValue);
}