#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n, q, i, j;
  int *S, *T;
  int found;

  scanf("%d", &n);
  S = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) scanf("%d", &S[i]);

  scanf("%d", &q);
  T = (int *)malloc(sizeof(int) * q);
  for (i = 0; i < q; i++) scanf("%d", &T[i]);

  found = 0;
  for (i = 0; i < q; i++) {
    for (j = 0; j < n; j++) {
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
