#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int sorting(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int
        start = lb;
    int end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
            start++;
        while (arr[end] > pivot)
            end--;
        if (start < end)
            swap(&arr[start], &arr[end]);
    }
    swap(&arr[lb], &arr[end]);
    return end;
}

void quick_sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = sorting(arr, lb, ub);
        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}
int main()
{
    int n, temp;
    printf("-----QUICK SORT-----\n");

    //! get array size
    printf("\nEnter the size of the array : ");
    scanf("%d", &n);
    int a[n];
    printf("\n");

    //! get array elements
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element [%d] : ", i);
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n - 1);

    //! display
    printf("\nThe array is : <<< ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf(" >>>");

    return 0;
}