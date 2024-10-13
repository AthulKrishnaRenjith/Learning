#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
 int st=0,m[50],hp,n,tot=0,y=0
 printf("Fcfs disc scheduling\n");
 printf("Enter the head position:\n");
 scanf("%d",&hp); 
 printf("Enter the limit:\n");
 scanf("%d",&n); 
 printf("Enter the values into memory:\n"); 
 for(int i=0;i<n;i++) 
 {
  scanf("%d",&m[i]);
 }
 st=abs(hp-m[0]);
 tot=tot+st;
 for(int i=1;i<n;i++)
 { 
  st=abs(m[i-1]-m[i]);
  tot=tot+st;
 }
 printf("Total seekcount:%d \n",tot);
 printf("Average seekcount:%d",tot/(float)n);
 return 0;
}