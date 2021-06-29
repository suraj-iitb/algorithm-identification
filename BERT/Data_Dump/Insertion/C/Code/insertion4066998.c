#include<stdio.h>
#include<stdlib.h>
#define N 100
int main(){
  int A[N],i,j,v,kosuu,k;
  scanf("%d",&kosuu);
  if(kosuu < 1 || kosuu > 100) exit(1);
 for(k = 0;k < kosuu ;k++)
	{
	  scanf("%d",&A[k]);
	  if(0>A[k] || 1000<A[k]) exit(2); 
	}
 for(k=0;k < kosuu-1 ; k++)
	{
	  printf("%d ",A[k]);
	}
      printf("%d\n",A[k]);
  
  for(i = 1;i<kosuu;i++)
    {v = A[i];
      j = i-1;
      while( j>=0 && A[j] > v)
	{
	  A[j+1]=A[j];
	  j--;
	}
      A[j+1] = v;

      for(k=0;k < kosuu-1 ; k++)
	{
	  printf("%d ",A[k]);
	}
      printf("%d\n",A[k]);
    }
  return 0;
}

