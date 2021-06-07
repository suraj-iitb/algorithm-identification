#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j, n, q, *S, cnt = 0, num;

  scanf("%d", &n);

  /* n個の整数を含む数列Sを格納する配列を動的に確保 */
  S = (int *)malloc( sizeof(int) * n );

  for( i = 0; i<n; i++ )
    scanf("%d", &S[i]);

  scanf("%d", &q);

  for( i = 0; i<q; i++ )
    {
      /* Tの数字がSに含まれる個数を数える */
      scanf("%d", &num);
      for( j = 0; j<n; j++ )
	{
	  if( num == S[j] )
	    {
	      cnt++;
	      break;
	    }
	}
    }

  printf("%d\n", cnt);

  return 0;
}

