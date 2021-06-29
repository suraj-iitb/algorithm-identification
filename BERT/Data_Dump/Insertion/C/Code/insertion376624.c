#include<stdio.h>

int main()
{
  int A[100];
  int N;
  int key;
  int i, j, k;

  //Read N and keys
  scanf("%d", &N);
  for(i=0; i<N; i++)scanf("%d", &A[i]);

  //Sort
  for(i=0; i<N; i++)
    {
      key=A[i];
      j=i-1;

      //if A[j]>key, change A[j] to A[j+1]
      while(j>=0 && A[j]>key)
	{
	  A[j+1]=A[j];
	  j=j-1;
	}
      A[j+1]=key;

      //print
      for(k=0; k<N; k++)
	{
	  printf("%d", A[k]);
	  if(k!=N-1)printf(" ");
	}
      printf("\n");
    }

  return 0;
}
