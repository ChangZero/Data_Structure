#include <stdio.h>
//A에서 C로 탑을 옮기는 문제!
//n-1개 일때 A에서 B로 옮기는 것을 순환함수를 사용하여 호출 그 후 가장 마지막 탑을 C로 옮긴후 B에서 C로 옮기는 것을 순환함수로 다시 호출!  
void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n==1)
        printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
    else{
        hanoi_tower(n-1,from, to, tmp);
        printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
        hanoi_tower(n-1,tmp,from,to);
    }
}
int main(void)
{   
    int num;
    scanf("%d", &num);
    hanoi_tower(num, 'A','B','C');
    return 0;
}
