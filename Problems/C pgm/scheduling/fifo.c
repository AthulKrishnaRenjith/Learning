#include<stdio.h>

int main()
{
    int frame[10],page[10],nof,nop,hit,fault=0,j=0;
    printf("Enter the number of frames: ");
    scanf("%d",&nof);
    printf("Enter the number of pages: ");
    scanf("%d",&nop);
    printf("Enter the page numbers: ");
    for(int i=0;i<nop;i++) scanf("%d",&page[i]);
    for(int i=0;i<nof;i++) frame[i]=-1;
    for(int i = 0;i<nop;i++)
    {
        printf("Page %d \t",page[i]);
        hit =0;
        for(int k =0;k<nof;k++) if(frame[k]==page[i]) hit=1;
        if(hit==0)
        {
            frame[j]=page[i];
            j=(j+1)%nof;
            fault++;
            for(int k=0;k<nof;k++) printf("%d ",frame[k]);
            printf("FAULT\n");
        }
        else{
            printf("HIT\n");
        }
    }
    printf("Number of page faults: %d\n",fault);
    return 0;
}