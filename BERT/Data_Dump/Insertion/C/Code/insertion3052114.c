#include <stdio.h>

/*
挿入ソート
*/

void trace(int A[], int n){
    // 1行半角スペースで書き出し
    for (int i = 0; i < n; i++){
        printf("%d", A[i]);
        if (i != n-1){
            printf(" ");
        }
        else {
            printf("\n");
        }
    }
}

void insertionSort(int A[], int n){
    int v;
    int j;

    for (int i = 1; i < n; i++){
        v = A[i];
        j = i - 1;

        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, n);
    }
}

int main(){
    // 1行読む
    int n;
    scanf("%d", &n);

    // 1行半角スペースで読む
    int A[100];
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    // 出力用の関数
    trace(A, n);

    // 挿入ソートのロジック部分の関数
    insertionSort(A, n);

    return 0;
}

