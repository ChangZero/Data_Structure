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


int main()
{
    int i;
    element item;
    strcpy(item.key,"ulsan");
    linear_insert(item, hash_table);

    for (i = 0; i < TABLE_SIZE;i++){
        printf("%s\n", hash_table[i].key);
    }
    return 0;
}
