#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node TreeNode;
typedef struct node
{
	int comp_num;
	char comp_name[20];
	int stock;
	int recall;
	TreeNode *left;
	TreeNode *right;
};
TreeNode *root = NULL;

int err_num(int comp_num)
{
	if (comp_num < 100000)
	{
		printf("%6d    ������Ʈ ��ȣ ����\n", comp_num);
		return 1;
	}

	if (comp_num > 999999)
	{
		printf("%6d    ������Ʈ ��ȣ ����\n", comp_num);
		return 1;
	}
	return 0;
}

void add_comp(int comp_num, int add_num)
{
	TreeNode *temp = root;
	if (err_num(comp_num) == 1)
		return;

	while (1)
	{
		if (temp->comp_num > comp_num)
		{ // tmp�� ��ǰ��ȣ�� ��ǰ��ȣ���� Ŭ�� ���� ��忡 ��������
			if (temp->left)
			{
				temp = temp->left;
				continue;
			}
			else
			{
				printf("%6d    �׷��� ������Ʈ ����\n", comp_num);
				break;
			}
		}
		else if (temp->comp_num < comp_num)
		{ // tmp�� ��ǰ��ȣ�� ��ǰ��ȣ���� ������ ������ ��忡 ��������
			if (temp->right)
			{
				temp = temp->right;
				continue;
			}
			else
			{
				printf("%6d    �׷��� ������Ʈ ����\n", comp_num);
				break;
			}
		}
		else
		{ //��� �߰�
			temp->stock += add_num;
			break;
		}
	}
}
void remove_comp(int comp_num, int remove_num)
{
	TreeNode *temp = root;

	if (err_num(comp_num) == 1)
		return;

	while (1)
	{
		if (temp->comp_num > comp_num)
		{ // tmp�� ��ǰ ��ȣ�� ��ǰ ��ȣ���� Ŭ�� ���ʿ� ����
			if (temp->left)
			{
				temp = temp->left;
				continue;
			}
			else
			{
				printf("%6d    �׷��� ������Ʈ ����\n", comp_num);
				break;
			}
		}
		else if (temp->comp_num < comp_num)
		{ // tmp�� ��ǰ ��ȣ�� ��ǰ ��ȣ���� ������ �����ʿ� ����
			if (temp->right)
			{
				temp = temp->right;
				continue;
			}
			else
			{
				printf("%6d    �׷��� ������Ʈ ����\n", comp_num);
				break;
			}
		}
		else
		{ //��� ����
			if (temp->stock >= remove_num)
				temp->stock -= remove_num;
			else //������ ���
				printf("%6d    ����� ������� ����\n", comp_num);
			break;
		}
	}
}

TreeNode *insert(TreeNode *root, int comp_num, char comp_name[], int stock, int recall)
{
	TreeNode *ptr;											  // Ž���� ������ ������
	TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode)); // newNode ����
	newNode->comp_num = comp_num;
	newNode->stock = stock;
	newNode->recall = recall;
	strcpy(newNode->comp_name, comp_name);
	newNode->left = newNode->right = NULL;

	if (root == NULL)
	{ // Ʈ���� ��� ���� ���
		root = newNode;
		return root;
	}

	ptr = root; // root ������ Ž�� ����

	while (ptr)
	{
		if (comp_num == ptr->comp_num)
		{ // �ߺ���
			printf("%6d	������Ʈ �ߺ�!\n");
			return root;
		}
		else if (comp_num < ptr->comp_num)
		{ // ���� ����Ʈ��
			if (ptr->left == NULL)
			{ // ����ִٸ� �߰�
				ptr->left = newNode;
				return root;
			}
			else
			{ // ������� �ʴٸ� �ٽ� Ž�� ����
				ptr = ptr->left;
			}
		}
		else
		{ // key > ptr->key ������ ����Ʈ��
			if (ptr->right == NULL)
			{ // ����ִٸ� �߰�
				ptr->right = newNode;
				return root;
			}
			else
			{ // ������� �ʴٸ� �ٽ� Ž�� ����
				ptr = ptr->right;
			}
		}
	}
}

