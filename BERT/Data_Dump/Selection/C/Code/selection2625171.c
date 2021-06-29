#include <stdio.h>
 
int main(void){
    int N, i, j, minj;
    int count = 0, swap;
    
    scanf("%d", &N);
    
    int A[N];
    for(i = 0; i < N; i ++) scanf("%d", &A[i]);
    
    for(i = 0; i < N; i ++) {
        minj = i;
        for(j = i; j < N; j ++) {
            if(A[j] < A[minj]) {
                minj = j;
            }
        }
        swap = A[i];
        A[i] = A[minj];
        A[minj] = swap;
        if (minj != i) count ++;
    }
    
    for(i = 0; i < N-1; i ++) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
    printf("%d\n", count);
    
    return 0;
}
