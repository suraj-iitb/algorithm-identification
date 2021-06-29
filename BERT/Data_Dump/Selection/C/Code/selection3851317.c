#include <stdio.h>

int
main(void)
{
    int i, j, N, A[101], min, tmp, count;
    
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
        scanf("%d", A + i);
    
    count = 0;
    for(i = 0; i < N; ++i) {
        min = i;
        for(j = i; j < N; ++j) {
            if(A[j] < A[min]) min = j;
        }
        if(i != min) {
            tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
            count++;
        }
    }
    for(i = 0; i < N-1; ++i)
        printf("%d ", A[i]);
    printf("%d\n%d\n", A[N-1], count);
}

