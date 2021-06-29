#include <stdio.h>

#define nMAX 100000
#define qMAX 50000

int main()
{
  int q, t[qMAX], n, s[nMAX];
  int l, r, m, c = 0;
  int i = 0;

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

  i = 0;

  while (i != q)
  {
    l = 0;
    r = n;
    while (l < r)
    {
      m = (r + l) / 2;
      if (s[m] == t[i])
      {
        c++;
        break;
      }
      else if (t[i] < s[m])
      {
        r = m;
      }
      else
      {
        l = m + 1;
      }
    }
    i++;
  }

  printf("%d\n", c);
  return 0;
}

