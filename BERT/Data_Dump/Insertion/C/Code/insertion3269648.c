#include <stdio.h>
#include <stdlib.h>
#define Nlimit 100
#define Alimit 1000

int main()
{
  int N,A[Nlimit],i,v,j,k; 
  scanf("%d",&N);
  if(N>Nlimit)
    exit(1);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
      if(A[i]>Alimit)
	exit(2);
    }
  for(i=0;i<N;i++)
    {
      printf("%d",A[i]);
      if(i==N-1) break;
      printf(" ");
    }
  printf("\n");
  for(i=1;i<N;i++)
    {
      v=A[i];
      j=i-1;
      while(j>=0&&A[j]>v)
	{
	  A[j+1]=A[j];
	  j--;
	}
      A[j+1]=v;
      for(k=0;k<N;k++)
	{
	  printf("%d",A[k]);
	  if(k==N-1) break;
	  printf(" ");
	}
      printf("\n");
    }
  return 0;
}

