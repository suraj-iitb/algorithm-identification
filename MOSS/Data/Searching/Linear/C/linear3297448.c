#include <stdio.h>

int serch(int [],int);

int n,q;

int main()
{
  int a,i,S[10000],T[500],count = 0;

  scanf("%d",&n);
  for(i = 0;i < n;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  for(i = 0;i < q;i++)
    {
      scanf("%d",&T[i]);
      a = serch(S,T[i]);
      if(a == T[i]) count++;
    }
  printf("%d\n",count);
  return 0;
}
int serch(int S[],int a)
{
  int i;
  for(i = 0;i < n;i++)
    {
      if(S[i] == a)
	return a;
    }
  return 1;
}
	
    
  
  

