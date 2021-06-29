#include<stdio.h>

void trace(int A[], int N) {
    for ( int i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int N) {
    int i, j, v;
    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        //未ソート部の銭湯に一時変数vを代入
        A[j + 1] = v;
        trace(A, N);
    }
}
    


int main() {
    int N, i, j;
    int A[100];
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &A[i]);
    
    //初めの状態を出力
    trace(A, N);
    insertionSort(A, N);
    
    return 0;
}
