#include<stdio.h>

void selectionSort(int *A, int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(A[i] != A[minj]){
            int temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            count++;
        }
    }
    for(int i = 0; i < N; i++){
        if(i != N-1){
            printf("%d ",A[i]);
        }
        else{
            printf("%d\n",A[i]);
        }
    }
    printf("%d\n",count);
}

int main(void){
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }
    selectionSort(A, N);
    return 0;
}
