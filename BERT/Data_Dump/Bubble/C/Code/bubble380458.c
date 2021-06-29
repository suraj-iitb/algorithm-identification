#include<stdio.h>

int main()
{
  int N, A[100];
  int result;
  int i, j, k;

  //Read N and Sets
  scanf("%d", &N);
  for(i=0; i<N; i++)scanf("%d", &A[i]);

  //Begin Bubble Sort
  result=0;
  for(i=0; i<N; i++)
    {
      for(j=1; j<N; j++)
	{
	  //if A[j]<A[j+1], change;
	  if(A[j]<A[j-1])
	    {
	      k=A[j];
	      A[j]=A[j-1];
	      A[j-1]=k;
	      result++;
	    }
	}
    }

  //print
  for(i=0; i<N; i++)
    {
      if(i!=N-1)printf("%d ", A[i]);
      else printf("%d", A[i]);;
    }
  printf("\n%d\n", result);



  return 0;
}
