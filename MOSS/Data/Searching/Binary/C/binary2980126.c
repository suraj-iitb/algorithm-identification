#include <stdio.h>
#include <stdlib.h>

int main() {
  int i,j,n,q,count=0,left,right;
  int *S;
  int *T;
  scanf("%d",&n);
  if(n>100000) exit(8);
  S=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
      if(S[i]<0 || S[i]>1000000000) exit(8);
    }
  scanf("%d",&q);
  if(q>50000) exit(8);
  T=(int *)malloc(q*sizeof(int));
  for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
      if(T[i]<0 || T[i]>1000000000) exit(8);
    }
  
  for(j=0;j<q;j++)
    {
      left = 0;
      right = n;
      while(left<right)
	{
	  if(S[(left+right)/2]==T[j])
	    {
	      count++;
	      break;
	    }
	  else if(S[(left+right)/2]<T[j])
	    {
	      left = ((left+right)/2)+1;
	    }
	  else if(S[(left+right)/2]>T[j])
	    {
	      right = (left+right)/2;
	    }
	}
    }
  
  printf("%d\n",count);
  return 0;
}


