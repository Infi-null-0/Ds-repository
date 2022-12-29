#include <stdio.h>
#include <stdlib.h>
int stack[10], top = -1, temp;
void push()
{
    int element;
    printf("-----PUSH--------\n");
    if (top == 9)
    {
        printf("Stack is full !\n");
    }
    else
    {
        printf("Enter the element : ");
        scanf("%d", &element);
        top++;
        stack[top] = element;
        printf("Element %d pushed successfully !\n", stack[top]);
    }
}
void pop()
{
    printf("-----POP---------\n");
    if (top == -1)
    {
        printf("Stack is empty !\n");
    }
    else
    {
        stack[top] = 0;
        top--;
        printf("pop successfull !\n");
    }
}
void peak()
{
    printf("-----PEAK--------\n");
    if (top != -1)
    {
        printf("The peak element id : %d\n", stack[top]);
    }
    else
    {
        printf("The stack is empty !\n");
    }
}
void display()
{
    printf("-----DISPLAY-----\n");
    if (top != -1)
    {
        printf("The stack is ::");
        temp = top;
        while (temp >= 0)
        {
            printf("\n%d", stack[temp]);
            temp--;
        }
        printf("\n");
    }
    else
    {
        printf("The stack is empty !\n");
    }
}
void isfull()
{
    printf("-----ISFULL------\n");
    if (top == 9)
    {
        printf("The stack is full!\n");
    }
    else
    {
        printf("The stack is not full !\n");
    }
}
void isempty()
{
    printf("-----ISEMPTY-----\n");
    if (top == -1)
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
    printf("-----STACK - ARRAY-----\n\n1-PUSH\n2-POP\n3-PEAK\n4-DISPLAY\n5-ISEMPTY\n6-ISFULL\n7-EXIT\n");
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
            isfull();
            break;
        case 7:
            printf("-----EXIT-------");
            exit(0);
        default:
            printf("invalid choice !\n");
            break;
        }
    }
    return 0;
}