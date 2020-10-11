#include"stdio.h"
#include"stdlib.h"
int main()
{
    int i,j;
    int n;
    int *A;
    int buf;
    int count=0;
    scanf("%d",&n);
    A=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);   
    }
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(A[j-1]>A[j])
            {
                buf=A[j-1];
                A[j-1]=A[j];
                A[j]=buf;
                count++;
            }
        }
    }
    printf("%d",A[0]);
    for(i=1;i<n;i++)
    {
        printf(" %d",A[i]);
    }
    printf("\n%d\n",count);
    return 0;
}
