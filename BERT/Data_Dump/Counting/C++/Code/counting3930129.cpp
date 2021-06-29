#include<cstdio>
#define MAXIMUM 10001

int C[MAXIMUM] = {0};

int main() {
  int n;
  scanf("%d", &n);

  int A[n] = {0};
  int B[n] = {0};
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);

  for (int i = 0; i < n; i++) C[A[i]]++;
  for (int i = 1; i < MAXIMUM; i++) C[i] += C[i - 1];
  for (int i = n - 1; 0 <= i; i--) {
    B[C[A[i]] - 1] = A[i];
    C[A[i]]--;
  }

  for (int i = 0; i < n; i++) {
    if (i != 0) printf(" ");
    printf("%d", B[i]);
  }

  printf("\n");

  return 0;
}

