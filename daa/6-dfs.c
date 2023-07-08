#include<stdio.h>
 int n,arr[10][10],reach[20];

void dfs(int v)
{
reach[v]=1;
 for(int i=1;i<=n;i++)
 {
  if(arr[v][i] && !reach[i])
  {
   printf("\n%d ---> %d",v,i);
   dfs(i);
  }
 }
 
}


int main()
{ 
 printf("Enter number of Node : \n");
 scanf("%d",&n);
 
 printf("Enter the element in adjacency matrix : \n");

 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
    scanf("%d",&arr[i][j]);
  }
 }

dfs(1);
 
}
