#include <stdio.h>

#define nMAX 10000
#define qMAX 500

int q, t[qMAX], n, s[nMAX];

int main()
{
  int i = 0, j = 0, c = 0;

  scanf("%d", &n);
  while (i != n)
  {
    scanf("%d", &s[i]);
    i++;
  }

  i = 0;
  scanf("%d", &q);
  while (i != q)
  {
    scanf("%d", &t[i]);
    i++;
  }

  for (i = 0; i < q; i++)
  {
    j = 0;
    while (n != j)
    {
      if (t[i] == s[j])
      {
        c++;
        break;
      }
      j++;
    }
  }

  printf("%d\n", c);
  return 0;
}

