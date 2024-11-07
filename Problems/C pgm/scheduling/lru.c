#include<stdio.h>

int main()
{
    int frame[10],page[10],nof,nop,fault=0,top=0,hit,j,k;
    printf("Enter the number of frames: ");
    scanf("%d",&nof);
    printf("Enter the number of pages: ");
    scanf("%d",&nop);
    printf("Enter the page numbers: ");
    for(int i=0;i<nop;i++) scanf("%d",&page[i]);
    for(int i =0;i<nop;i++)
    {
        if(top<nof)
        {
            frame[top++]=page[i];
            fault++;
        }
        else
        {
            for(j=0;j<nof;j++)
            {
                if(frame[j]==page[i])
                {
                    break;
                }
            
            }
            if(j<nof)
            {
                for(k=j;k<nof-1;k++)
                {
                    frame[k]=frame[k+1];
                }
                frame[k]=page[i];
            }
            else
            {
                for(k=0;k<nof-1;k++)
                {
                    frame[k]=frame[k+1];
                }
                frame[k]=page[i];
                fault++;
            }

        }
        printf("Page %d \t",page[i]);
        for(int k=0;k<nof;k++) printf("%d ",frame[k]);
        if(j==nof || top<nof) printf("FAULT\n");
        else printf("HIT\n");
        
    }
    printf("Number of page faults: %d\n",fault);
    return 0;
}