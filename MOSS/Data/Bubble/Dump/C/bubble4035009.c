/*
  バブルソート
*/
#include <stdio.h>

void swap(int *, int *);

int main()
{
  int i, count = 0, flag = 1, n, ary[100];

  scanf("%d", &n);
  for( i = 0; i<n; i++ )
    scanf("%d", &ary[i]);

  /*バブルソートで昇順にソート*/
  while( flag )
    {
      flag = 0;

      for( i = n-1; i>=1; i-- )
	{
	  if( ary[i] < ary[i-1] )
	    {
	      swap(&ary[i], &ary[i-1]);
	      flag = 1;
	      count++;
	    }
	}
    }

  for( i = 0; i<n; i++ )
    {
      printf("%d", ary[i]);

      if( i != n-1 )
        printf(" ");
    }
  printf("\n%d\n", count);

  return 0;
}

/*引数として与えられた整数 a,b を交換する関数*/
void swap(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

