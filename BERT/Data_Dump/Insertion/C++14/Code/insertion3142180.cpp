#include<stdio.h>

void InsertionSort(int N, int *A)
{
    int j, i, v;
    for(i=0;i<N;i++)
    {
        v = A[i];
        j = i-1;
        while(j>=0 && A[j]>v)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j + 1]=v;
        for(int k=0;k<N;k++)
        {
            if(k>0)
            {
                printf(" ");
            }
            printf("%d",A[k]);
        }
        printf("\n");
    }
}

int main()
{
    int N;
    int A[110];
   
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    InsertionSort(N,A);
    return 0;
}
