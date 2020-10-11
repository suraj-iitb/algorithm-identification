#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main() {
    unsigned short *A, *B;   //unsignedを付けることで符号なしを表す。(係数ソートの条件は0以上のため)
    
    int C[VMAX+ 1];
    int n, i, j;
    scanf("%d", &n);
    
    A = malloc(sizeof(short) * n + 1);
    B = malloc(sizeof(short) * n + 1);
    
    //count用配列の初期化
    for ( i = 0; i <= VMAX; i++ ) C[i] = 0;
    
    //配列Aを入力、Aで出てきた数字の回数をCに保存
    for ( i = 0; i < n; i++ ) {
        scanf("%hu", &A[i + 1]);
        C[A[i + 1]]++;
    }
    
    //Cに保存した数字を足し合わせる
    for ( i =  1; i <= VMAX; i++ ) C[i] = C[i] + C[i -1];
    
    //配列Bにソートした値を格納する
    for ( j = 1; j <= n; j++ ) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    
    for ( i = 1; i <= n; i++ ) {
        if ( i > 1 ) printf(" ");
        printf("%d", B[i]);
    } 
    printf("\n");
    
    return 0;
}
