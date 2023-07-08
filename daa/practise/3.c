#include <stdio.h>
int min(int a, int b)
{
    return a > b ? b : a;
}
void floyd(int p[10][10], int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
            }
        }
    }
}
int main()
{
    int n, arr[10][10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the elements in the Adjacency Metrix ");
    printf("\nEnter 0 for self loop  and 999 for no edge: \n\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    floyd(arr, n);

    printf("\nThe shortest path is: \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
