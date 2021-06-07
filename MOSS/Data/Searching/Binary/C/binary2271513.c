#include <stdio.h>

int main() {
  int n, q, C = 0;
  int S[100000], T[50000];
  int i, j;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", S+i);

  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", T+i);

  for(i = 0; i < q; i++) {
    int lb = 0, ub = n;
    while(lb + 1 < ub) {
      int mb = (lb + ub) / 2;
      if(T[i] < S[mb]) ub = mb;
      else lb = mb;
    }
    if(T[i] == S[lb]) C++;
  }

  printf("%d\n", C);

  return 0;
}
