#include<stdio.h>

int main()
{
  int N, A[100];
  int sum=0;
  int mini;
  int i, j, k;

  //Read N and set A
  scanf("%d", &N);
  for(i=0; i<N; i++)scanf("%d", &A[i]);

  //Begin Selection Sort
  for(i=0; i<N; i++)
    {
      mini=i;
      for(j=i; j<N; j++)
	{
	  if(A[j]<A[mini])
	    mini=j;
	}
      //swap
      if(mini!=i)
	{
	  k=A[i];
	  A[i]=A[mini];
	  A[mini]=k;
	  sum++;
	}
    }

  //print
  for(i=0; i<N; i++)
    {
      if(i!=N-1)printf("%d ", A[i]);
      else printf("%d", A[i]);;
    }
  printf("\n%d\n", sum);

  return 0;
}
