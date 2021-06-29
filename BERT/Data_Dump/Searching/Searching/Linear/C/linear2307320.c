#include<stdio.h>

int main()
{
  int n, q, i, j, cnt=0;
  int s[10001], t[500];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    {
      scanf("%d", &s[i]);
    }
  scanf("%d", &q);
  for(i=0; i<q; i++)
    {
      scanf("%d", &t[i]);
    }

  for(i=0; i<q; i++)
    {
      j=0;
      s[n] = t[i];
      while(s[j] != t[i])
	{
	  j++;
	}
      if(j == n)
	{
	  //intf("%d not found\n", t[i]);
	}
      else
	{
	  cnt++;
	}
    }

  printf("%d\n", cnt);
  
  return 0;
}
