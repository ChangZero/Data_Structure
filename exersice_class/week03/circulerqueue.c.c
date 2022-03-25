#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 3
typedef struct data
{
    int key;
    char string[15];
}element;

element queue[MAX_QUEUE_SIZE];
//��ġ�� �ʱ�ȭ �ݵ�� ������� ���� ť�϶��� 0���� �ָ� ��! 
int rear = 0;
int front = 0;

int IsEmptyQ(){
    return (front==rear);
}
int IsFullQ(){
    return (rear==MAX_QUEUE_SIZE);
}
void addq(element item){
	
    if(rear == MAX_QUEUE_SIZE){
        IsFullQ();
        return ;
    }
    else{
    	rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear] = item;
    }
}
element deleteq(){
    if(front == rear)
        IsEmptyQ();
    else{
    	front =( front + 1) % MAX_QUEUE_SIZE;
        return queue[front];
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
    
    
    element delq1 = deleteq();
    element delq2 = deleteq();
    element delq3 = deleteq();
    //element q4 = {4, "struct"};
    //addq(q4);
    //element delq4 = deleteq();
    element q5 = {5, "linked list"};
    addq(q5);

    
    
    printf("%d %s\n", delq1.key, delq1.string);
    printf("%d %s\n", delq2.key, delq2.string);
    printf("%d %s\n", delq3.key, delq3.string);
    //printf("%d %s\n", delq4.key, delq4.string);
    
    return 0;
}
