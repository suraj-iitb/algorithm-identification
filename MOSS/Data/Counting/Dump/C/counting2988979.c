#include <stdio.h>
#include <stdlib.h>
#define VMAX 2000001

void CountingSort(int[],int);

int C[VMAX + 1];
int B[VMAX + 1];

int main(){
    int *A,n;

    scanf("%d",&n);

    A = malloc(sizeof(int) * n + 1);

    for(int i = 0;i < n;i++)scanf("%d",&A[i]);

    CountingSort(A,n);

    for(int i = 1;i <= n;i++){
        printf("%d",B[i]);
        if(i < n)printf(" ");
    }
    printf("\n");

    return 0;
}

void CountingSort(int A[VMAX],int n){
    //C初期化
    for(int i = 0;i < VMAX;i++)C[i] = 0;
    //CのA[i]番目にA[i]が現れる回数をカウント
    for(int i = 0;i < n;i++)C[A[i]]++;
    //累積和を求める
    for(int i = 1;i < VMAX;i++)C[i] = C[i] + C[i - 1];

    for(int i = 0;i < n;i++){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}


