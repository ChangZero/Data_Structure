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
		printf("%6d    컴포넌트 번호 에러\n", comp_num);
		return 1;
	}

	if (comp_num > 999999)
	{
		printf("%6d    컴포넌트 번호 에러\n", comp_num);
		return 1;
	}
	return 0;
}

TreeNode *search(TreeNode *root, int comp_num)
{
	if (root == NULL)
	{ // 값을 찾지 못한 경우
		printf("Error : 값을 찾을 수 없습니다\n");
		return root;
	}

	if (comp_num == root->comp_num)
	{ // 값을 찾음
		return root;
	}
	else if (comp_num < root->comp_num)
	{ // 왼쪽 서브트리 탐색
		search(root->left, comp_num);
	}
	else if (comp_num > root->comp_num)
	{ // 오른쪽 서브트리 탐색
		search(root->right, comp_num);
	}
}

TreeNode *add(TreeNode *root, int comp_num, int add_num)
{
	TreeNode *ptr = root;
	if (root == NULL)
	{ // 값을 찾지 못한 경우
		printf("Error : 값을 찾을 수 없습니다\n");
		return root;
	}

	if (comp_num == ptr->comp_num)
	{ // 값을 찾음
		ptr->stock += add_num;
		return root;
	}
	else if (comp_num < ptr->comp_num)
	{ // 왼쪽 서브트리 탐색
		search(ptr->left, comp_num);
	}
	else if (comp_num > ptr->comp_num)
	{ // 오른쪽 서브트리 탐색
		search(ptr->right, comp_num);
	}
}

TreeNode *remo(TreeNode *root, int comp_num, int remove_num)
{
	TreeNode *ptr = root;
	if (root == NULL)
	{ // 값을 찾지 못한 경우
		printf("Error : 값을 찾을 수 없습니다\n");
		return root;
	}

	if (comp_num == ptr->comp_num)
	{ // 값을 찾음
		if (ptr->stock < remove_num)
			printf("재고량이 충분하지 않음\n");
		else
			ptr->stock -= remove_num;
		return root;
	}
	else if (comp_num < ptr->comp_num)
	{ // 왼쪽 서브트리 탐색
		search(ptr->left, comp_num);
	}
	else if (comp_num > ptr->comp_num)
	{ // 오른쪽 서브트리 탐색
		search(ptr->right, comp_num);
	}
}

TreeNode *insert(TreeNode *root, int comp_num, char comp_name[], int stock, int recall)
{
	TreeNode *ptr;											  // 탐색을 진행할 포인터
	TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode)); // newNode 생성
	newNode->comp_num = comp_num;
	newNode->stock = stock;
	newNode->recall = recall;
	strcpy(newNode->comp_name, comp_name);
	newNode->left = newNode->right = NULL;

	if (root == NULL)
	{ // 트리가 비어 있을 경우
		root = newNode;
		return root;
	}

	ptr = root; // root 노드부터 탐색 진행

	while (ptr)
	{
		if (comp_num == ptr->comp_num)
		{ // 중복값
			printf("%6d	컴포넌트 중복!\n");
			return root;
		}
		else if (comp_num < ptr->comp_num)
		{ // 왼쪽 서브트리
			if (ptr->left == NULL)
			{ // 비어있다면 추가
				ptr->left = newNode;
				return root;
			}
			else
			{ // 비어있지 않다면 다시 탐색 진행
				ptr = ptr->left;
			}
		}
		else
		{ // key > ptr->key 오른쪽 서브트리
			if (ptr->right == NULL)
			{ // 비어있다면 추가
				ptr->right = newNode;
				return root;
			}
			else
			{ // 비어있지 않다면 다시 탐색 진행
				ptr = ptr->right;
			}
		}
	}
}

void delete (int comp_num)
{ //자식이 없을 때 하나 있을 때 두개 있을 때
	TreeNode *tmp = root;
	TreeNode *ptmp = NULL;

	if(err_num(comp_num)==1)
		return;

	while (1)
	{
		if (tmp->comp_num > comp_num)
		{
			if (tmp->left)
			{
				ptmp = tmp;
				tmp = tmp->left;
				continue;
			}
			else
			{
				printf("%6d    그러한 컴포넌트 없음\n", comp_num);
				break;
			}
		}
		else if (tmp->comp_num < comp_num)
		{
			if (tmp->right)
			{
				ptmp = tmp;
				tmp = tmp->right;
				continue;
			}
			else
			{
				printf("%6d    그러한 컴포넌트 없음\n", comp_num);
				break;
			}
		}
		else
		{
			if (ptmp)
			{
				if (ptmp->comp_num > tmp->comp_num)
				{
					if (tmp->left)
					{
						if (tmp->right)
						{
							tmp = tmp->right;
							while (tmp->left)
								tmp = tmp->left;
							tmp->left = ptmp->left->left;
							tmp = ptmp->left;
							ptmp->left = tmp->right;
							free(tmp);
							break;
						}
						else
						{
							ptmp->left = tmp->left;
							free(tmp);
							break;
						}
					}
					else
					{
						if (tmp->right)
						{
							ptmp->left = tmp->right;
							free(tmp);
							break;
						}
						else
						{
							ptmp->left = NULL;
							free(tmp);
							break;
						}
					}
				}
				else if (ptmp->comp_num < tmp->comp_num)
				{
					if (tmp->left)
					{
						if (tmp->right)
						{
							tmp = tmp->right;
							while (tmp->left)
								tmp = tmp->left;
							tmp->left = ptmp->right->left;
							tmp = ptmp->right;
							ptmp->right = tmp->right;
							free(tmp);
							break;
						}
						else
						{
							ptmp->right = tmp->right;
							free(tmp);
							break;
						}
					}
					else
					{
						if (tmp->right)
						{
							ptmp->right = tmp->right;
							free(tmp);
							break;
						}
						else
						{
							ptmp->right = NULL;
							free(tmp);
							break;
						}
					}
				}
			}
			else
			{
				if (tmp->left)
				{
					if (tmp->right)
					{
						tmp = tmp->right;
						while (tmp->left)
							tmp = tmp->left;
						tmp->left = root->left;
						tmp = root;
						root = tmp->right;
						free(tmp);
						break;
					}
					else
					{
						tmp = root;
						root = tmp->left;
						free(tmp);
						break;
					}
				}
				else
				{
					if (tmp->right)
					{
						tmp = root;
						root = tmp->right;
						free(tmp);
						break;
					}
					else
					{
						root = NULL;
						free(tmp);
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
	printf("%d \t %s \t %d \t %d\n", root->comp_num, root->comp_name, root->stock, root->recall);
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
			if (err_num(comp_num) == 0)
			{
				printf("%d %s %d %d\n", comp_num, comp_name, stock, recall);
				root = insert(root, comp_num, comp_name, stock, recall);
			}
			break;

		case 'D':
			fscanf(fp, "%d", &comp_num);
			printf("%d\n", comp_num);
			delete (comp_num);
			break;

		case 'A':
			fscanf(fp, "%d %d", &comp_num, &add_num);
			printf("%d %d\n", comp_num, add_num);
			root = add(root, comp_num, add_num);
			break;

		case 'R':
			fscanf(fp, "%d %d", &comp_num, &remove_num);
			printf("%d %d\n", comp_num, remove_num);
			root = remo(root, comp_num, remove_num);
			break;

		case 'P':
			print_tree(root);
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
