#include <stdio.h>
#define a 100
#define n 100

int selectionSort(int A[], int N){
    int i = 0;
    int j = 0;
    int minj = 0;
    int count = 0;
    int tmp = 0;
    int t = 0;
    
    for(i = 0; i < N; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(minj != i){
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            count++;
        }
    }
    
    for(t = 0; t < N; t++){
        if(t == N-1){
            printf("%d\n", A[t]);
        }else{
            printf("%d ", A[t]);
        }
    }
    printf("%d\n", count);
}

int main(void){
    int A[a] = {};
    int N = 0;
    int i = 0;
    
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    
    selectionSort(A, N);
    
    return 0;
}
