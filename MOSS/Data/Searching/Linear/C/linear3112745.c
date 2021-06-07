#include <stdio.h>

#define N_MAX 10000
#define Q_MAX 500

int main(void) {
  int S[N_MAX+1];
  int T[Q_MAX];
  int n, q, i, j, C = 0;

  scanf("%d", &n);
  for(i=0; i<n; ++i) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i=0; i<q; ++i) {
    scanf("%d", &T[i]);
  }

  for(i=0; i<q; ++i) {
    S[n] = T[i];

    for(j=0; j<n; ++j) {
      if(S[j] == T[i]) break;
    }

    if(j != n) ++C;
  }

  printf("%d\n", C);

  return 0;
}

