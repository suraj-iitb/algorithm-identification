#include <stdio.h>

#define N 2000000
#define M 10000

void CountingSort(int *, int *, int);
int n;
int main() {
  int A[N],B[N],i;

  scanf("%d", &n);
  for (i=1; i<=n;i++){
    scanf("%d", &A[i]);
  }

  CountingSort(A,B,10000);

  for (i=1;i<=n;i++){

    if(i==1) printf("%d", B[i]);
    else printf(" %d", B[i]);
  }
  printf("\n");

  return 0;
}

void CountingSort(int *A, int *B, int k){
  int C[M],i,j;

  for (i=0;i<=k;i++){
    C[i] = 0;
  }

  for (j=1;j<=n;j++){
    C[A[j]]++;
  }

  for (i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }

  for (j=n;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
