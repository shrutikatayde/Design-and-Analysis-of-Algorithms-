#include <stdio.h>
void knapsack(int n, float w[], float p[], int m)
{
    float x[20], tp = 0;
    int i, j, u;
    u = m;

    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++)
    {
        if (w[i] > u)
        {
            break;
        }
        else
        {
            x[i] = 1.0;
            tp = tp + p[i];
            u = u - w[i];
        }
    }
    if (i < n)
    {
        x[i] = u / w[i];
        tp = tp + (x[i] * p[i]);
    }

    printf("\nThe resultant vector is: ");
    for (i = 0; i < n; i++)
    {
        printf("%f\t", x[i]);
    }
    printf("\nThe maximum profit is: %f", tp);
}

int main()
{
    int n, m, temp;
    float w[50];
    float p[50];
    float ratio[50];
    int items[50];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("\nEnter the capacity of bag: ");
    scanf("%d", &m);
    
    printf("\nItems\tWeight\tProfit");
    printf("\n------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("I[%d]\t", i + 1);
        scanf("%f", &w[i]);
        scanf("%f", &p[i]);
    }

    for (int i=0; i < n; i++)
    {
        ratio[i] = p[i] / w[i];
    }

    printf("\n Items\t\tWeight\t\tProfit\t\tRatio");
    printf("\n-----------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("I[%d]\t\t", i + 1);
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
