#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_CHAR 10
#define TABLE_SIZE 13
#define IS_FULL(ptr) (!(ptr))
typedef struct
{
    char key[MAX_CHAR];
    /* other fields */
} element;
typedef struct list_node *list_ptr;
typedef struct list_node
{
    element item;
    list_ptr link;
} list_node;

list_ptr hash_table[TABLE_SIZE];

int transform(char *key)
{
    int number = 0;
    while (*key)
        number += *key++;
    return number;
}

int hash(char *key)
{
    return (transform(key) % TABLE_SIZE);
}

void chain_insert(element item, list_ptr ht[])
{

    int hash_value = hash(item.key);
    list_ptr ptr, trail = NULL;
    list_ptr lead = ht[hash_value];
    // trail points to the last node if any after for loop
    for (; lead; trail = lead, lead = lead->link)
    {
        if (!strcmp(lead->item.key, item.key))
        {
            fprintf(stderr, "the key is in the table\n");
            exit(1);
        }
    }
    ptr = (list_ptr)malloc(sizeof(list_node));
    if (IS_FULL(ptr))
    {
        fprintf(stderr, "the memory is full\n");
        exit(1);
    }

    ptr->item = item;
    ptr->link = NULL;
    if (trail)
        trail->link = ptr;
    else
        ht[hash_value] = ptr;
}

void hash_chain_delete(element item, list_ptr ht[])
{
    list_ptr temp;
    int hash_value = hash(item.key);
    temp = ht[hash_value];
    ht[hash_value] = ht[hash_value]->link;
    free(temp);
}

void PrintHash(list_ptr ht[])
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("[%d]: ", i);
        for (; ht[i]; ht[i] = ht[i]->link)
        {
            printf("%s  ", ht[i]->item.key);
        }
        printf("\n");
    }
}

int main()
{
    element tmp;
    int op;
    while (1)
    {
        printf("원하는 연산을 입력하시오(0=입력, 1=삭제, 2=종료)=");
        scanf("%d", &op);
        if (op == 2)
            break;
        printf("키를 입력하시오=");
        scanf("%s", &tmp.key);
        if (op == 0)
            chain_insert(tmp, hash_table);
        else if (op == 1)
            hash_chain_delete(tmp, hash_table);
        // hash_lp_print(h);

        PrintHash(hash_table);
    }

    return 0;
}