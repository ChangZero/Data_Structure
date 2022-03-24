#include<stdio.h>
//Stack CreateS(max_stack_size)
#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1; //반드시 해줘야함
int IsEmpty()
{
    return (top<0);
}
int IsFull()
{
    return (top>=MAX_STACK_SIZE-1);
}
void push(int *ptop, element item){
    if(*ptop >= MAX_STACK_SIZE-1){
        IsFull();
        return;
    }
    stack[++*ptop] = item;
}
element pop(int *ptop){
    if(*ptop == -1)
        return IsEmpty();
    return stack[(*ptop)--];
}

int main(void)
{
    return 0;
}