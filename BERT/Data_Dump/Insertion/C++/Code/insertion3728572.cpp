#include<stdio.h>

void print(int A[], int N){
    for(int i = 0; i < N-1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N-1]);
}

void insertionSort(int A[], int N){
    for(int i = 0; i < N; i++){
        int v, j;
        v = A[i];
        j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print(A, N);
    }
}

 

int main(void){
    int n, a[200];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    insertionSort(a, n);

    return 0;   
}
