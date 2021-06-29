
#include <stdio.h>
#include <stdlib.h>

#define NMIN 1
#define NMAX 2000000
#define AMIN 0
#define AMAX 10000

void CountingSort(int, int *, int *, int k);
  
int main() {
  int n;
  int *A; // input
  int *B; // output
  int k=0; // maximum in A
  int i; // counter

  scanf("%d", &n);
  if(n<NMIN || NMAX<n) {
    fprintf(stderr,"%d <= n <= %d\n", NMIN, NMAX);
    exit(8);
  }
  A = (int *)malloc(sizeof(int)*(n+1));
  B = (int *)malloc(sizeof(int)*(n+1));
  for(i=1; i<=n; i++) {
    scanf("%d", &A[i]);
    if(A[i]<AMIN || AMAX<A[i]) {
      fprintf(stderr,"%d <= Ai <= %d\n", AMIN, AMAX);
      exit(8);
    }
    if(k<A[i])
      k = A[i];
  }

  CountingSort(n,A,B,k);

  for(i=1; i<=n; i++) {
    printf("%d", B[i]);
    if(i==n)
      printf("\n");
    else
      printf(" ");
  }
  
  free(A);
  free(B);
  
  return 0;
}

void CountingSort(int n, int *A, int *B, int k) {
  int *C;
  int i, j; // counter

  C = (int *)malloc(sizeof(int)*(k+1));
  for(i=0; i<=k; i++)
    C[i] = 0;
  
  for(j=1; j<=n; j++)
    C[A[j]]++;
  for(i=1; i<=k; i++)
    C[i] = C[i] + C[i-1];
  for(j=n; j>=1; j--) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
    }
  
  free(C);
}

