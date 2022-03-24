#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEQE_SIZE 100
typedef struct data
{
    int key;
    char string[15];
}element;

element queue[MAX_QUEQE_SIZE];
//위치값 초기화 반드시 해줘야함 원형 큐일때는 0으로 주면 됨! 
int rear = -1;
int front = -1;

int IsEmptyQ(){
    return (front==rear);
}
int IsFullQ(){
    return (rear==MAX_QUEQE_SIZE -1);
}
void addq(element item){
    if(rear == MAX_QUEQE_SIZE-1){
        IsFullQ();
        return ;
    }
    else{
        queue[++rear] = item;
    }
}
element deleteq(){
    if(front == rear)
        IsEmptyQ();
    else{
        return queue[++front];
    }
}
int main(void)
{
    element q1 = {1,"stack"};
    addq(q1);
    element q2 = {2, "queue"};
    addq(q2);
    element q3 = {3, "array"};
    addq(q3);
    element q4 = {4, "struct"};
    addq(q4);
    element q5 = {5, "linked list"};
    addq(q5);

    element delq1 = deleteq();
    element delq2 = deleteq();
    printf("%d %s\n", delq1.key, delq1.string);
    printf("%d %s\n", delq2.key, delq2.string);
    
    return 0;
}