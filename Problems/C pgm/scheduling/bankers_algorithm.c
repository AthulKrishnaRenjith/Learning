#include<stdio.h>
int main()
{
    int no_p, no_r, alloc[50][50], max[50][50], need[50][50], avail[50], work[50], finish[50], count=0, safe[50];
    printf("Enter the number of processes: ");
    scanf("%d",&no_p);
    printf("Enter the number of resources: ");
    scanf("%d",&no_r);
    printf("Enter the allocation matrix: ");
    for(int i=0;i<no_p;i++)
    {
        for(int j=0;j<no_r;j++)
        {
            printf("ALLOCATION OF P%d R%d: ",i,j);
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the max matrix: ");
    for(int i=0;i<no_p;i++)
    {
        for(int j=0;j<no_r;j++)
        {
            printf("MAX OF P%d R%d: ",i,j);
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the available matrix: ");
    for(int i=0;i<no_r;i++)
    {
        printf("AVAILABLE OF R%d: ",i);
        scanf("%d",&avail[i]);
    }
    for(int i=0;i<no_p;i++)
    {
        for(int j=0;j<no_r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(int i=0;i<no_r;i++)
    {
        work[i]=avail[i];
    }
    for(int i=0;i<no_p;i++)
    {
        finish[i]=0;
    }
    for(int i=0;i<no_p;i++)
    {
        for(int j=0;j<no_p;j++)
        {
            if(finish[j]==0)
            {
                int flag=0;
                for(int k=0;k<no_r;k++)
                {
                    if(need[j][k]>work[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    for(int k=0;k<no_r;k++)
                    {
                        work[k]+=alloc[j][k];
                    }
                    finish[j]=1;
                    safe[count++]=j;
                }
            }
        }
    }
    if(count==no_p)
    {
        printf("The system is in safe state\n");
        printf("The safe sequence is: ");
        for(int i=0;i<no_p;i++)
        {
            printf("P%d ",safe[i]);
        }
    }
    else
    {
        printf("The system is in unsafe state\n");
    }
    return 0;
    
}