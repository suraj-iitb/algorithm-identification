#include <stdio.h>

int main(void)
{
  int n[10000], q[500], n1, q1, i, j, k = 0;
  scanf("%d", &n1);
  for (i = 0; i < n1; i++)  {
    scanf("%d", &n[i]);
  }
  scanf("%d", &q1);
  for (i = 0; i < q1; i++)  {
    scanf("%d", &q[i]);
  }

  for (i = 0; i < q1; i++)  {
    j = 0;
    while (n[j] != q[i])  {
      if (j == n1)  {
        break;
      }
      j++;
    }
    // printf("j = %d\n", j);
    if (j != n1)  {
      k++;
    }
  }

  printf("%d\n", k);

  return 0;
}
