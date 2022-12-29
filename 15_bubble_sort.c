#include <stdio.h>

int main()
{
    int i, j, N, temp;
    printf("Enter the size of the array : ");
    scanf("%d", &N);
    int arr[N];
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted elements: ");
    for (i = 0; i < N; i++)
        printf("%d", arr[i]);
}