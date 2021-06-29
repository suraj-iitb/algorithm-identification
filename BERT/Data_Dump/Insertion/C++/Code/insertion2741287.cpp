#include <iostream>
#include <stdio.h>
using namespace std;

void trace(int A[], int N){
    int len = N - 1;
    for(int i = 0; i < len; ++i) printf("%d ", A[i]);
    printf("%d\n", A[len]);
}

void insertionSort(int A[], int N){
    for(int i = 1; i < N; ++i){
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}

int main(void){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; ++i) cin >> A[i];
    
    trace(A, N);
    insertionSort(A, N);
    
    return 0;
}
