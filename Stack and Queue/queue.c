#define MAX_QUEQE_SIZE 100
typedef char element;
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
void addq(int *prear,element item){
    if(*prear == MAX_QUEQE_SIZE-1){
        IsFullQ();
        return ;
    }
    queue[++*prear] = item;
}
element deleteq(int *pfront, int rear){
    if(*pfront == rear)
        return IsEmptyQ();
    return queue[++*pfront];
}
int main(void)
{
    return 0;
}