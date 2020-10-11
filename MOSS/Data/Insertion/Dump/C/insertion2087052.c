#include <stdio.h>
int trump[101]={};
int n;

void print(void)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d",trump[i]);
        if(i<n-1)printf(" ");
    }
    printf("\n");
    return;
}

int main(void)
{
    scanf("%d",&n);
    int i,j;

    for(i=0;i<n;i++)
    {
        scanf("%d",&trump[i]);
    }
    int v;
    print();
    for(i=1;i<n;i++)
    {
        v=trump[i];
        j=i-1;
        while(j>=0 && trump[j]>v)
        {
            trump[j+1]=trump[j];
            j--;
        }
        trump[j+1]=v;
        print();
    }


    return 0;
}
