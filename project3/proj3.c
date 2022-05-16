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

void add_comp(int comp_num, int add_num)
{
	TreeNode *temp = root;
	if (err_num(comp_num) == 1)
		return;

	while (1)
	{
		if (temp->comp_num > comp_num)
		{ // tmp의 제품번호가 제품번호보다 클때 왼쪽 노드에 연결해줌
			if (temp->left)
			{
				temp = temp->left;
				continue;
			}
			else
			{
				printf("%6d    그러한 컴포넌트 없음\n", comp_num);
				break;
			}
		}
		else if (temp->comp_num < comp_num)
		{ // tmp의 제품번호가 제품번호보다 작을때 오른쪽 노드에 연결해줌
			if (temp->right)
			{
				temp = temp->right;
				continue;
			}
			else
			{
				printf("%6d    그러한 컴포넌트 없음\n", comp_num);
				break;
			}
		}
		else
		{ //재고량 추가
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
		{ // tmp의 제품 번호가 제품 번호보다 클때 왼쪽에 연결
			if (temp->left)
			{
				temp = temp->left;
				continue;
			}
			else
			{
				printf("%6d    그러한 컴포넌트 없음\n", comp_num);
				break;
			}
		}
		else if (temp->comp_num < comp_num)
		{ // tmp의 제품 번호가 제품 번호보다 작을때 오른쪽에 연결
			if (temp->right)
			{
				temp = temp->right;
				continue;
			}
			else
			{
				printf("%6d    그러한 컴포넌트 없음\n", comp_num);
				break;
			}
		}
		else
		{ //재고량 제거
			if (temp->stock >= remove_num)
				temp->stock -= remove_num;
			else //부족할 경우
				printf("%6d    재고량이 충분하지 않음\n", comp_num);
			break;
		}
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
				printf("%6d    그러한 컴포넌트 없음\n", comp_num);
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
				printf("%6d    그러한 컴포넌트 없음\n", comp_num);
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
		printf("%d \t\t %s \t\t %d \t\t %d	*재주문 필요*\n", root->comp_num, root->comp_name, root->stock, root->recall);
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
			printf("컴포넌트 번호\t\t설명\t\t현재재고량\t재주문수준\n");
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
