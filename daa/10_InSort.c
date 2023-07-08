#include <stdio.h>

void main()
{
    void insertion_sort(int a[], int N);
    int a[10], i, N;

    N = 10;

    printf("\n Enter the ten elements to sort:\n");
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    insertion_sort(a, N);

    printf("\n\nThe sorted elements are:\n");
    for (i = 0; i < N; i++)
        printf("%d\n", a[i]);
}

void insertion_sort(int a[], int N)
{
    int i = 0, j = 0, temp = 0;
    for (i = 0; i < N; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0; j--)
            if (a[j] > temp)
                a[j + 1] = a[j];
            else
                break;
        a[j + 1] = temp;
    }
}