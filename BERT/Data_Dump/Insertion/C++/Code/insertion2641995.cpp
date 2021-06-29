#include<stdio.h>

void trace(int A[], int N){
    for(int i = 0; i < N; i++){
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");

}

void insersionSort(int A[], int N){
    for(int i = 1; i < N; i++){
        int v = A[i];
        int j = i - 1;

        while(j >=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        trace(A,N);
    }

}

int main(){
    int A[100];
    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)scanf("%d",&A[i]);

    trace(A, N);
    insersionSort(A,N);

}
