#include<stdio.h>
#define A 100

int k=0;

void swap (int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void bubble_sort(int abc[],int abc_size)
{
    int i,j;
    
    for(i=0;i<abc_size-1;i++)
    {
        for(j=abc_size-1;j>=i+1;j--)
        {
            if(abc[j]<abc[j-1])
            {
                swap(&abc[j],&abc[j-1]);
                k++;
            }
        }
    }
}

int main(void)
{
    int abc[A];
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&abc[i]);
    }
    
    bubble_sort(abc,n);
    
    for(i=0;i<n-1;i++)
    {
        printf("%d ",abc[i]);
    }
    printf("%d\n",abc[i]);
    printf("%d\n",k);
    return 0;
}


