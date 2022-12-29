#include <stdio.h>
#include <stdlib.h>
int x, count = 0;
struct node
{
    int data;
    struct node *next;
    struct node *prevn;
} *newnode, *head, *temp, *tail;
int out()
{
    printf("\n Displaying list\n");
    temp = head;
    if (temp == 0)
    {
        printf("\n list is empty");
    }
    else
    {
        printf("\nAscending order:\t");
        while (temp->next != 0)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\t", temp->data);
        printf("\nDescending order:\t");
        temp = tail;
        while (temp->prevn != 0)
        {
            printf("%d\t", temp->data);
            temp = temp->prevn;
        }
        printf("%d", temp->data);
    }
}
int create()
{
    int c = 1;
    head = 0;
    while (c == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\n enter the data:");
        scanf("%d", &x);
        newnode->data = x;
        newnode->next = 0;
        newnode->prevn = 0;
        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prevn = tail;
            tail = newnode;
        }
        printf("\ncontinue press 1:");
        scanf("%d", &c);
        count++;
    }
    out();
}
int inst()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the data:");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = 0;
    newnode->next = head;
    newnode->prevn = 0;
    head->prevn = newnode;
    head = newnode;
    count++;
}
int inmid()
{
    int pos, i = 1;
    printf("\n enter the position:");
    scanf("%d", &pos);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the data:");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = 0;
    if (pos > count)
    {
        printf("\n invalid position!");
    }
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prevn = temp;
    temp->next = newnode;
    temp = newnode->next;
    temp->prevn = newnode;
    count++;
}
int inend()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the data:");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = 0;
    newnode->prevn = tail;
    tail->next = newnode;
    tail = newnode;
    count++;
}
int delst()
{
    if (head == 0)
    {
        printf("\n no node!");
    }
    else
    {
        printf("\n deleted element:%d", head->data);
        temp = head;
        head = head->next;
        head->prevn = 0;
        free(temp);
    }
    count--;
}
int delend()
{
    if (head == 0)
    {
        printf("\n no node!");
    }
    else
    {
        temp = tail;
        if (head == temp)
        {
            head = 0;
        }
        else
        {
            printf("\n deleted element:%d", temp->data);
            tail = tail->prevn;
            tail->next = 0;
        }
        free(temp);
    }
    count--;
}
int delmid()
{
    struct node *nextnode;
    int pos, i = 1;
    temp = head;
    printf("\n enter the postion:");
    scanf("%d", &pos);
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    nextnode->next->prevn = temp;
    free(nextnode);
    count--;
}
int search()
{
    int val, pos = 0, ser;
    printf("\n\nSEARCH:");
    printf("\nenter the data to be searched:");
    scanf("%d", &val);
    temp = head;
    while (temp != 0)
    {
        pos++;
        if (temp->data == val)
        {
            ser = 1;
            break;
        }
        else
        {
            ser = 0;
            temp = temp->next;
        }
    }
    if (ser == 1)
    {
        printf("\n no.%d found at position:%d", val, pos);
    }
    else
    {
        printf("number not found!");
    }
}
int main()
{
    int n, ch = 1;
    printf("\nSINGLY LINKED LIST:");
    create();
    printf("\n\n1.insert beg\t2.insert mid\t3.insert end\t4.delete beg\t.5.delete mid\t6.delete end\t7.search\n\n");
    while (ch == 1)
    {
        printf("\nenter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            inst();
            break;
        case 2:
            inmid();
            break;
        case 3:
            inend();
            break;
        case 4:
            delst();
            break;
        case 5:
            delmid();
            break;
        case 6:
            delend();
            break;
        case 7:
            search();
            break;
        default:
            printf("\n invalid choice!");
            break;
        }
        out();
        printf("\n\nthe number of element:%d\n\ncontinue press 1 otherwise 0:", count);
        scanf("%d", &ch);
    }
}