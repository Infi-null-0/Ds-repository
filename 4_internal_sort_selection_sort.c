#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    printf("-----SELECTION SORT-----\n");

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

    //! ordering
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }

    //! display
    printf("\nThe array is : <<< ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf(" >>>");

    return 0;
}