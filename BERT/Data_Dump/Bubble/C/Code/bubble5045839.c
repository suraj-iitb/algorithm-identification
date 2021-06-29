#include <stdio.h>

#define MAX 100

void swap(int *a, int *b){//値を入れ替える関数
  int sw;
  sw = *a;
  *a = *b;
  *b = sw;
}

int bubbleSort(int A[], int N){//バブルソート
  int sw=0, j, flag=1;
  while(flag){
    flag = 0;
    for(j=N-1; j>=1; j--){
      if(A[j]<A[j-1]){
        swap(&A[j], &A[j-1]);
        flag = 1;
        sw++;
      }
    }
  }
  return sw;//実行回数を戻す
}

int main(){
  int i, N, A[MAX], sortcount=0;

  scanf("%d", &N);

  for(i=0; i<N; i++) scanf("%d", &A[i]);

  sortcount = bubbleSort(A, N);

  for(i=0; i<N; i++){//並び替えられた順に表示
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");

  printf("%d\n", sortcount);//回数を表示
  return 0;
}
