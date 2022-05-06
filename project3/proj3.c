#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char cmd;
	int comp_num;
	char comp_naum[20];
	int stock;
	int recall;
	int add_num;
	int remove_num;

	char str[100];

	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL)
	{
		printf("input file open error\n");
		exit(0);
	}
	else
		printf("input file open success\n");

	while (1)
	{
		fgets(str, 50, fp);
		char *ptr = strtok(str, " ");
		while (ptr != NULL)
		{
			switch (ptr)
			{
			case 'N':
			}

			ptr = strtok(NULL, " ");
		}
	}

	return 0;
}
