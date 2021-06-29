/*挿入ソートを実装したプログラム*/
#include <stdio.h>

#define ARY_MAX 100       /*入力の数列の最大の長さ*/

int main()
{
  int i, j, n, v, ary[ARY_MAX];

  scanf("%d", &n);

  for( i = 0; i<n; i++ )
    {
      scanf("%d", &ary[i]);

      if( i == n-1 )
	break;
    }

  /*挿入ソートを用いて昇順にソート*/
  for( i = 1; i<n; i++ )
    {
      /*各ステップでの途中結果を表示*/
      for( j = 0; j<n; j++ )
	{
	  printf("%d", ary[j]);
	  if( j != n-1 )
	    printf(" ");
	}
      printf("\n");

      v = ary[i];
      j = i-1;

      while( j>=0 && ary[j]>v )
	{
	  ary[j+1] = ary[j];
	  j--;
	}
      ary[j+1] = v;

    }

  for( j = 0; j<n; j++ )
    {
      printf("%d", ary[j]);

      if( j != n-1 )
	printf(" ");
    }
  printf("\n");
  return 0;
}

