#include<stdio.h>
#include<stdlib.h>

int linearSearch(int);
int S[10000],T[10000];
int n,q;

int main()
{
  int c=0,i;

  scanf("%d",&n);
  

  for(i = 0;i < n;i++)
    {
      scanf("%d",&S[i]);

    }
  scanf("%d",&q);

  for(i = 0;i < q;i++)
    {
      scanf("%d",&T[i]);
      if(i > 0)
	{
	  if(T[i-1] == T[i])exit(2);
	}
      c += linearSearch(T[i]);
    }

  printf("%d\n",c);

  return 0;
}

int linearSearch(int key)
{
  int i=0;

 
      while(S[i] != key)
	{
	  i++;
	  if(i == n) return 0;
	}
      return 1;
    
}

