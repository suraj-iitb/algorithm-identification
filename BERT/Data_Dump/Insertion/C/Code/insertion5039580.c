#include <stdio.h>

#define MAX 100

void trace(int A[], int N){//配列の要素を順番に出力する関数
  int i;
  for(i=0; i<N; i++){
    if(i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void swap(int *x, int *y){//値を入れ替える関数
  int sw;
  sw = *x;
  *x = *y;
  *y = sw;
}

void insertionSort(int A[], int N){//挿入ソート(昇順)
  int i, v, j;
  for(i=1; i<N; i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){//順番が正しくない間のみ実行される
      swap(&A[j], &A[j+1]);//隣り合う値を入れ替える
      j--;//番号を更新
    }
    trace(A, N);
  }
}

int main(){
  int N, i;
  int A[MAX];

  scanf("%d", &N);
  for(i=0; i<N;i++) scanf("%d", &A[i]);
  trace(A, N);
  insertionSort(A, N);
  return 0;
}
