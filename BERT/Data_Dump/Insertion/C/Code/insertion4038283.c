#include<stdio.h>

int main()
{
  int i,j,k,A[1000],N,v;

  scanf("%d", &N);
  for(k=0;k<N;k++)
    {
      scanf("%d", &A[k]);
    }
  for(k=0;k<N;k++)
    {
      if(k>0)printf(" ");
      printf("%d",A[k]);
    }
  printf("\n");
  
  for(i=1;i<=N-1;i++)
    {
      v=A[i];
      j=i-1;
      while(j>=0 && A[j]>v)
	{
	  A[j+1]=A[j];
	  j--;
	}
      A[j+1]=v;
      for(k=0;k<N;k++)
	{
	  if(k>0)printf(" ");
	  printf("%d",A[k]);
	}
      printf("\n");
    }
  return 0;
}

