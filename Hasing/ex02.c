#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 10
#define TABLE_SIZE 13
#define IS_FULL(ptr) (!(ptr))

#define MAX_CHAR 10
#define TABLE_SIZE 13

typedef struct
{
    char key[MAX_CHAR];
    /* other fields */
} element;

typedef struct list *list_ptr;
typedef struct list
{
    element item;
    list_ptr link;
} hash_table[TABLE_SIZE];
hash_table hash;
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

        if (!strcmp(lead->item.key, item.key))
        {

            fprintf(stderr, "the key is in the table\n");
            exit(1);
        }

    ptr = (list_ptr)malloc(sizeof(list_ptr));
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


int main()
{
    int i;
    element item;
    strcpy(item.key, "ulsan");
    chain_insert(item, hash);

    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("%s\n", hash.key);
    }
    return 0;
}