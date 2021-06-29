#include <stdio.h>

int main(){
    int N, A[100], i, j, cou=0, sw;
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    for(i=0; i<N; i++){
        for(j=N-1; j>i; j--){
            if(A[j]<A[j-1]){
                sw=A[j];
                A[j]=A[j-1];
                A[j-1]=sw;
                cou++;
            }
        }
    }
    for(i=0; i<N-1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n%d\n", A[N-1], cou);
    return 0;
}
