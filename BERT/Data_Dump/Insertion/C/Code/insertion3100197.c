#include<stdio.h>

int main()
{
    int n,v,j;
    scanf("%d",&n);
    int A[n];
    for(int x=0;x<n;x++)
    {
        scanf("%d",&A[x]);
        if(x != n-1)
        {
            printf("%d ",A[x]);
        }else {
            printf("%d\n",A[x]);
        }
    }
    for(int i=1;i<n;i++){
        v = A[i];
        j = i - 1;
        while(j >=0 && A[j] > v)
        {
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        for(int cont = 0;cont < n;cont ++)
        {
            if(cont != n-1)
            {
                printf("%d ",A[cont]);
            }else {
                printf("%d\n",A[cont]);
            }
        }
    }
    return 0;
}
