#include <stdio.h>
void merging(int arr[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb, b[ub], l;
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while (j <= ub)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    for (l = lb; l <= ub; l++)
    {
        arr[l] = b[l];
    }
}

void merge_sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort(arr, lb, mid);
        merge_sort(arr, mid + 1, ub);
        merging(arr, lb, mid, ub);
    }
}

int main()
{
    int n, temp;
    printf("-----MERGE SORT-----\n");

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

    merge_sort(a, 0, n - 1);

    //! display
    printf("\nThe array is : <<< ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf(" >>>");

    return 0;
}