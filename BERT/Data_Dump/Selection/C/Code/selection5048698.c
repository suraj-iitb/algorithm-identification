#include <stdio.h>

int main()
{
    int i, j, minj,temp, count=0, N, A[100];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < N; i++)
    {
        minj=i;
        for (j = i+1; j<N; j++)
        {
            if (A[j] < A[minj])
            {
                minj=j;
            }
        }

        if(A[i]>A[minj]){
            count++;
        }

        temp=A[i];
        A[i]=A[minj];
        A[minj]=temp;
    }

    for (j = 0; j < N; j++)
    {
        printf("%d", A[j]);
        if (j == N - 1)
            break;
        else
            printf(" ");
    }
    printf("\n%d\n", count);

    return 0;
}
