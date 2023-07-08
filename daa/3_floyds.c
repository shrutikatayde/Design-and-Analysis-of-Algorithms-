#include <stdio.h>

int min(int a, int b)
{
  if (a > b)
  {
    return b;
  }
  else
  {
    return a;
  }
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

  printf("Enter number of Node : ");
  scanf("%d", &n);

  printf("\nEnter the element in adjacency matrix \n");
  printf("Enter 0 for self loop and 999 for no edge: \n\n");
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  floyd(arr, n);

  printf("\nThe Shortest Path is: \n");
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}
