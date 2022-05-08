#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int key;          // key ��
    struct TreeNode *left;  // left child
    struct TreeNode *right; // right child
} TreeNode;

TreeNode *search(TreeNode *root, int key)
{
    if (root == NULL)
    { // ���� ã�� ���� ���
        printf("Error : ���� ã�� �� �����ϴ�\n");
        return root;
    }

    if (key == root->key)
    { // ���� ã��
        return root;
    }
    else if (key < root->key)
    { // ���� ����Ʈ�� Ž��
        search(root->left, key);
    }
    else if (key > root->key)
    { // ������ ����Ʈ�� Ž��
        search(root->right, key);
    }
}

TreeNode *insert(TreeNode *root, int key)
{
    TreeNode *ptr;                                            // Ž���� ������ ������
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode)); // newNode ����
    newNode->key = key;
    newNode->left = newNode->right = NULL;

    if (root == NULL)
    { // Ʈ���� ��� ���� ���
        root = newNode;
        return root;
    }

    ptr = root; // root ������ Ž�� ����

    while (ptr)
    {
        if (key == ptr->key)
        { // �ߺ���
            printf("Error : �ߺ����� ������ �ʽ��ϴ�!\n");
            return root;
        }
        else if (key < ptr->key)
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

TreeNode *delete_node(TreeNode *root, int key)
{
    TreeNode *del = NULL;         // ������ ���
    TreeNode *parent = NULL;      // ������ ����� �θ� ���
    TreeNode *successor = NULL;   // ������ ����� ���� ����Ʈ������ ���� ū ���
    TreeNode *predecessor = NULL; // successor�� �θ���
    TreeNode *child = NULL;       // ������ ����� �ڽ� ���

    del = root;
    while (del != NULL)
    { // ������ ��� Ž��
        if (key == del->key)
        {
            break;
        }
        parent = del;
        if (key < del->key)
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
        printf("Error : �������� �ʴ� Ű\n");
        return root;
    }

    if (del->left == NULL && del->right == NULL)
    { // ������ ����� �ڽĳ�尡 ���� ���
        if (parent != NULL)
        { // �θ��尡 �ִ� ���
            if (parent->left == del)
            { // �θ����� ���ʳ�尡 ������ ����� ��
                parent->left = NULL;
            }
            else
            { // ������ �� ��
                parent->right = NULL;
            }
        }
        else
        { // �θ��尡 ���� ��� = root ���
            root = NULL;
        }
    }
    else if (del->left != NULL && del->right != NULL)
    { // ������ ����� �ڽ� ��尡 2���� ���
        predecessor = del;
        successor = del->left;

        while (successor->right != NULL)
        { // ���� ����Ʈ������ ���� ū �� ã��
            predecessor = successor;
            successor = successor->right;
        }

        predecessor->right = successor->left; // successor�� �ڽ� ��� ��ġ ����
        successor->left = del->left;          // successor�� ������ ����� ��ġ�� �ű� �Ͱ� ����
        successor->right = del->right;

        if (parent != NULL)
        { // ������ ����� �θ��尡 ���� ��
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
    { //     ������ ����� �ڽ� ��尡 1���� ���
        if (del->left != NULL)
        { // ���� ���
            child = del->left;
        }
        else
        { // ������ ���
            child = del->right;
        }

        if (parent != NULL)
        { // �θ��尡 �ִ� ���
            if (parent->left == del)
            { // �θ����� ���� ���� ������ ����� �ڽĳ�� ����
                parent->left = child;
            }
            else
            { // �θ����� ������ ���� ������ ����� �ڽĳ�� ����
                parent->right = child;
            }
        }
        else
        {
            root = child;
        }
    }

    free(del); // �޸�����
    return root;
}

void print_tree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%d\n", root->key);
    print_tree(root->right);
}

int main()
{
    TreeNode *root = NULL;
    TreeNode *ptr = NULL;
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 10);

    print_tree(root);
    printf("\n");

    ptr = search(root, 7);
    printf("%d\n", ptr->key);

    root = delete_node(root, 7);
    ptr = search(root, 7);

    return 0;
}
