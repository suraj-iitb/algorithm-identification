#include <stdio.h>
#include <stdlib.h>

int main() {
  int i,j,n,q,count=0,size;
  int *S;
  int *T;
  scanf("%d",&n);
  if(n>10000) exit(8);
  S=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
      if(S[i]<0 || S[i]>1000000000) exit(8);
    }
  scanf("%d",&q);
  if(q>500) exit(8);
  T=(int *)malloc(q*sizeof(int));
  for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
      if(T[i]<0 || T[i]>1000000000) exit(8);
    }
  for(i=0;i<q;i++)
    {
      for(j=0;j<n;j++)
	{
	  if(S[j] == T[i])
	    {
	      count++;
	      break;
	    }
	}
    }
  /*for(i=0;i<q;i++)
    {
      if(linearSearch(&S[0],T[i],n) != EOF)
	{
	  count++;
	}
	}*/
  printf("%d\n",count);
  return 0;
}


