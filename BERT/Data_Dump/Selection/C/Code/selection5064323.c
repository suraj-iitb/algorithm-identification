#include <stdio.h>

int main()
{
  int N,A[100],i,minj,j,b,cnt=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&(A[i]));
    }

  for(i=0;i<=N-1;i++)
    {
      minj=i;
      for(j=i;j<=N-1;j++)
	{
	  if(A[j]<A[minj])
	    {
	    minj=j;
	    }	  
	}
      b=A[minj];
	  A[minj]=A[i];
	  A[i]=b;
	  if(minj!=i)
	    {
	  cnt++;
	    }
    }
  printf("%d",A[0]);
  for(i=1;i<N;i++)
    {
      printf(" %d",A[i]);
    }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}

