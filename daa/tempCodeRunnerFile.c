#include<stdio.h>
int towerOfHanoi(int n,char source, char aux, char destination)
{
    if(n == 0)
    {
        // printf("Move %c to %c \n",source,destination);
        return 0;
    }
    towerOfHanoi(n-1,source,destination,aux);
    printf("Move Disk %d from %c to %c \n",n,source,destination);
    towerOfHanoi(n-1,aux,source ,destination);
}
