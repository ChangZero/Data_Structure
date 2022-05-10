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
TreeNode *ptr = NULL;

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
			printf("Error : 중복값은 허용되지 않습니다!\n");
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

TreeNode *delete_node(TreeNode *root, int comp_num)
{
	TreeNode *del = NULL;		  // 삭제할 노드
	TreeNode *parent = NULL;	  // 삭제할 노드의 부모 노드
	TreeNode *successor = NULL;	  // 삭제할 노드의 왼쪽 서브트리에서 가장 큰 노드
	TreeNode *predecessor = NULL; // successor의 부모노드
	TreeNode *child = NULL;		  // 삭제할 노드의 자식 노드

	del = root;
	while (del != NULL)
	{ // 삭제할 노드 탐색
		if (comp_num == del->comp_num)
		{
			break;
		}
		parent = del;
		if (comp_num < del->comp_num)
		{
			del = del->left;
		}
		else
		{
			del = del->right;
		}
	}

	if (del == NULL)
	{
		printf("Error : 존재하지 않는 키\n");
		return root;
	}

	if (del->left == NULL && del->right == NULL)
	{ // 삭제할 노드의 자식노드가 없는 경우
		if (parent != NULL)
		{ // 부모노드가 있는 경우
			if (parent->left == del)
			{ // 부모노드의 왼쪽노드가 삭제할 노드일 때
				parent->left = NULL;
			}
			else
			{ // 오른쪽 일 때
				parent->right = NULL;
			}
		}
		else
		{ // 부모노드가 없는 경우 = root 노드
			root = NULL;
		}
	}
	else if (del->left != NULL && del->right != NULL)
	{ // 삭제할 노드의 자식 노드가 2개인 경우
		predecessor = del;
		successor = del->left;

		while (successor->right != NULL)
		{ // 왼쪽 서브트리에서 가장 큰 값 찾기
			predecessor = successor;
			successor = successor->right;
		}

		predecessor->right = successor->left; // successor의 자식 노드 위치 변경
		successor->left = del->left;		  // successor를 삭제할 노드의 위치로 옮긴 것과 같음
		successor->right = del->right;

		if (parent != NULL)
		{ // 삭제할 노드의 부모노드가 있을 때
			if (parent->left == del)
			{
				parent->left = successor;
			}
			else
			{
				parent->right = successor;
			}
		}
		else
		{
			root = successor;
		}
	}
	else
	{ //     삭제할 노드의 자식 노드가 1개인 경우
		if (del->left != NULL)
		{ // 왼쪽 노드
			child = del->left;
		}
		else
		{ // 오른쪽 노드
			child = del->right;
		}

		if (parent != NULL)
		{ // 부모노드가 있는 경우
			if (parent->left == del)
			{ // 부모노드의 왼쪽 노드로 삭제할 노드의 자식노드 연결
				parent->left = child;
			}
			else
			{ // 부모노드의 오른쪽 노드로 삭제할 노드의 자식노드 연결
				parent->right = child;
			}
		}
		else
		{
			root = child;
		}
	}

	free(del); // 메모리해제
	return root;
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
			printf("%d %s %d %d\n", comp_num, comp_name, stock, recall);
			root = insert(root, comp_num, comp_name, stock, recall);
			break;

		case 'D':
			fscanf(fp, "%d", &comp_num);
			printf("%d\n", comp_num);
			root = delete_node(root, comp_num);
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
