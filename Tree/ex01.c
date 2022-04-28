#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *root;
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->right = root->left = NULL;
        root->data = data;
        return root;
    }
    else
    {
        if (data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
}
node *fMin(node *root)
{
    node *min = root;
    while (min->left != NULL)
        min = min->left;
    return min;
}
node *delete (node *root, int data)
{
    node *tmproot = NULL;
    if (root == NULL)
        return NULL;
    if (data < root->data)
        root->left = delete (root->left, data);
    else if (data > root->data)
        root->right = delete (root->right, data);
    else
    {
        if (root->left != NULL && root->right != NULL)
        {
            tmproot = fMin(root->right);
            root->data = tmproot->data;
            root->right = delete (root->right, tmproot->data);
        }
        else
        {
            tmproot = (root->left == NULL) ? root->right : root->left;
            free(root);
            return tmproot;
        }
    }
    return root;
}
void print(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    print(root->left);
    print(root->right);
} //전위 순회
void preorderPrint(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    print(root->left);
    print(root->right);
} //중위 순회
void inorderPrint(node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
} //후위 순회
void postorderPrint(node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    print(root->right);
    printf("%d ", root->data);
}
int main()
{
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 5);
    printf("----insert----\n");
    printf("preorder : ");
    preorderPrint(root);
    printf("\n");
    printf("inorder : ");
    inorderPrint(root);
    printf("\n");
    printf("postorder : ");
    postorderPrint(root);
    printf("\n\n");
    printf("preorder : ");
    preorderPrint(root);
    printf("\n");

    root = delete (root, 1);
    root = delete (root, 2);
    root = delete (root, 3);
    root = delete (root, 4);
    root = delete (root, 5);
    printf("\n-----delete-----\n");
    printf("preorder : ");
    preorderPrint(root);
    printf("\n");
    printf("inorder : ");
    inorderPrint(root);
    printf("\n");
    printf("postorder : ");
    postorderPrint(root);
    printf("\n\n");

    return 0;
    // printf("delete : 9\n");
    // root = delete (root, 9);
    // preorderPrint(root);
    // printf("\n");
    // root = insert(root, 9);
    // printf("delete : 1\n");
    // root = delete (root, 1);
    // preorderPrint(root);
    // printf("\n");
    // root = insert(root, 1);
    // printf("delete : 5\n");
    // root = delete (root, 5);
    // preorderPrint(root);
    // printf("\n");
}
