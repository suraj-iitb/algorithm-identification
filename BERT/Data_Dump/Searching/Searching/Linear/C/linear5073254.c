#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define Q 500

int main()
{
  int n, q;
  int S[N], T[Q];
  int i, j, cnt = 0;

  scanf("%d", &n);
  if(n > N) exit(1);
  for(i = 0 ; i < n ; i++)
    {
      scanf("%d", &S[i]);
      if(S[i] < 0 || 10e9 < S[i]) exit(2);
    }
  
  scanf("%d", &q);
  if(q > Q) exit(3);
  for(i = 0 ; i < q ; i++)
    {
      scanf("%d", &T[i]);
      if(T[i] < 0 || 10e9 < T[i]) exit(4);
    }

  for(i = 0 ; i < q - 1 ; i++)
    {
      for(j = i + 1 ; j < q ; j++)
	{
	  if(T[i] == T[j]) exit(5);
	}
    }

  for(i = 0 ; i < q ; i++)
    {
      for(j = 0 ; j < n ; j++)
	{
	  if(T[i] == S[j])
	    {
	      cnt++;
	      break;
	    }
	}
    }

  printf("%d\n", cnt);

  return 0;
}

