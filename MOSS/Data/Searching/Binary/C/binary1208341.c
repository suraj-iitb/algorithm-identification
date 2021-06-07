#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n, q, i, j;
  int *S, *T;
  int found;
  int st, ed, center;

  scanf("%d", &n);
  S = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) scanf("%d", &S[i]);

  scanf("%d", &q);
  T = (int *)malloc(sizeof(int) * q);
  for (i = 0; i < q; i++) scanf("%d", &T[i]);

  found = 0;
  for (i = 0; i < q; i++) {
    st = 0;
    ed = n - 1;
    while (1) {
      center = st + (ed-st)/2;
      if (ed - st < 20) break;
      if (S[center] > T[i]) ed = center;
      else if (S[center] < T[i]) st = center;
      else break;
    }
    for (j = st; j <= ed; j++) {
      if (S[j] == T[i]) {
	found++;
	break;
      }
    }
  }

  printf("%d\n", found);

  free(S);
  free(T);

  return 0;
}
