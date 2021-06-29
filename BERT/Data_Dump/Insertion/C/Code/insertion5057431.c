#include <stdio.h>

#define MAX 1000

int main()
{
  int i, j, A[MAX], v=0, N,k;

  scanf("%d",&N);
  
  for(i = 0 ;i < N ; i++)
    {      
      scanf("%d",&(A[i]));
    }
   
  for(i=1;i<=N-1;i++)
    {
     
      v=A[i];
      j=i-1;
      for(k=0;k<N;k++){
	printf("%d",A[k]);
	if(k!=N-1)
	  {
	    printf(" ");
	  }
      }
      printf("\n");
	
      
      while(j>=0&&A[j]>v)
	{
	  
	  A[j+1]=A[j];
	  j--;
	  A[j+1]=v;
	}
    }
  for(i=0;i<N;i++)
    {
      printf("%d",A[i]);
      if(i!=N-1)
	  {
	    printf(" ");
	  }
    }
  printf("\n");
  return 0;
}


