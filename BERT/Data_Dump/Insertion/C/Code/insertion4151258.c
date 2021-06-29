// 挿入ソート
// O(n^2)　安定

#include <stdio.h>

void disp(int A[], int N){
    int i;

    // 表示
    for(i = 0; i < N; i++){
        if (i == 0) printf("%d", A[i]);
        else printf(" %d", A[i]);
    }

    // 改行を出力
    printf("\n");
}

void insertSort(int A[], int N) {
    int i, j, v;

    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;

        while((j >= 0)&&(A[j] > v)){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        disp(A, N);
    }
}

int main(){

    int A[100];
    int N, i;

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    disp(A, N);

    insertSort(A, N);

    return 0;
}
