#include <cstdio>
#include <utility>

static const size_t N_MAX = 100;

int main() {
  size_t N;
  int A[N_MAX];
  scanf("%zu", &N);
  for (size_t i = 0; i < N; i++)
    scanf("%d", &A[i]);
  int c = 0;
  for (size_t i = 1; i < N; i++)
    for (size_t j = i; j > 0 && A[j] < A[j-1]; j--, c++)
      std::swap(A[j], A[j-1]);
  for (size_t i = 0; i < N - 1; i++)
    printf("%d ", A[i]);
  printf("%d\n", A[N-1]);
  printf("%d\n", c);
  return 0;
}
