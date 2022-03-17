#include<stdio.h>
int fibo(int n)
{
    if (n<=2)
        return 1;
    else
        return fibo(n-1)+fibo(n-2);

}

int main(void)
{
    int num;
    scanf("%d", &num);
    for(int i=1;i<=num;i++){
        printf("%d ", fibo(i));
    }
    return 0;
}