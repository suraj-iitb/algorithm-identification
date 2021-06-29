#include <stdio.h>

int bubbleSort();
int main()
{
  int N,flag,i,j,sabu,c=0;
  scanf("%d",&N);
  int A[N];
  for(i = 0;i < N;i++)
    {
      scanf("%d",&A[i]);
    }
  flag = 1;
  i = 0;
  while (flag)
    {
      flag = 0;
      for(j = N-1;j >=i+1;j--)
	{
	  if(A[j] < A[j-1])
	    {
	      sabu = A[j];
	      A[j] = A[j-1];
	      A[j-1] = sabu;
	      flag = 1;
	      c++;
	    }
	}
      i++;
    }
  for(i = 0;i < N;i++)
    {
      printf("%d",A[i]);
      if(i != N-1)
	{
	  printf(" ");
	}
    }
  printf("\n%d\n",c);
  
  return 0;
}

