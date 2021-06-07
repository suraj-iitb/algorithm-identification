#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define Q 50000

int main()
{
  int n, q;
  int S[N], T[Q];
  int i, j, cnt = 0;
  int left, right, mid;

  scanf("%d", &n);
  if(n > N) exit(1);
  for(i = 0 ; i < n ; i++)
    {
      scanf("%d", &S[i]);
      if(S[i] < 0 || 10e9 < S[i]) exit(2);
      if(i > 0 && (S[i - 1] > S[i])) exit(3);
    }
  
  scanf("%d", &q);
  if(q > Q) exit(4);
  for(i = 0 ; i < q ; i++)
    {
      scanf("%d", &T[i]);
      if(T[i] < 0 || 10e9 < T[i]) exit(5);
    }

  for(i = 0 ; i < q - 1 ; i++)
    {
      for(j = i + 1 ; j < q ; j++)
	{
	  if(T[i] == T[j]) exit(6);
	}
    }

  for(i = 0 ; i < q ; i++)
    {
      left = 0;
      right = n;
      
      while(left < right)
	{
	  mid = (left + right) / 2;
	  if(T[i] == S[mid])
	    {
	      cnt++;
	      break;
	    }
	  if(T[i] > S[mid]) left = mid + 1;
	  else if(T[i] < S[mid]) right = mid;
	}
    }

  printf("%d\n", cnt);

  return 0;
}

