#include <stdio.h>
void bfs(int a[20][20],int visited[20],int q[20],int n,int v)
{
    int front=0;
    int rear=0;
    q[front]=v;
    visited[v]=1;
   
    while(front<=rear)
    {
        int temp=q[front];
        front++;
        printf("%d",temp);
       
        v=temp;
        int i;
        for( i=0;i<n;i++)
        {
            if(visited[i+1]==0 && a[v-1][i]==1)
            {
                rear++;
                q[rear]=i+1;
                visited[i+1]=1;
            }
        }
    }
}
int main()
{
   int n,i,j,a[20][20],q[20],visited[20];
   printf("Enter the number of verices: ");
   scanf("%d",&n);
   
   
   for(i=0;i<=n;i++)
   {
       visited[i]=0;
       q[i]=-1;
   }
   printf("Enter the elements in the array\n");
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           scanf("%d",&a[i][j]);
       }
   }
   
   printf("The solution of BFS:");
   bfs(a,visited,q,n,1);
}