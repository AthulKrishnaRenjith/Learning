#include<stdio.h>
void main()
{
    int n,q[0],i,j,s,d,temp,x,y;
    float total=0;
    printf("Enter the disk size:");
    scanf("%d",&s);
    s--;
    printf("Enter the queue size:");
    scanf("%d",&n);
    printf("Enter list to be scheduled:");
    for(i=1;i<=n;i++)
    {
      scanf("%d",&q[i]);
    }
    printf("enter the initial head:");
    scanf("%d",&q[0]);
    x=q[0];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(q[j]<q[i])
            {
               temp=q[i];
               q[i]=q[j];
               q[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
      if(q[i]==x)
           y=1;
    }
    printf("Disk scheduling order\n%d",q[y]);
    for(i=y+1;i<=n;i++)
    {
        printf("->%d",q[i]);
        total=total+q[i]-q[i-1];
    }
    printf("->%d",s);
    total=total+s-q[--i];
    printf("->0->%d",q[0]);
    total=total+q[0];
    for(i=0;i<y;i++)
    {
       printf("->%d",q[i]);
       total=total+q[i]-q[i-1];
    }
    printf("\nseektime is:%2f",total);
}
