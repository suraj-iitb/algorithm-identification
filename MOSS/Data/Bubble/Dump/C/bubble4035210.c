#include<stdio.h>

int main()
{
  int flag=1,N,a,A[100],i,j,c=0;

  scanf("%d",&N);

  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  
  i=0;
  
  while(flag)
    {
      flag=0;

      for(j = N-1; j >= i+1; j--)
	{
	  if(A[j] < A[j-1]){
	    a = A[j];
	    A[j] = A[j-1];
	    A[j-1] = a;
	    flag = 1;
	    c++;
	  }
	}
      i++;
    }

  for(i=0;i<=N-1;i++)
    {
      printf("%d",A[i]);
      if(i<N-1)printf(" ");
    }
  printf("\n%d\n",c);
  
  
  return 0;
}
	  

