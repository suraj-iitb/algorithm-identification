#include<stdio.h>
#include<stdlib.h>

#define nMAX 2000000
#define AMAX 10000

void CountingSort(int A[], int B[], int k);

int n;

int main(){

  int *A, *B, i, k;

  /*要素数の入力*/
  scanf("%d", &n);

  /*A, Bのメモリの動的確保*/
  A = malloc((n + 1)* sizeof(int));
  B = malloc((n + 1)* sizeof(int));

  /*要素の入力*/
  for(i = 1; i <= n; i++)
    scanf("%d", &A[i]);

  /*最大の要素の判定*/
  k = A[1];
  for(i = 1; i <= n; i++)
    if(A[i] >=  k) k = A[i];

  /*CountingSort*/
  CountingSort(A, B, k);

  /*ソート後の配列の出力*/
  for(i = 1; i <= n; i++){
    if(i != n) printf("%d ", B[i]);
    else printf("%d", B[i]);
  }
  printf("\n");
  
  return 0;
}

void CountingSort(int A[], int B[], int k){
  int i, j, C[k + 1];
  
  for(i = 0; i <= k; i++)
    C[i] = 0;

  for(j = 1; j <= n; j++)
    C[A[j]]++;

  for(i = 1; i <= k; i++)
    C[i] = C[i] + C[i - 1];

  for(j = n; j > 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

