#include <stdio.h>
#include <string.h>
#define KEY_SIZE 10   // 탐색키의 최대길이
#define TABLE_SIZE 13 // 해싱 테이블의 크기=소수
typedef struct
{
    char key[KEY_SIZE];
    // 다른 필요한 필드들을 여기에 넣는다.
} element;
element hash_table[TABLE_SIZE]; // 해싱 테이블

void init_table(element ht[])
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        ht[i].key[0] = NULL;
    }
}

// 문자로 된 탐색키를 숫자로 변환
int transform(char *key)
{
    int number = 0;
    while (*key) // 간단한 덧셈 방식 사용 자연수 생성
        number += *key++;
    return number;
}
// 제산 함수를 사용한 해싱 함수
int hash_function(char *key)
{
    return transform(key) % TABLE_SIZE;
}

#define empty(e) (strlen(e.key) == 0)
#define equal(e1, e2) (!strcmp(e1.key, e2.key))

// 선형 조사법을 이용하여 테이블에 키를 삽입하고,
// 테이블이 가득 찬 경우는 종료
void hash_lp_add(element item, element ht[])
{
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i]))
    {
        if (equal(item, ht[i]))
        {
            fprintf(stderr, "탐색키가 중복되었습니다\n");
            return;
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value)
        {
            fprintf(stderr, "테이블이 가득찼습니다\n");
            return;
        }
    }
    ht[i] = item;
}

void hash_lp_delete(element item, element ht[])
{
    int i;
    i = hash_function(item.key);
    for (int j = 0; j < KEY_SIZE; j++)
    {
        ht[i].key[j] = NULL;
    }
}

// 선형조사법을 이용하여 테이블에 저장된 키를 탐색
void hash_lp_search(element item, element ht[])
{
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (ht[i].key)
    {
        if (equal(item, ht[i]))
        {
            fprintf(stderr, "탐색성공: 위치 = %d\n", i);
            return;
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value)
        {
            fprintf(stderr, "찾는 값이 테이블에 없음\n");
            return;
        }
    }
    fprintf(stderr, "찾는 값이 테이블에 없음\n");
}

// 해싱 테이블의 내용을 출력
void hash_lp_print(element ht[])
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        printf("[%d]	%s\n", i, ht[i].key);
}

// 해싱 테이블을 사용한 예제
int main()
{
    element tmp;
    int op;
    init_table(hash_table);
    while (1)
    {
        printf("원하는 연산을 입력하시오(0=입력, 1=탐색, 2=삭제, 3=종료)=");
        scanf("%d", &op);
        if (op == 3)
            break;
        printf("키를 입력하시오=");
        scanf("%s", &tmp.key);
        if (op == 0)
            hash_lp_add(tmp, hash_table);
        else if (op == 1)
            hash_lp_search(tmp, hash_table);
        else if (op == 2)
            hash_lp_delete(tmp, hash_table);
        hash_lp_print(hash_table);
    }

    return 0;
}
