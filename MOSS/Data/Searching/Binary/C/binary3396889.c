/*--------------------------*/
// p.122
// 5.3 二分探索
//
// ALDS1_4_B: Binary Search
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

int A[1000000];
int n;

/* 二分探索 */
int binarySearch(int key){
    int left  = 0;
    int right = n;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if (key == A[mid]) return 1; // True: keyを発見できた
        if (key > A[mid]) left = mid + 1;   // 後半を探索
        else if (key < A[mid]) right = mid; // 前半を探索
    }
    return 0; // False: keyを発見できない
}

int main(){
    int i, q, k, sum=0;

    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for(i = 0 ; i < q ; i++){
        scanf("%d", &k);
        if( binarySearch(k) ) sum++;
    }

    printf("%d\n", sum);
    return 0;
}