void delete (int comp_num)
{ //�ڽ��� ���� �� �ϳ� ���� �� �ΰ� ���� ��
	TreeNode *temp = root;
	TreeNode *ptmp = NULL;

	if (err_num(comp_num) == 1)
		return;

	while (1)
	{
		if (temp->comp_num > comp_num)
		{
			if (temp->left)
			{
				ptmp = temp;
				temp = temp->left;
				continue;
			}
			else
			{
				printf("%6d    �׷��� ������Ʈ ����\n", comp_num);
				break;
			}
		}
		else if (temp->comp_num < comp_num)
		{
			if (temp->right)
			{
				ptmp = temp;
				temp = temp->right;
				continue;
			}
			else
			{
				printf("%6d    �׷��� ������Ʈ ����\n", comp_num);
				break;
			}
		}
		else
		{
			if (ptmp)
			{
				if (ptmp->comp_num > temp->comp_num)
				{
					if (temp->left)
					{
						if (temp->right)
						{
							temp = temp->right;
							while (temp->left)
								temp = temp->left;
							temp->left = ptmp->left->left;
							temp = ptmp->left;
							ptmp->left = temp->right;
							free(temp);
							break;
						}
						else
						{
							ptmp->left = temp->left;
							free(temp);
							break;
						}
					}
					else
					{
						if (temp->right)
						{
							ptmp->left = temp->right;
							free(temp);
							break;
						}
						else
						{
							ptmp->left = NULL;
							free(temp);
							break;
						}
					}
				}
				else if (ptmp->comp_num < temp->comp_num)
				{
					if (temp->left)
					{
						if (temp->right)
						{
							temp = temp->right;
							while (temp->left)
								temp = temp->left;
							temp->left = ptmp->right->left;
							temp = ptmp->right;
							ptmp->right = temp->right;
							free(temp);
							break;
						}
						else
						{
							ptmp->right = temp->right;
							free(temp);
							break;
						}
					}
					else
					{
						if (temp->right)
						{
							ptmp->right = temp->right;
							free(temp);
							break;
						}
						else
						{
							ptmp->right = NULL;
							free(temp);
							break;
						}
					}
				}
			}
			else
			{
				if (temp->left)
				{
					if (temp->right)
					{
						temp = temp->right;
						while (temp->left)
							temp = temp->left;
						temp->left = root->left;
						temp = root;
						root = temp->right;
						free(temp);
						break;
					}
					else
					{
						temp = root;
						root = temp->left;
						free(temp);
						break;
					}
				}
				else
				{
					if (temp->right)
					{
						temp = root;
						root = temp->right;
						free(temp);
						break;
					}
					else
					{
						root = NULL;
						free(temp);
						break;
					}
				}
			}
		}
	}
}

void print_tree(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	print_tree(root->left);
	if (root->stock < root->recall)
		printf("%d \t\t %s \t\t %d \t\t %d	*���ֹ� �ʿ�*\n", root->comp_num, root->comp_name, root->stock, root->recall);
	else
		printf("%d \t\t %s \t\t %d \t\t %d\n", root->comp_num, root->comp_name, root->stock, root->recall);
	print_tree(root->right);
}

int main()
{
	char cmd;
	int comp_num;
	char comp_name[20];
	int stock;
	int recall;
	int add_num;
	int remove_num;

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
		fscanf(fp, "%c", &cmd);
		switch (cmd)
		{
		case 'N':
			fscanf(fp, "%d", &comp_num);
			fgets(comp_name, 20, fp);
			fscanf(fp, "%d %d", &stock, &recall);
			if (err_num(comp_num) == 0)
			{
				root = insert(root, comp_num, comp_name, stock, recall);
			}
			break;

		case 'D':
			fscanf(fp, "%d", &comp_num);
			delete (comp_num);
			break;

		case 'A':
			fscanf(fp, "%d %d", &comp_num, &add_num);
			add_comp(comp_num, add_num);
			break;

		case 'R':
			fscanf(fp, "%d %d", &comp_num, &remove_num);
			remove_comp(comp_num, remove_num);
			break;

		case 'P':
			printf("������Ʈ ��ȣ\t\t����\t\t�������\t���ֹ�����\n");
			printf("----------------------------------------------------------------------\n");
			print_tree(root);
			printf("----------------------------------------------------------------------\n");
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
