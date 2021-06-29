#include<stdio.h>
#include<stdlib.h>
#define nmax 10000
#define qmax 500

void linearSearch(int);

int T[qmax],q,count=0;
int judge[qmax];

int main()
{
  int n;
  int S[nmax],i;

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ )
    {
      scanf("%d",&S[i]);
    }

 scanf("%d",&q);

  for( i = 0 ; i < q ; i++ )
    {
      scanf("%d",&T[i]);
    }

  for( i = 0 ; i < n ; i++ )
    {
      linearSearch(S[i]);
    }
  printf("%d\n",count);

  return 0;
}


void linearSearch(int x)
{
  int i,j;
  int flag = 1;
  for(i = 0 ; i < q ; i++ )
    {
      if( T[i] == x )
	{
	for( j = 0 ; j < count ; j++ )
	  {
	    if( judge[j] == x )
	      flag = 0;
	  }
      if( flag == 1 )
	{
	judge[j] = x;
	count++;
	}
}

     }
}
