#include<stdio.h>
#include<stdlib.h>
#define A 100

int main ()
{
    int i,j;
    int n;
    int sort[A];
    int a;
    int b;
    
    scanf("%d",&n);
    
    if(n>A)
    {
        printf("print errar");
        exit(1);
    }
    
    i=0;
    while(i<n)
    {
        scanf("%d",&sort[i]);
        i++;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(sort[j]>sort[i])
            {
                a=sort[i];
                for(b=i;b>=j;b--)
                {
                    sort[b]=sort[b-1];
                }
                sort[j]=a;
                break;
            }
        }
        b=0;
        while(b+1<n)
        {
            printf("%d ",sort[b]);
            b++;
        }
        printf("%d\n",sort[n-1]);
    }
}














