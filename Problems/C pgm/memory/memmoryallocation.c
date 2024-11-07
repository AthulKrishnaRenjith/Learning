#include<stdio.h>

struct process
{
    int pid;
    int size;
    int allocated;     
};

struct block
{
    int bid;
    int size;
    int allocated;
};
void firstfit(struct process po[],struct block bo[],int n, int m)
{
    struct process p[10];           
    struct block b[10]; 
    for(int i=0;i<n;i++)
    {
        p[i]=po[i];
    }
    for(int i=0;i<m;i++)
    {
        b[i]=bo[i];
    }   
    printf("\nFirst Fit\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(p[i].size<=b[j].size && b[j].allocated==0)
            {
                b[j].allocated=1;
                p[i].allocated=1;
                printf("Process P%d is allocated to Block B%d\n",p[i].pid,b[j].bid);
                break;
            }
        }
        if(p[i].allocated==0)
        {
            printf("Process P%d is not allocated\n",p[i].pid);
        }
    }       
}
void bestfit(struct process po[],struct block bo[],int n, int m)
{
    struct process p[10];           
    struct block b[10]; 
    for(int i=0;i<n;i++)
    {
        p[i]=po[i];
    }
    for(int i=0;i<m;i++)
    {
        b[i]=bo[i];
    }   
    printf("\nBest Fit\n");
    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if(b[i].size>b[j].size)
            {
                struct block temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(p[i].size<=b[j].size && b[j].allocated==0)
            {
                b[j].allocated=1;
                p[i].allocated=1;
                printf("Process P%d is allocated to Block B%d\n",p[i].pid,b[j].bid);
                break;
            }
        }
        if(p[i].allocated==0)
        {
            printf("Process P%d is not allocated\n",p[i].pid);
        }
    }       
}
void worstfit(struct process po[],struct block bo[],int n, int m)
{
    struct process p[10];           
    struct block b[10]; 
    for(int i=0;i<n;i++)
    {
        p[i]=po[i];
    }
    for(int i=0;i<m;i++)
    {
        b[i]=bo[i];
    }   
    printf("\nWorst Fit\n");
    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if(b[i].size<b[j].size)
            {
                struct block temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(p[i].size<=b[j].size && b[j].allocated==0)
            {
                b[j].allocated=1;
                p[i].allocated=1;
                printf("Process P%d is allocated to Block B%d\n",p[i].pid,b[j].bid);
                break;
            }
        }
        if(p[i].allocated==0)
        {
            printf("Process P%d is not allocated\n",p[i].pid);
        }
    }       
}

int main()
{
    int n,m;
    struct process p[10];
    struct block b[10];
    printf("Enter the number of processes: ");  
    scanf("%d",&n);     
    printf("Enter the number of blocks: ");
    scanf("%d",&m);         
    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Enter the size of process P%d: ",i+1);
        scanf("%d",&p[i].size);
        p[i].allocated=0;
    }
    for(int i=0;i<m;i++)
    {
        b[i].bid=i+1;
        printf("Enter the size of block B%d: ",i+1);
        scanf("%d",&b[i].size);
        b[i].allocated=0;
    }
    firstfit(p,b,n,m);
    bestfit(p,b,n,m);   
    worstfit(p,b,n,m);  
    return 0;   
}