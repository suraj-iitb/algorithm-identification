#include <stdio.h>

void selectionSort(int*, int);

int main(){
    int A[255];
    int i, N;
    
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }
    selectionSort(A, N);
    
    return 0;
}

void selectionSort(int A[], int N){
    int i, j, minj, num, count;
    count = 0;
    
    for(i = 0; i < N; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        num = A[i];
        A[i] = A[minj];
        A[minj] = num;
        if(minj != i){
            count = count + 1;
        }
    }
    
    for(j = 0; j < N - 1; j++){
        printf("%d ", A[j]);
    }
    printf("%d\n", A[j]);
    printf("%d\n", count);
    
}


