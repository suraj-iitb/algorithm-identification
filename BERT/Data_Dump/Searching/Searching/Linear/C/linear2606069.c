#include <stdio.h>

int main(void)
{
  int n, i, q, j;
  int S[10000];
  int T[500];
  int c = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
     scanf("%d", &S[i]);

  scanf("%d", &q);

  for(i = 0; i < q; i++)
    scanf("%d", &T[i]);

  for(i = 0; i < q; i++) {
    for(j = 0; j < n; j++) {
      if(S[j] == T[i]) {
        c++;
        break;
      }
    }
  }

  printf("%d\n", c);

  return 0;
}
