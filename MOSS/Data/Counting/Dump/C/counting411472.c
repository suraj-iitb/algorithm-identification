#include <stdio.h>

void Counting_Sort(int A[], int B[], int n, int k) {
  int i, j;
  int C[10001];
  for(i = 0; i <= k; ++i)
    C[i] = 0;
  for(j = 1; j <= n; ++j)
    C[A[j]] = C[A[j]]+1;
  /* C[i] now contains the number of elements equal to i */
  for(i = 1; i <= k; ++i)
    C[i] = C[i] + C[i-1];
  /* C[i] now contains the number of elements less than or equal to i */
  for(j = n; j >= 1; --j) {
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]]-1;
  }
}
int A[2000001], B[2000001];
int main() {
  int i;
  int n, k;
  k = 0;
  scanf("%d", &n);
  for(i = 1; i <= n; ++i) {
    scanf("%d", A+i);
    k = A[i] > k ? A[i] : k;
  }
  Counting_Sort(A,B,n,k);
  for(i = 1; i <= n; ++i) {
    if(i-1) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");
  return 0;
}
