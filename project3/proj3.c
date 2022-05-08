#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node *tree_ptr;
typedef struct node{
	int comp_num;
	char comp_name[20];
	int stock;
	int recall;
	tree_ptr left;
	tree_ptr right;
};

tree_ptr ptr;

int main()
{
	char cmd;
	int comp_num;
	char comp_name[20];
	int stock;
	int recall;
	int add_num;
	int remove_num;

	char str[100];

	FILE *fp = fopen("C:\\Coding\\Cource\\Data Structure\\project3\\input.txt", "r");
	if (fp == NULL)
	{
		printf("input file open error\n");
		exit(0);
	}
	else
		printf("input file open success\n");

	while (1)
	{
		fscanf(fp, "%c", &cmd);
		switch (cmd)
		{
		case 'N':
			fscanf(fp, "%d", &comp_num);
			fgets(comp_name, 20, fp);
			fscanf(fp, "%d %d", &stock, &recall);
			printf("%d %s %d %d\n", comp_num, comp_name, stock, recall);
			break;
		case 'D':
			fgets(comp_name, 20, fp);
			printf("%s", comp_name);
			break;
		case 'A':
			fscanf(fp, "%d %d", &comp_num, &add_num);
			printf("%d %d\n", comp_num, add_num);
			break;
		case 'R':
			fscanf(fp, "%d %d", &comp_num, &remove_num);
			printf("%d %d\n", comp_num, remove_num);
			break;
		case 'P':
			break;
		case 'X':
			exit(0);
			break;
		default:
			break;
		}
	}
	fclose(fp);
	return 0;
}
