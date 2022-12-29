#include <stdio.h>
#include <stdlib.h>
int heap[20], i, val, parent, child, size = 0;
void display()
{
    printf("TREE >> ");
    if (size == 0)
    {
        printf(" EMPTY ");
    }
    else
    {
        for (i = 1; i <= size; i++)
        {
            printf("-> %d", heap[i]);
        }
    }
}
void swap(int a, int b)
{
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

void up_heapify(int child)
{
    if (child > 1)
    {
        parent = child / 2;
        if (heap[parent] < heap[child])
        {
            swap(parent, child);
            up_heapify(parent);
        }
    }
}

void insert()
{
    printf("\nEnter the data value:: ");
    scanf("%d", &val);
    size = size + 1;
    heap[size] = val;
    up_heapify(size);
    display();
}

void down_heapify(int parent)
{
    int largest = parent;
    int leftChild = 2 * parent;
    int rightChild = 2 * parent + 1;
    if (rightChild < size && heap[rightChild] > heap[largest])
        largest = rightChild;
    if (leftChild < size && heap[leftChild] > heap[largest])
        largest = leftChild;
    if (parent != largest)
    {
        swap(parent, largest);
        down_heapify(largest);
    }
}

void deleteRoot()
{
    swap(1, size);
    --size;
    down_heapify(1);

    display();
}

int MAX()
{
    return heap[1];
}
int extractMAX()
{
    int ans = heap[1];
    deleteRoot();
    return ans;
}

int main()
{
    int c, ch = 1;
    while (ch)
    {
        printf("\n1.Insert\n2.Delete Root\n3.MAX No.\nexit()\tCHOICE: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            extractMAX();
            break;
        case 3:
            printf("The MAX No. is :: %d", MAX());
            break;
        case 4:
            exit(EXIT_SUCCESS);
        default:
            printf("\nWRONG choice!!!");
        }
        printf("\n");
        printf("to continue press 1 0r o for exit:");
        scanf("%d", &ch);
    }
}