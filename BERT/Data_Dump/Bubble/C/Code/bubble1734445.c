#include<stdio.h>

int main()
{
  int N,c=0,A[100],i,j,X,flag=1;
 
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }

  while(flag){
    flag=0;

    for(j=N-1;j>=1;j--)
      {
	if(A[j]<A[j-1])
	  {
	    X=A[j];
	    A[j]=A[j-1];
	    A[j-1]=X;
	    flag=1;
	    c++;
	  }
      }
  }


  for(i=0;i<N-1;i++)
    {
      printf("%d ",A[i]);
    }

  printf("%d\n",A[N-1]);
  printf("%d\n",c);
  return 0;
}
