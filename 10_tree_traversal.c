#include <stdio.h>
#include <stdlib.h>
struct node *create();
void postorder(struct node *root);
void preorder(struct node *root);
void inorder(struct node *root);
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int main()
{
    struct node *root;
    root = 0;
    root = create();
    printf("\n tree created");
    printf("\ncalling preorder ");
    preorder(root);
    printf("\ncalling postorder");
    postorder(root);
    printf("\n calling inorder");
    inorder(root);
}

struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the data");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    else
    {
        newnode->data = x;
    }
    printf("\n Enter the Left child of %d", x);
    newnode->left = create();
    printf("\n enter the Right child of %d", x);
    newnode->right = create();
    return newnode;
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->data);

    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}