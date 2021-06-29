#include <stdio.h>
int main()
{
  int A[100];
  int i, j;
  int N,key;
  

  scanf("%d%",&N);
  for(i = 0; i < N; i++)
      scanf("%d",&A[i]);
  //printf("\n");
  for(i = 0; i < N; i++)
    {
      printf("%d",A[i]);
      if(i != N - 1) printf(" ");
    }
  printf("\n");
  for(j = 1; j < N ; j++)
    {
      key = A[j];
      i = j - 1;
      while(i >= 0 && A[i] > key)
	{
	  A[i+1] = A[i];
	  i--;
	}
      A[i+1] = key;
      for(i = 0; i < N; i++)
	{
	  printf("%d",A[i]);
	  if(i != N - 1) printf(" ");
	}
      printf("\n");
    }
  return 0;
}
      

  

  

