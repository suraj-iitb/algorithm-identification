#include<stdio.h>

void insertionsort(int A[],int N){
    int v, j;
    for(int i=1; i<N; i++){
        v = A[i];
        j = i - 1;
        while( j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A,N);
    }
}

void trace(int A[], int N){
    for(int i = 0; i < N; i++){
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int main(){
    int A[100], N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    trace(A, N);
    insertionsort(A, N);
    return 0;
}
