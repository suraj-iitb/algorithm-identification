// bubble sort バブルソート

#include <stdio.h>

// 標準出力にarrayを出力する関数
void printArray(int *A, int N){
    for(int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if(i < N-1) printf(" ");  // 最後の要素以外は空白を挟む
    }
    printf("\n");
}

// 小さい順に並び替える バブルソート
int bubbleSort(int *A, int N) {
    int tmp;
    int count = 0;    // 交換した回数をカウントする変数
    int flag = 1; // 逆の隣接要素が存在する. L > R
    while(flag == 1) {
        flag = 0;
        for(int i = N - 1; i >= 1; i--) { // 最後のidx N-1 から idx 1 まで
            if(A[i - 1] > A[i]) {         // L > R なら入れ替える
                tmp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = tmp;

                flag = 1;
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char const *argv[]) {
    const int MAX = 100;
    int A[MAX];
    int N;
    int count;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    count = bubbleSort(A, N);

    printArray(A, N);
    printf("%d\n", count);

    return 0;
}

