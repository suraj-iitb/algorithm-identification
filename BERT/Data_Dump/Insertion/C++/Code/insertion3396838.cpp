#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;


//配列の要素を順番に出力
void trace(int A[], int N) {
    int i;
    
    for (i = 0; i < N; i++) {
        if (i > 0)    printf(" ");    //隣接する要素の間に1つの空白を出力
        printf("%d", A[i]);
    }
    printf("\n");
}


//挿入ソート
void insertionSort(int A[], int N)       //N個の要素を含む0-オリジンの配列A
{
    //i: 未ソートの部分列の先頭を示すループ変数
    //v: A[i]の値を一時的に保持しておく変数
    //j: ソート済みの部分列からvを挿入するためのイチを探すループ変数
    int v, i, j;          

    for (i = 1; i < N; i++) {
        v = A[i];          
        j = i - 1;

        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
       trace(A, N);
    }
}

int main() {
    int N, i, j;
    int A[100];

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    trace(A, N);
    insertionSort(A, N);

    return 0;   
}
