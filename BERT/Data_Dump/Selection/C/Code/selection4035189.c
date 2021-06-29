/*
  選択ソート
*/
#include <stdio.h>

void swap(int *, int *);

int main()
{
  int i, j, minj,  count = 0, n, ary[100];

  scanf("%d", &n);
  for( i = 0; i<n; i++ )
    scanf("%d", &ary[i]);

  /*選択ソートを用いて昇順にソート*/
  for( i = 0; i<n; i++ )
    {
      minj = i;

      for( j = i+1; j<n; j++ )
	{
	  if( ary[j] < ary[minj] )
	    {
	      minj = j;
	    }
	}
      if( minj != i )
	{
	  swap(&ary[i], &ary[minj]);
	  count++;
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

