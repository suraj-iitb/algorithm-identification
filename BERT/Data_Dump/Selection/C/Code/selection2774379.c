#include<stdio.h>

int main(void) {
    
    // 変数定義
    int n;
    int array[100] = {};
    int i, j, minj, count, flag;

    // 入力の読み込み
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // 選択ソート
    count = 0;
    flag = 0;
    for (i = 0; i < n; i++) {
        minj = i;
        for (j = i; j < n; j++) {
            // 配列要素の中で最小値を見つけ、indexをminjに保持
            if (array[j] < array[minj]) {
                minj = j;
            }
        }

        if (minj != i) {
            // 要素を交換する
             int tmp = array[i];
            array[i] = array[minj];
            array[minj] = tmp;

            // 交換回数をカウントアップ
            count++;
        }
    }

    // 結果を表示
    for (i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i != (n-1)) printf(" ");
    }
    printf("\n%d\n", count);

    return 0;
}

