#include<stdio.h>

int main(){
    int n,A[4][2000002],i,j;//A0 初期配列 A1 数値ごとの要素数 A2 数値ごとの残りストック A3 ソート結果

    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&A[0][i]);
        A[1][A[0][i]]++;
    }
    int num=0;
    for(i=0;i<10000;i++){
        A[2][i]=num+A[1][i];
        num=A[2][i];
    }
    for(i=n;i>=0;i--){
        A[3][A[2][A[0][i]]]=A[0][i];
        A[2][A[0][i]]--;
    }
    for(i=1;i<=n;i++){
        if(i-1){
            printf(" ");
        }
        printf("%d",A[3][i]);
    }
    printf("\n");

    return 0;
}
