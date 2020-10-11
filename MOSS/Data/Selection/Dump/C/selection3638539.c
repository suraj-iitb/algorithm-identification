#include<stdio.h>

int selectionsort(int A[], int N){
    int minj, t, sw = 0;
    for(int i = 0; i < N; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if( A[j] < A[minj]){
                minj = j;
            }
        }
        t = A[i]; A[i] = A[minj]; A[minj] = t;
        if(i != minj) sw++;
    }
    return sw;
}

int main(){
    int A[100], N, sw;
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    sw = selectionsort(A, N);
    
    for(int i = 0; i < N; i++){
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", sw);
    
    return 0;
}
