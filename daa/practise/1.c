#include <stdio.h>
int toh(int n, char big, char aux, char end)
{
    if (n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, big, end);
        return 0;
    }
    else
    {
        toh(n - 1, big, end, aux);
        printf("Move disk %d from %c to %c\n", n, big, end);
        toh(n - 1, aux, big, end);
    }
}
int main()
{
    int n = 3;
    toh(n, 'A', 'B', 'C');
}