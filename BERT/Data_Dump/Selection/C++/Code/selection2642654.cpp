#include<stdio.h>

void trace(int A[], int N){
    for(int i = 0; i < N; i++){
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");

}

int selectionSort(int A[], int N){
    int count = 0;

    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i != minj){
            int tmp = A[i];
            A[i]= A[minj];
            A[minj] = tmp;
            count++;
        }
    }
    return count;

}

int main(){
    int A[100];
    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)scanf("%d",&A[i]);

    int count = selectionSort(A,N);
    trace(A, N);

    printf("%d\n", count);

}
