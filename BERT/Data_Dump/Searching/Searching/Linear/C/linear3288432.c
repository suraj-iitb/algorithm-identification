#include<stdio.h>

int linearSearch(int,int *,int);

int main()
{
  int i,j,n,q,S[10000],T[10000];

  scanf("%d",&n);
  for(i = 0;i < n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i = 0;i < q;i++)
    scanf("%d",&T[i]);

  i = 0;
  
  for(j = 0;j < q;j++)
    {
      if(linearSearch(n,S,T[j]) == 1)
	i++;
    }
  printf("%d\n",i);
      
  return 0;
}

  int linearSearch(int n,int *A,int B)
{
  int i;
  
  for(i = 0;i < n;i++)
    {
      if(A[i] == B)
	{
	  return 1;
	  break;
	}
    }
  return 0;
}
      

