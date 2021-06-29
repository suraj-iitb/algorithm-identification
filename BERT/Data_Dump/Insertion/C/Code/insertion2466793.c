#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int i, A[100];
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }

    int v, j, k; 
    for(i = 0; i < N; ++i)
    {
        v = A[i];
        j = i - 1;

        while(j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = v;

        for(k = 0; k < N; ++k)
        {
            printf("%d%s", A[k], k != N - 1 ? " " : "\n");
        }
    }

    return 0;
}
