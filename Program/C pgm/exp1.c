#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
 int flag=0,l=0,len,i,j,k=0,sem=0;
 FILE *ptr;
 char str[50];
 ptr=fopen("file.txt","r");
 fgets(str,50,ptr);
 printf("\n %s \n",str);
 len=strlen(str); 
 for(i=0;i<len;i++)
 {
  if(str[i]=='(')
  { 
   for(j=i;j<len;j++)
   {
    if(str[j]==')')
    {
      flag=1;
      break;
    }
   }
   if(flag==0)
   {
    printf("The closing bracket was not found");
   }
   l=1; 
  }
 }
 if(l==0)
 {
    printf("The opening bracket was not found");
 }
 for(i=0;i<len;i++)
 {
  if(str[i]==';')
  {
   sem++;
  }
 }
 if(sem!=2)
 {
    printf("Incorrect no. of semicolons");
 }
 for(i=0;i<len;i++)
 {
  if(str[i]=='{')
  {
   for(j=i;j<len;j++)
   {
    if(str[j]=='}')
    {
     flag=1;
     break;
    }
    flag=0;
   }
   if(flag==0)
   {
    printf("The close curly was not found");
   }
   k=1;
  }
 }
 if(k==0)
 {
   printf("The open curly was not found");
 }
 if(flag==1 && k==1 && l==1 && sem==2)
 {
  printf("\n The syntax is correct \n");
 }
 else
 {
  printf("\n The syntax is wrong \n");
 }
 fclose(ptr);
}