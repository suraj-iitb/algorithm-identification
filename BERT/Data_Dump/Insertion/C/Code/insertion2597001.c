
#include "stdio.h"


int main()
{
    int N, a, A[1000];
    scanf("%d", &N);
    for (a = 0; a<N; a++)
        scanf("%d\n", &A[a]);

    for (a = 0; a < N - 1; a++)
        printf("%d ", A[a]);

    printf("%d\n", A[N-1]);

    int j;
    for (int i = 1; i < N; i++) {
        int v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    

    for (j = 0; j < N - 1; j++)
        printf("%d ", A[j]);

    printf("%d\n", A[N - 1]);
    }

    return 0;
}
