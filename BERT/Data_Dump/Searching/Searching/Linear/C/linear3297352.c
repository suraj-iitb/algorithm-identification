#include<stdio.h>

int main()
{
  int n = 0,S[10000],q = 0,T[500],i = 0,j = 0,k = 0,l = 0,C = 0;
  
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  for(j =0;j < q;j++)
    {
      scanf("%d",&T[j]);
    }
  
  for(k = 0;k < q;k++)
    {
      for(l = 0;l < n;l++)
	{
	  if( S[l] == T[k]){
	      C++;
	      break;
	    }
	}
      
    }
  printf("%d\n",C);
  return 0;
}

