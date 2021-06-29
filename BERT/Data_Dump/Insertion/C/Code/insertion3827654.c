#include <stdio.h>
//挿入ソート
//配列の要素を順番に出力
void trace(int A[],int N){
    int i;
    for(i = 0; i < N;i++){
        if(i > 0){
            printf(" ");//隣の要素の間に一つの空白を出力
        }
        printf("%d",A[i]);
    }
    printf("\n");
}

//挿入ソート
void insertionSort(int A[], int N){
    int j, i, v;
    //jは
    for(i = 1;i < N;i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];//この行が意味わからん　わかった自分でかける自信がない
            j--;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}

int main(){
    int N, i, j;
    int A[100];

    scanf("%d",&N);
    for(i = 0;i < N;i++){
        scanf("%d",&A[i]);
    }
    trace(A,N);
    insertionSort(A,N);
    return 0;
}
