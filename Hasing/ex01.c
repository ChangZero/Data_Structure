#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 10
#define TABLE_SIZE 13
typedef struct
{
    char key[MAX_CHAR];
} element;

element hash_table[TABLE_SIZE];

void init_table(element ht[])
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        ht[i].key[0] = NULL;
    }
}

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

void linear_insert(element item, element ht[])
{
    int i, hash_value;
    hash_value = hash(item.key);
    i = hash_value;
    while (strlen(ht[i].key))
    {
        if (!strcmp(ht[i].key, item.key))
        {
            fprintf(stderr, "duplicate entry\n");
            exit(1);
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value)
        {
            fprintf(stderr, "the table is full\n");
            exit(1);
        }
    }
    ht[i] = item;
}

void linear_delete(element item, element ht[])
{
    int i;
    i = hash(item.key);
    for (int j = 0; j < TABLE_SIZE; j++)
    {
        ht[i].key[j] = NULL;
    }
}

void linear_print(element ht[])
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        printf("[%d]	%s\n", i, ht[i].key);
}

int main()
{
    int i, cmd;
    char st[MAX_CHAR];
    element item;
    init_table(hash_table);
    while(1){
        printf("Please enter cmd(0=insert, 1=delete, 2=exit)=");
        scanf("%d", &cmd);
        switch (cmd)
        {
        case 0:
            printf("Please insert key=");
            scanf("%s", item.key);
            strcpy(item.key, "ulsan");
            linear_insert(item, hash_table);
            linear_print(hash_table);
            break;
        
        case 1:
            printf("Please insert key=");
            scanf("%s", st);
            strcpy(item.key, "ulsan");
            linear_delete(item, hash_table);
            linear_print(hash_table);
            break;
        
        case 2:
            exit(1);
            break;
        
        default:
            printf("Wrong cmd\n");
            break;
        }
        
    }
    

    return 0;
}
