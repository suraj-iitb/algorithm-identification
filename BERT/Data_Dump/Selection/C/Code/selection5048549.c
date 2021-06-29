#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, N, tmp, minj, count=0;
    int *A;

    scanf("%d", &N);
    A = (int *)malloc(N * sizeof(int));
    for(i=0; i<N; i++) scanf("%d", &A[i]);

    for(i=0; i<N; i++){
        minj = i;
        for(j=i; j<N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        if(i != minj) count++;
    }

    for(i=0; i<N-1; i++) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
    printf("%d\n", count);

    free(A);
    return 0;
}
