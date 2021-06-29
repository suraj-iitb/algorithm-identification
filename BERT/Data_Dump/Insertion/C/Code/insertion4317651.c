#include<stdio.h>

// 配列の要素を順番に出力
void trace(int A[], int N) {
    for (int i=0; i<N; i++) {
        if (i>0) printf(" ");  //隣接する要素の間に1つの空白を出力
        printf("%d", A[i]);
    }
    printf("\n");
}

// 挿入ソート(0オリジン配列)
void insertionSort(int A[], int N) {
    int j, i, tmp;
    for (i=1; i<N; i++) {
        tmp = A[i];
        j = i-1;
        while (j>=0 && A[j]>tmp) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = tmp;
        trace(A, N);
    }
}

int main() {
    int N, i, j;
    int A[100];

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);

    trace(A, N);
    insertionSort(A, N);

    return 0;
}
