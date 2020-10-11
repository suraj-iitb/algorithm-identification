#include<stdio.h> //なんで動かないのかわからない。飛ばす。

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int bubblesort(int A[], int N){
    int sw = 0;
    
    for( int i = 0; i < N-1; i++){
        for(int j = N-1; j > i; j--){
            if( A[j] < A[j - 1]){
                swap(&A[j], &A[j - 1]);
                sw++;
            }
        }
    }
    return sw;
}

int main(){
    int A[100], N, sw;
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    sw = bubblesort(A, N);
    
    for(int i = 0; i < N; i++){
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", sw);
    return 0;
}
