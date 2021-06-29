#include <stdio.h>
#include <stdlib.h>

void CountingSort(int  *A, int *B, int k);

int n;

int main() {

  int i;
  int k = 0;
  int *pA, *pB;

  scanf("%d", &n);

  pA = (int *)malloc((n+1) * sizeof(int));
  pB = (int *)malloc((n+1) * sizeof(int));
  
  for(i=1; i<=n; i++){
    scanf("%d", &pA[i]);
    if(k < pA[i]) k = pA[i];
}
  
  CountingSort(pA,pB,k);

  
  return 0;
}

void CountingSort(int *A, int *B, int k){

  int i,j;
  int C[10001];

  //  C = (int *)malloc(n * sizeof(int));

  for(i=0; i<=k; i++)
    C[i] = 0;

  for(j=1; j<=n; j++)
    C[A[j]]++;
  
  
  for(i=1; i<=k; i++)
    C[i] = C[i] + C[i-1];

  for(j=n; j>=1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1; i<=n; i++){
    if(i == n) printf("%d\n", B[i]);
    else printf("%d ", B[i]);
  }
  
}

