#include <stdio.h>
#include <stdlib.h>
void enqueue();
void dequeue();
void display();
void peek();
void isempty();
struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
struct node *newnode, *temp;
void enqueue(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if (rear == 0 && front == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("\n inserted :%d", x);
}
void dequeue()
{
    temp = front;
    if (rear == 0 && front == 0)
    {
        printf("no elements");
    }
    else
    {
        front = front->next;
        printf("\n deleted:%d", temp->data);
        free(temp);
    }
}
void display()
{
    if (rear == 0 && front == 0)
    {
        printf("no elements");
    }
    else
    {
        temp = front;
        while (temp->next != 0)
        {
            printf("\n display:%d", temp->data);
            temp = temp->next;
        }
        printf("\n display:%d", temp->data);
    }
}
void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("\nqueue is empty");
    }
    else
    {
        printf("\n top element is : %d", temp->data);
    }
}
void isempty()
{
    if (front == 0 && rear == 0)
    {
        printf("\nqueue is empty");
    }
    else
    {
        printf("\n queue is not empty");
    }
}
void main()
{
    enqueue(2);
    enqueue(7);
    enqueue(8);
    dequeue();
    display();
    peek();
    isempty();
}