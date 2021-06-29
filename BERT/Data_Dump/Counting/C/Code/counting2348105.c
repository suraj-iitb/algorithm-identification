#include <stdio.h>
#include <string.h>

#define MAX_N 2000000

int n, A[MAX_N+1];
int B[MAX_N+1], C[MAX_N+1];
int k;

void countingSort() {
  int i;
  memset(C, 0, sizeof(C));
  for(i = 0; i < n; i++) C[A[i]]++;
  for(i = 1; i <= k; i++) C[i] += C[i-1];
  for(i = n-1; i >= 0; i--) B[C[A[i]]--] = A[i];
}

int main() {
  int i;

  scanf("%d", &n);
  k = 0;
  for(i = 0; i < n; i++) {
    scanf("%d", A+i);
    if(A[i] > k) k = A[i];
  }
  countingSort();
  for(i = 1; i <= n; i++) {
    if(i > 1) putchar(' ');
    printf("%d", B[i]);
  }
  puts("");

  return 0;
}
