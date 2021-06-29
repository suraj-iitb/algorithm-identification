#include<stdio.h>

int main()
{
    int o,n,k,i,j;
    int key;
    int A[110];
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%d",&A[i]);

    for(i=1; i<=n; i++)
    {
        key = A[i];
        j = i-1;
        while(j>0 && A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = key;
        for(k=1; k<=n; k++)
        {
            if(k == n)
                printf("%d\n",A[k]);
            else
                printf("%d ",A[k]);
        }
    }

    return 0;
}

