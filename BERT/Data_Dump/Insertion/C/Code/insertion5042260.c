#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, k, v, N, *A;

    scanf("%d", &N);
    A = (int *)malloc(N * sizeof(int));
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    for(k = 0; k < N-1; k++)
        printf("%d ", A[k]);
    printf("%d\n", A[N-1]);

    for(i = 1; i < N; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        for(k = 0; k < N-1; k++)
            printf("%d ", A[k]);
        printf("%d\n", A[N-1]);
    }

    free(A);
    return 0;
}
