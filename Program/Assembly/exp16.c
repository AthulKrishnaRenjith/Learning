#include<stdio.h> 
void main()
{
 int n,q[10],i,j,s,d,temp,x,y;
 float total=0;
 printf("Enter disk size:\n");
 scanf("%d",&s);
 s--;
 printf("Enter queue size: ");
 scanf("%d",&n); 
 printf("Enter 1ist to be sheduled: "); 
 for(i=1;i<=n;i++)
 {
  scanf("%d",&q[i]);
  printf("Enter initial head: "); 
  scanf("%d",&q [O]); 
  x=q[0];
  for(i=0;i<=n;i++)
  { 
   for(j=i+1;<=n;i++)
   {
    if(q[j]<q[i])
    {
     temp=q[i];
     q[i]=q[j];
     q[j]=temp;
    }
   }
  }
  for(i=0;i<=n;i++)
  {
   if(q[i]==x)
   y=i;
  } 
  printf("disk scheduling order\n %d",q[y]);
  for(i=y+1;i<=n:i++)
  {
    printf("-> %d",q[i]);
    total=total+q[i]-q[i-1];
   }
  printf("-> %d",s);
  total=total+s-q[--i];
  printf("->0->%d",q[0]);
  total=total+q[o];
  for(i=1;i<y;i++)
  {
    printf("->%d"q[i]);
    total=total+q[i]-q[i-1];
  }  
   printf("seektime:%f",total);
   getch();
}
