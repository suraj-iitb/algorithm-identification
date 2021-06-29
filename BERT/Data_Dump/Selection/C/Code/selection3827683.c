#include <stdio.h>
//選択ソート

//配列の要素を順番に出力
void trace(int A[],int N){
    int i;
    for(i = 0; i < N;i++){
        if(i > 0)printf(" ");//隣の要素の間に一つの空白を出力
        printf("%d",A[i]);
    }
    printf("\n");
}


void selectionSort(int A[], int N){
    int i , j, t;
    int min_j;
    int select_count = 0;

    for(i = 0; i < N; i++){
        min_j = i;
        for(j = i; j < N; j++){
            if(A[j] < A[min_j]) {
                min_j = j;
            }
        }
        t = A[i]; A[i] = A[min_j]; A[min_j] = t;
        if(i != min_j){
            select_count++;
        }
    }
    trace(A,N);
    printf("%d\n", select_count);
}
int main(){
    int N, i, j;
    int A[100];

    scanf("%d",&N);
    for(i = 0;i < N;i++){
        scanf("%d",&A[i]);
    }
    selectionSort(A,N);
    return 0;
}
