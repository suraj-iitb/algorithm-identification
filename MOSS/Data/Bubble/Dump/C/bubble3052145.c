#include <stdio.h>

/*
バブルソート
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

int bubbleSort(int A[], int n){
    int flag = 1;
    int cnt = 0;
    while (flag) {
        flag = 0;
        for (int j = n - 1; j > 0; j--){
            if (A[j] < A[j-1]){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                cnt++;
            }
        }
    }

    return cnt;
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

    // 挿入ソートのロジック部分の関数
    int cnt = bubbleSort(A, n);
    
    // 出力用の関数
    trace(A, n);

    // 交換回数
    printf("%d\n", cnt);

    return 0;
}

