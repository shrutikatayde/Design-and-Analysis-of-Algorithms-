#include <stdio.h>
void knapsack(int n, float w[], float p[], int m)
{
  float x[20], tp = 0;
  int i, j, u;
  u = m;

  for (i = 0; i < n; i++)
    x[i] = 0.0;

  for (i = 0; i < n; i++)
  {
    if (w[i] > u)
    {
      break;
    }
    else
    {
      x[i] = 1.0;
      tp = tp + p[i]; // 24
      u = u - w[i];   // 5
    }
  }
  
  if (i < n)
    x[i] = u / w[i];
    tp = tp + (x[i] * p[i]);

  printf("\n The resultant vector is: ");
  for (i = 0; i < n; i++)
  {
    printf("%f\t", x[i]);
  }
  printf("\n The Maximum profit is: %f \n", tp);
}


int main()
{
  int n, m, temp;
  float w[50];
  float p[50];
  int items[50];
  float ratio[50];
  printf("\nEnter the number of items: ");
  scanf("%d", &n);
  printf("\nEnter capcity of bag : ");
  scanf("%d", &m);
  printf("\n items\tweight\tprofit");
  printf("\n------------------------\n");


  for (int i = 0; i < n; i++)
  {
    printf("I[%d]\t", i + 1);
    scanf("%f", &w[i]);
    scanf("%f", &p[i]);
  }


  for (int i = 0; i < n; i++)
  {
    ratio[i] = p[i] / w[i];
  }


  printf("\nitems\tweight\tprofit\tRatio");
  printf("\n------------------------------\n");
  for (int i = 0; i < n; i++)
  {
    printf("I[%d]\t", i + 1);
    printf("%f\t", w[i]);
    printf("%f\t", p[i]);
    printf("%f\t", ratio[i]);
    printf("\n");
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (ratio[i] < ratio[j])
      {
        temp = ratio[i];
        ratio[i] = ratio[j];
        ratio[j] = temp;

        temp = w[i];
        w[i] = w[j];
        w[j] = temp;

        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
  knapsack(n, w, p, m);
  return 0;
}