#include <stdio.h>
#define MAX 2000001
#define VMAX 10000

int A[MAX], B[MAX];

void CountingSort(int *A, int *B, int k, int n){
  int C[VMAX+1];
  int i, j;

  for(i=0; i<=k; i++){
    C[i]=0;
  }

  /* C[i] に i の出現数を記録する */
  for(j=1; j<=n; j++){
    C[A[j]]++;
  }

  /* C[i] に i 以下の数の出現数を記録する*/
  for(i=1; i<=k; i++){
    C[i] = C[i] + C[i-1];
  }

  for(j=n; j>0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main(){
  int n, i;

  scanf("%d", &n);

  for(i=1; i<=n; i++){
    scanf("%d", &A[i]);
  }

  CountingSort(A, B, 10000, n);

  for(i=1; i<=n; i++){
    if(i != 1){
      printf(" ");
    }
    printf("%d", B[i]);
  }

  printf("\n");

  return 0;

}
