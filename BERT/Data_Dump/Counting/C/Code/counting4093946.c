#include<stdio.h>

int n;
int A[2000001],B[2000001];

void CountingSort(int k);

int main(){
  int i;
  int max = 0;

  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%d", &A[i]);
    if(max < A[i]) max = A[i];
  }

  CountingSort(max);

  for(i = 1; i <= n; i++){
    printf("%d", B[i]);
    if(i < n) printf(" ");
  }
  printf("\n");
  
  return 0;
}

void CountingSort(int k){
  int i, j;
  int C[10000];

  for(i = 0; i <= k; i++){
    C[i] = 0;
  }

  /* C[i] に i の出現数を記録する */
  for(j = 1; j <= n; j++){
    C[A[j]]++;
  }

  /* C[i] に i 以下の数の出現数を記録する*/
  for(i = 1; i <= k; i++){
    C[i] = C[i] + C[i - 1];
  }

  for(j = n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}


