#include <stdio.h>
#include <stdlib.h>
struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};
struct bst *temp, *newn, *root;
int val;
struct bst *initialise(int val)
{
    newn = (struct bst *)malloc(sizeof(struct bst));
    newn->data = val;
    newn->left = newn->right = NULL;
    return newn;
}
struct bst *insertion(struct bst *root, int val)
{
    if (root == NULL)
        return initialise(val);
    if (val <= root->data)
        root->left = insertion(root->left, val);
    if (val >= root->data)
        root->right = insertion(root->right, val);
    return root;
}
void inorder(struct bst *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("\t-->%d", root->data);
        inorder(root->right);
    }
}
struct bst *search(struct bst *root, int item)
{
    if (root == NULL || root->data == item)
        return root;
    if (item <= root->data)
        search(root->left, item);
    if (item > root->data)
        search(root->right, item);
}
struct bst *minvalnode(struct bst *node)
{
    struct bst *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct bst *deletion(struct bst *root, int item)
{
    if (root == NULL)
        return root;
    if (item < root->data)
        root->left = deletion(root->left, item);
    else if (item > root->data)
        root->right = deletion(root->right, item);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = minvalnode(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
}
void main()
{
    int ch, x = 0, rooot = 0;
    printf("\nbinary search tree\n");
    while (1)
    {
        printf("\n1.insert\n2.search\n3.delete\n4.exit\nchoice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n------insertion------\n");
            printf("enter data:");
            scanf("%d", &val);
            root = insertion(root, val);
            printf("\ninorder list:\n");
            inorder(root);
            break;
        case 2:
            printf("\n------search------\n");
            printf("enter data:");
            scanf("%d", &val);
            temp = search(root, val);
            if (temp == NULL)
            {
                printf("\ndata not found");
            }
            else
            {
                printf("\ndata found");
            }
            break;
        case 3:
            printf("\n------deletion------\n");
            printf("enter data:");
            scanf("%d", &val);
            root = deletion(root, val);
            printf("\ninorder list:\n");
            inorder(root);
            break;
        case 4:
            exit(EXIT_SUCCESS);
        default:
            printf("\ninvalid choce");
            break;
        }
        printf("\n");
        printf("-----------------------------------------------------");
    }
}