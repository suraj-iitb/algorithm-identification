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

    int flag=1;
    int count=0;
    while(flag)
    {
        flag=0;
        for(j=n-1;j>=1;j--)
        {
            if(trump[j]<trump[j-1])
            {
                int c;
                c=trump[j-1];
                trump[j-1]=trump[j];
                trump[j]=c;
                flag=1;
                count++;
            }
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
