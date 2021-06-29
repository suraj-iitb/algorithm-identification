#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main()
{
    unsigned short *A, *B;

    int C[VMAX + 1];  // 配列Cはカウンタ配列(ソートする配列Aの累積和を記録する)
    int n, i, j;
    scanf("%d", &n);

    A = malloc(sizeof(short) * n + 1);  // ソートする配列Aのメモリ領域を確保
    B = malloc(sizeof(short) * n + 1);  // ソートされた配列Bのメモリ領域を確保

    for (i = 0; i <= VMAX; i++) {
        C[i] = 0;  // カウンタ配列Cを初期化
    }
    
    for (i = 0; i < n; i++) {
        scanf("%hu", &A[i + 1]);
        C[A[i + 1]]++;  // 配列Aの値を添字とするCの一部をインクリメントする
    }

    for (i = 1; i <= VMAX; i++) {
        C[i] = C[i] + C[i - 1];  // Cの累積和を求める
    }
    
    for (j = 1; j <= n; j++) {
        // Aの要素を添え字とするCのカウンタ配列を添字とする部分にAの要素を入れる
        // CはAの要素の累積和だからAの要素が何番目に出てきたかが記録されている
        // C[A[j]]が3ということはA[j]が3番目に出てきたということ
        // 同じ要素が複数回出ているかもしれないのでBに代入後は添字となったCの要素はデクリメント
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for (i = 1; i <= n; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}
