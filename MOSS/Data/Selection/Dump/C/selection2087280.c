#include <stdio.h>
int trump[101]={};
int n;

int main(void)
{
    scanf("%d",&n);
    int i,j;

    for(i=0;i<n;i++)
    {
        scanf("%d",&trump[i]);
    }
    int count=0;
    int minj,c;
    for(i=0;i<n;i++)
    {
        minj=i;
        for(j=i;j<n;j++)
        {
            if(trump[j]<trump[minj])
            {
                minj=j;
            }
        }
        if(i!=minj)
        {
            c=trump[i];
            trump[i]=trump[minj];
            trump[minj]=c;
            count++;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d",trump[i]);
        if(i<n-1)printf(" ");
    }
    printf("\n%d\n",count);


    return 0;
}
