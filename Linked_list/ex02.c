#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_node *list_ptr;

typedef struct list_node
{
	char data[5];
	list_ptr link;
} list_node;

list_ptr ptr = NULL;

void insert(list_ptr *pptr, list_ptr node, char *item)
{
	list_ptr temp;
	temp = (list_ptr)malloc(sizeof(struct list_node));
	if (temp == NULL)
	{
		fprintf(stderr, "The momory is full\n");
		exit(1);
	}
	strcpy(temp->data, item);
	temp->link = NULL;

	if (*pptr)
	{
		if (node)
		{
			temp->link = node->link;
			node->link = temp;
		}
		else
		{
			temp->link = *pptr;
			*pptr = temp;
		}
	}
	else
	{
		*pptr = temp;
	}
}

void delete (list_ptr *pptr, list_ptr trail, list_ptr node)
{
	if (trail)
		trail->link = node->link;
	else
		*pptr = (*pptr)->link;
	free(node);
}

void print_list(list_ptr listptr)
{
	printf("---리스트---\n");
	for (; listptr; listptr = listptr->link)
		printf("%4s\n", listptr->data);
	printf("\n");
}

int main(void)
{
	list_ptr node;
	node = (list_ptr)malloc(sizeof(struct list_node));
	int insert_num = 0;
	int delete_num = 0;
	int num;
	char a[5];
	printf("데이터를 입력: ");
	scanf("%s", a);

	insert(&ptr, node, a);
	print_list(ptr);

	while (1)
	{
		printf("1.삽입, 2.삭제, 3.종료\n");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("몇번째 노드에 추가시킬껀가요?: ");
			scanf("%d", &insert_num);
			printf("데이터를 입력: ");
			scanf("%s", a);
			insert(&ptr, node, a);
			print_list(ptr);
			break;

		case 2:
			scanf("몇번째 노드를 삭제하실껀가요?: %d", &delete_num);
			//				delete(ptr, node[delete_num -1] ,node[delete_num]);
			print_list(ptr);
			break;

		case 3:
			printf("종료합니다..\n");
			exit(1);

		defualt:
			printf("잘못입력했습니다.\n");
			break;
		}
	}

	return 0;
}
