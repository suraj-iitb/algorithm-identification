/*--------------------------*/
// p.119
// 5.2 線形探索
//
// ALDS1_4_A: Linear Search
//
// 配列Aに含まれる，配列Sの要素の個数を出力するプログラム
//
// 入力例:
//     5 (n)
//     1 2 3 4 5 (A: nコの配列)
//     3 (q)
//     3 4 1 (T: qコの配列)
// 出力例:
//     3
//
/*--------------------------*/

#include<stdio.h>

// 線形探索
int linearSearch(int A[], int n, int key){
    int i = 0;
    A[n] = key; // 配列Aの末尾要素を「番兵」としてkeyにする．
    while(A[i] != key) i++;
    return i != n;
}


int main(){
    int i, n, A[10001], q, key;
    int sum = 0;

    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for(i = 0 ; i < q ; i++){
        scanf("%d", &key);
        if (linearSearch(A, n, key)){
            sum++; // 配列Aにkeyがあれば，sumをインクリメント
        }
    }

    printf("%d\n", sum); // 配列Aに含まれる，配列Sの要素の個数を出力する
    return 0;
}
