#include<stdio.h>

double slow_power(double x, int n)
{
    int i;
    double r = 1.0; //결과값이 큰 수가 될 수 있음으로 실수로 정의
    for(i=1;i<=n;i++){
        r = r*x;
    }

    return(r);
}
void main(){
    printf("%0.f", slow_power(3.0, 5));
}