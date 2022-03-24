#include<stdio.h>
//Stack CreateS(max_stack_size)
#define MAX_STACK_SIZE 3
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1; //반드시 해줘야함
int IsEmpty()
{
    printf("Empty\n");
    return (top<0);
}
int IsFull()
{
    return (top>=MAX_STACK_SIZE-1);
}
void push(element item){
    if(top >= MAX_STACK_SIZE-1){
        IsFull();
        printf("Full\n");
        return;
    }
    stack[++top] = item;
}
element pop(){
    if(top == -1){
        IsEmpty();
    }
    else{
        printf("%d\n", stack[top]);
        return stack[(top)--];
    }
}

int main(void)
{
    pop();
    push(1);
    push(2);
    pop();
    push(3);
    push(4);
    push(5);
    pop();
    return 0;
}