#include <stdio.h>
int binarySearch(int[], int, int, int);
int main()
{
    int N;
    printf("\n****BINARY_SEARCH****\n");
    printf("\nEnter the size of the array::");
    scanf("%d", &N);
    int arr[N], item, i, location = -1;
    printf("\nEnter the elements of the array:: ");
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    printf("Enter the item which you want to search ");
    scanf("%d", &item);
    location = binarySearch(arr, 0, N, item);
    if (location != -1)
    {
        printf("\nItem %d found at index-> %d location-> %d\n", item, location - 1, location);
    }
    else
    {
        printf("Item not found");
    }
}
int binarySearch(int a[], int beg, int end, int item)
{
    int mid;

    if (end >= beg)
    {
        mid = (beg + end) / 2;
        if (a[mid] == item)
        {
            return mid + 1;
        }
        else if (a[mid] < item)
        {
            return binarySearch(a, mid + 1, end, item);
        }
        else
        {
            return binarySearch(a, beg, mid - 1, item);
        }
    }
    return -1;
}