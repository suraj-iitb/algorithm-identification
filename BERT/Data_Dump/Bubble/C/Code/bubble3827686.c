#include <stdio.h>
//バブルソート
//配列の要素を順番に出力
void trace(int A[],int N){
    int i;
    for(i = 0; i < N;i++){
        if(i > 0)printf(" ");//隣の要素の間に一つの空白を出力
        printf("%d",A[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int N){
    int i , j, t;
    int bubble_count = 0;

    for(i = 0;i < N-1;i++){
        for(j = N-1; i < j;j--){
            if(A[j] < A[j - 1]){
                t = A[j]; A[j] = A[j - 1]; A[j - 1] = t;
                bubble_count++;
            }
        }
    }
    trace(A, N);
    printf("%d\n", bubble_count);
}
int main(){
    int N, i;
    int A[100];

    scanf("%d",&N);
    for(i = 0;i < N;i++){
        scanf("%d",&A[i]);
    }
    bubbleSort(A,N);
    return 0;
}
