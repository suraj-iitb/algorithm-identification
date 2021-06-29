#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int i;
    int A[N];
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    int j;
    int cnt = 0;
    
    for(i = 0; i < N - 1; i++) {
    int min_i = i;
        for (j = i + 1; j < N; j++) {
            if (A[j] < A[min_i])
                min_i = j;
        }
        if (min_i != i) {
            int temp = A[i];
            A[i] = A[min_i];
            A[min_i] = temp;
            cnt++;
        }
    }

    for (i = 0; i < N - 1; i++)
        printf("%d ", A[i]);
    printf("%d\n", A[N - 1]);

    printf("%d\n", cnt);

    return 0;
}

