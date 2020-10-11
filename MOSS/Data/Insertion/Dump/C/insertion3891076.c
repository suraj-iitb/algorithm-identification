// Insertion Sort  挿入ソート

#include <stdio.h>

void insertionSort(int *A, int N) {
    int v, i, j, k;

    // 標準出力で表示する
    for(k = 0; k < N; k++) {
        printf("%d", A[k]);
        if(k == N - 1) // 最後の要素の後は空白ではなく改行
            printf("\n");
        else
            printf(" ");
    }

    // 挿入ソート
    for(i = 1; i < N; i++) {
        v = A[i];  // 移動対象の値
        j = i - 1; // 移動対象の今いるidxの左の値
        while(j >= 0 && A[j] > v) {
            A[j + 1] = A[j]; // 左の値を右にずらす
            j--;
        }
        A[j + 1] = v; //挿入先まできたら値を入れる

        // 標準出力で表示する
        for(k = 0; k < N; k++) {
            printf("%d", A[k]);
            if(k == N - 1) // 最後の要素の後は空白ではなく改行
                printf("\n");
            else
                printf(" ");
        }
    }
}

int main(int argc, char const *argv[]) {
    const int MAX = 100;
    int A[MAX];
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    insertionSort(A, N);

    return 0;
}

