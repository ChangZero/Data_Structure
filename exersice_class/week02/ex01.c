#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX_TERMS 501

//희소행렬 만들기
typedef struct{
    int col;
    int row;
    int value;
}term;

term a[MAX_TERMS], b[MAX_TERMS];

void FAST_TRANS(term a[], term b[]){
    int row_terms[MAX_TERMS];
    int starting_pos[MAX_TERMS];
    int i,j;
    int num_cols = b[0].row = a[0].col;
    int num_terms = b[0].value = a[0].value;
    b[0].col = a[0].row;
    if(num_terms >0){
        for(i=0;i<num_cols;i++)
            row_terms[i]=0;
        for(i=1;i<=num_terms;i++)
            row_terms[a[i].col]++;

        starting_pos[0] =1;
        for(i=1;i<num_cols;i++)
            starting_pos[i]=starting_pos[i-1]+row_terms[i-1];
        for(i=1;i<=num_terms;i++){
            j=starting_pos[a[i].col]++;
            b[j].row=a[i].col;
            b[j].col=a[i].row;
            b[j].value=a[i].value;
        }
    }
}

void SIMPLE_TRANS(term a[], term b[]){
    int n,i,j,currentb;
    
    n= a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    if(n>0){
        currentb = 1;
        for(i=1;i<a[0].col;i++)
            for(j=1;j<=n;j++)
            if(a[j].col == i){
                b[currentb].row = a[j].col;
                b[currentb].col = a[j].row;
                b[currentb].value = a[j].value;
                currentb++;
            }

    }

}

int main(void)
{
    clock_t start, end;
    double duration;
    int i,k=0;
    start = clock();

    //a[0]값 입력해주기
	a[0].col = MAX_TERMS -1;
	a[0].row = MAX_TERMS -1 ;
	a[0].value = MAX_TERMS -1;
	
    //b[0]값 입력해주기
	b[0].col = MAX_TERMS -1;
	b[0].row = MAX_TERMS -1;
	b[0].value = MAX_TERMS -1;

    
    //a읙 값 초기화
    for(i=1;i<MAX_TERMS;i++){

            a[i].col = 0;
            a[i].row = i;
            a[i].value = 1;
      
    }
    //b의 값 초기화
    for(i=1;i<MAX_TERMS;i++){

            b[i].col = 0;
            b[i].row = i;
            b[i].value = 1;
      
    }
    
    //천번 돌려서 기간 비교
	while(k<1000){
		//FAST_TRANS(a,b); //FAST_TRANS()함수 호출
		SIMPLE_TRANS(a,b); //SIMPLE_TRANS()함수 호출
		k++;
	}

    end = clock();
    //시간 측정 결과
    duration = (double)(end - start);
    printf("duration = %lf\n", duration);

    return 0;
}
