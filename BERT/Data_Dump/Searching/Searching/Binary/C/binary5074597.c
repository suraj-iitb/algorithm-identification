#include<stdio.h>

int main()
{
  int n, q, s[100000], t[50000], i, cnt=0, l, m, r;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i = 0; i < q; i++)
    scanf("%d", &t[i]);

  for(i = 0; i < q; i++)
  {
    l = 0;
    r = n;

    while(l < r)
    {
      m = (l+r) / 2;

      if(s[m] > t[i])
      {
        r = m;
      }

      else if(s[m] < t[i])
      {
        l = m + 1;
      }

      else if(s[m] == t[i])
      {
        cnt++;
        break;
      }
    }
  }

  printf("%d\n", cnt);

  return 0;
}

