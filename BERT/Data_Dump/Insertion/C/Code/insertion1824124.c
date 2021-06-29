#include<stdio.h>
#define MAX 1000

int main()
{
  int i, j, k, N, v;
  int A[MAX];

  scanf("%d",&N);

  for(i=0;i<=N-1;i++)
    {
      scanf("%d",&A[i]);
    }

  printf("%d",A[0]);
  for(k=1;k<=N-1;k++)
	{
	  printf(" %d",A[k]);
	}
  printf("\n");
  
  for(i=1;i<=N-1;i++)
    {
      v = A[i];
      j = i-1;
      while(j>=0&&A[j]>v)
      {
        A[j+1] = A[j];
        j--;
      }
      A[j+1] = v;
      
      printf("%d",A[0]);
      for(k=1;k<=N-1;k++)
	{
	  printf(" %d",A[k]);
	}
      printf("\n");
      }
  return(0);
}
