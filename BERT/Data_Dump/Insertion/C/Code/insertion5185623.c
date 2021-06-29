#include <stdio.h>
#include <stdlib.h>

int main() {

  short N;
  scanf("%hu", &N);

  long long* sequence = (long long*)malloc(N * sizeof(long long));
  
  for (short i = 0; i < N; ++i) {
    scanf("%lld", &sequence[i]);
  }

  for (short i = 0; i < N; ++i) {
      if (i == N - 1) {
        printf("%lld", sequence[i]);
      } else {
        printf("%lld ", sequence[i]);
      }
    }
    printf("\n");

  for (short i = 1; i < N; ++i) {

    int key = sequence[i];
    short j = i - 1;

    while (j >= 0 && sequence[j] > key) {
      sequence[j+1] = sequence[j];
      --j;
    }

    sequence[j+1] = key;

    for (short i = 0; i < N; ++i) {
      if (i == N - 1) {
        printf("%lld", sequence[i]);
      } else {
        printf("%lld ", sequence[i]);
      }
    }
    printf("\n");

  }

  return 0;
}
