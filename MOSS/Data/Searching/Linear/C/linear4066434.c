#include<stdio.h>

int main()
{
  int i,n,q,S[10000],T[500],j=0,k=0,a;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
    }

  for(i=0;i<q;i++)
    {
      S[n]=T[i];
      j=0;
      while( S[j]!=T[i])
	{
	  j++;
	  if(j==n){k++; break;}
	}
    }
  a=q-k;
  printf("%d\n",a);

  return 0;
}

