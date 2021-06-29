// Counting Sort
#include <stdio.h>
#include <stdlib.h>

#define MAX 2000000

void CountingSort(); // 計数ソートを実施する関数

int C[MAX]; // 配列Aの各要素が何回現れるか数える配列

int main(){
  int i, n, *A, *B;

  // 配列Aの入力
  scanf("%d", &n);

  A = malloc(sizeof(int) * n + 1);
  B = malloc(sizeof(int) * n + 1);
  
  for(i=1; i <= n; i++){
    scanf("%d", &A[i]);
  }

  CountingSort(A, B, n); // 計数ソートの実施

  // 結果を出力
  for(i=1; i <= n; i++){
    if(i != 1)printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");
  
  return 0;
}

void CountingSort(int *A, int *B, int n){
  int i;

  // カウンタ配列を初期化
  for(i=0; i < MAX; i++){
    C[i] = 0;
  }
  
  // C[i]にiの出現数を記録する
  for(i=1; i <= n; i++){
    C[A[i]]++;
  }

  // C[i]にi以下の数の出現数を記録する(配列Cの要素数1から昇順に累積和をとる)
  for(i=1; i < MAX; i++){
    C[i] = C[i] + C[i-1];
  }

  // 配列Aの要素を出力配列Bに順にコピーしていく
  for(i=n; i > 0; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}

