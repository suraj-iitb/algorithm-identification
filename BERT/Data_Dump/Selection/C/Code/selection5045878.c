#include <stdio.h>

#define MAX 100

void swap(int *x, int *y){//値を入れ替える関数
  int sw;
  sw = *x;
  *x = *y;
  *y = sw;
}

int selectionSort(int A[], int N){//選択ソート
  int i, j, sw=0, min;
  for(i=0; i<N-1; i++){
    min = i;
    for(j=i; j<N; j++){
      if(A[j]<A[min]) min=j;
    }
    swap(&A[i], &A[min]);
    if(i!=min) sw++;
  }
  return sw;//実行回数を戻す
}

int main(){
  int i, N, A[MAX], sortcount=0;

  scanf("%d", &N);

  for(i=0; i<N; i++) scanf("%d", &A[i]);

  sortcount = selectionSort(A, N);

  for(i=0; i<N; i++){//並び替えられた順に表示
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");

  printf("%d\n", sortcount);//回数を表示
  return 0;
}
