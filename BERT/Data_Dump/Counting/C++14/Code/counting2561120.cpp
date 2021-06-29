#include <cstdio>

const int kMaxN = 2000000;
const int kMaxAi = 10000;

void CountingSort (int A[], int B[], int k, int n) {
  int i;
  int C[k + 1] = {};
  for (i = 0; i < n; ++i) { ++C[A[i]]; }
  for (i = 1; i < k + 1; ++i) { C[i] += C[i - 1]; }
  for (i = n - 1; i > -1; --i) {
    B[C[A[i]] - 1] = A[i];
    --C[A[i]];
  }
}

int main() {
  int n, i;
  std::scanf("%d", &n);
  int A[n], B[n];
  for (i = 0; i < n; ++i) { std::scanf("%d", &A[i]); }
  CountingSort(A, B, kMaxAi, n);
  for (i = 0; i < n - 1; ++i) { std::printf("%d ", B[i]); }
  std::printf("%d\n", B[n - 1]);
  return 0;
}
