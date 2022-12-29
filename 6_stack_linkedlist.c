#include <stdio.h>
#include <stdlib.h>
int choice = 1;
struct node
{
    int data;
    struct node *next;
}
    *top = 0,
    *newnode,
    *temp;
void push()
{
    printf("-----PUSH--------\n");
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element : ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->next = top;
    top = newnode;
    printf("Element %d pushed successfully !\n", top->data);
}
void pop()
{
    printf("-----POP---------\n");
    if (top != NULL)
    {
        temp = top;
        top = top->next;
        free(temp);
        printf("pop successfull !\n");
    }
    else
    {
        printf("Stack is empty !\n");
    }
}
void peak()
{
    printf("-----PEAK--------\n");
    if (top != NULL)
    {
        printf("The peak element id : %d\n", top->data);
    }
    else
    {
        printf("The stack is empty !\n");
    }
}
void display()
{
    printf("-----DISPLAY-----\n");
    if (top != NULL)
    {
        printf("The stack is ::");
        temp = top;
        while (temp != 0)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("The stack is empty !\n");
    }
}
void isempty()
{
    printf("-----ISEMPTY-----\n");
    if (top == NULL)
    {
        printf("The stack is empty !\n");
    }
    else
    {
        printf("The stack is not empty !\n");
    }
}
int main()
{
    int option;
    printf("-----STACK - LINKED LIST-----\n\n1-PUSH\n2-POP\n3-PEAK\n4-DISPLAY\n5-ISEMPTY\n6-EXIT\n");
    while (1)
    {
        printf("\nEnter option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peak();
            break;
        case 4:
            display();
            break;
        case 5:
            isempty();
            break;
        case 6:
            printf("-----EXIT-------");
            exit(0);
        default:
            printf("invalid choice !\n");
            break;
        }
    }
    return 0;
}