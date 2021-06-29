// Selection Sort  選択ソート

#include <stdio.h>

// 標準出力にarrayを出力する関数
void printArray(int *A, int N){
    for(int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if(i < N-1) printf(" ");  // 最後の要素以外は空白を挟む
    }
    printf("\n");
}

// Selection Sort  選択ソート
int selectionSort(int A[], int N){
    int count = 0;
    for (int i=0; i<N; i++){
        int minj = i;  // 最小値のidx
        for (int j=i; j<N; j++){
            if (A[j] <A[minj])
                minj = j;
        }
        if (minj != i){
            // [minj]の要素と[i]の要素を交換する
            int tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;

            count++;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    const int MAX = 100;
    int A[MAX];
    int N;
    int count;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    count = selectionSort(A, N);

    printArray(A, N);
    printf("%d\n", count);

    return 0;
}

