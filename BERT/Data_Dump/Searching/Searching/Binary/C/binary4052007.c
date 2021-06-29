#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, n, q, *S, cnt = 0, num, left, right, mid;

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
      left = 0;
      right = n;

      while( left < right )
	{
	  mid = ( left + right )/2;

	  if( S[mid] == num )
	    {
	      cnt++;
	      break;
	    }
	  else if( S[mid] < num )
	    left = mid+1;
	  else
	    right = mid;
	}
    }

  printf("%d\n", cnt);

  return 0;
}

