#include<stdio.h>
#define MAX 2000001

int A[MAX];     //実際の数字(0~10000)が格納される配列
int C[10001];   //配列Aの数字の数を記録する配列 ( C[0] : A[]に含まれる"0"の数)
int n;          //配列Aの長さを表す。A[n]
int B[MAX];
int i,j;

void CountingSort(int A[],int B[],int k){
    for(i=0;i<k;i++) C[i] = 0;       //C配列の初期化

    for(j=1;j<n+1;j++) C[A[j]]++;      //C[i]にiの出現数を記録

    /*for(i=0;i<n;i++){
        printf("%d ",C[i]);
    }
    printf("\n");*/

    for(i=1;i<k;i++) C[i] = C[i] + C[i-1];   //後ろの奴の合計数を足してく

    /*for(i=0;i<n;i++){
        printf("%d ",C[i]);
    }
    printf("\n");*/

    for(j=n;j>0;j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main(){
    scanf("%d",&n);
    for(i=1;i<n+1;i++){
        scanf("%d",&A[i]);
    }
    
    CountingSort(A,B,10001);
    for(i=1;i<n+1;i++){
        printf("%d",B[i]);
        if(i != n)printf(" ");
    }
    printf("\n");

    return 0;
}
