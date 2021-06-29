#include<stdio.h>

int main()
{
    int i,j,N,A[105],min,t,num=0;
    scanf("%d",&N);
    for(i = 0 ; i < N ; i++)
        scanf("%d",&A[i]);
    for(i = 0 ; i < N ; i++)
    {
        min = i;
        for(j = i ; j < N ; j++)
        {
            if(A[j] < A[min])
                min=j;
        }
        if(A[min] != A[i])
        {
            t = A[i];
            A[i] = A[min];
            A[min] = t;
            num++;
        }
    }
    for(i = 0 ;i < N-1 ; i++)
        printf("%d ",A[i]);
    printf("%d\n",A[i]);
    printf("%d\n",num);
    return 0;
}


