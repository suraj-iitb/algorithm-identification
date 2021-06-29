#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, N, tmp, flag=1, count=0;
    int *A;

    scanf("%d", &N);
    A = (int *)malloc(N * sizeof(int));
    for(i=0; i<N; i++) scanf("%d", &A[i]);

    for(i=0; flag; i++){
        flag = 0;
        for(j=N-1; j>i; j--){
            if(A[j] < A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                count++;
                flag = 1;
            }
        }
    }

    for(i=0; i<N-1; i++) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
    printf("%d\n", count);

    free(A);
    return 0;
}
