#include <stdio.h>
#include <stdlib.h>
#define N 5
void enqueue(int x);
void dequeue();
void frontfunc();
void isfull();
void isempty();
int queue[N];
int front = -1, rear = -1;
void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("queue is overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue overflow\n");
    }
    else if (front == 0 && rear == 0)
    {
        front = rear = -1;
    }
    else
    {
        printf("%d is deleted\n", queue[front]);
        front++;
    }
}
void frontfunc()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is underflow\n");
    }
    else
    {
        printf("%d is the front elements\n", queue[front]);
    }
}
void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("queue overflow");
    }
    else
    {
        for (i = front; i < rear + 1; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}
void isfull()
{
    if (rear == N - 1)
    {
        printf("queue is full\n");
    }
    else
    {
        printf("queue is not full\n");
    }
}
void isempty()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("queue is not empty\n");
    }
}
int main()
{
    enqueue(5);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    frontfunc();
    isfull();
    isempty();
    return 0;
}