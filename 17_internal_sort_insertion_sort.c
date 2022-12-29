#include <stdio.h>
int main()
{
    int n, temp;
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
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        int j = i - 1;
        while ((temp < a[j]) && (j >= 0))
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = temp;
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