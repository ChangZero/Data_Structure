#include <stdio.h>
//A���� C�� ž�� �ű�� ����!
//n-1�� �϶� A���� B�� �ű�� ���� ��ȯ�Լ��� ����Ͽ� ȣ�� �� �� ���� ������ ž�� C�� �ű��� B���� C�� �ű�� ���� ��ȯ�Լ��� �ٽ� ȣ��!  
void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n==1)
        printf("���� 1�� %c���� %c���� �ű��.\n", from, to);
    else{
        hanoi_tower(n-1,from, to, tmp);
        printf("���� %d�� %c���� %c���� �ű��.\n", n, from, to);
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
