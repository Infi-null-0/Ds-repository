#include <stdio.h>
int main()
{
    int N, found = 0;
    printf("\n*****LINEAR_SEARCH******");
    printf("\nENter the size of the array::");
    scanf("%d", &N);
    int a[N], item, i;
    printf("\nEnter the elements of the array:: ");
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("\nEnter Item which is to be searched\n");
    scanf("%d", &item);

    for (i = 0; i < N; i++)
    {
        if (a[i] == item)
        {
            printf("element found at index is %d  location at %d ", i, i + 1);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("element not found");
    }
}