#include <stdio.h>
 
int main(void){
    int N, i, j;
    int count = 0, flag = 1, swap;
    
    scanf("%d", &N);
    
    int A[N];
    for(i = 0; i < N; i ++) scanf("%d", &A[i]);
    
    while(flag) {
        flag = 0;
        for(j = N-1; j > 0; j --) {
            if(A[j] < A[j-1]) {
                swap = A[j];
                A[j] = A[j-1];
                A[j-1] = swap;
                count ++;
                flag = 1;
            }
        }
    }
    
    for(i = 0; i < N-1; i ++) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
    printf("%d\n", count);
    
    return 0;
}
