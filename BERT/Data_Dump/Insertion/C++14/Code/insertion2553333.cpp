#include <cstdio>

static const size_t N_MAX = 100;

size_t N;
int A[N_MAX];

void inspect() {
  for (size_t i = 0; i < N - 1; i++)
    printf("%d ", A[i]);
  printf("%d\n", A[N-1]);
}

int main() {
  scanf("%zu", &N);
  for (size_t i = 0; i < N; i++)
    scanf("%d", &A[i]);
  inspect();
  for (size_t i = 1; i < N; i++) {
    auto v = A[i];
    auto j = i;
    while (j >= 1 && A[j-1] > v) {
      A[j] = A[j-1];
      j--;
    }
    A[j] = v;
    inspect();
  }
  return 0;
}
