#include <stdio.h>

int main()
{
  int i,j,flag,tmp=0,k=0;
  int N,A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  flag=1;
  while(1)
    {
      flag=0;
      for(j=N-1;j>0;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      tmp=A[j-1];
	      A[j-1]=A[j];
	      A[j]=tmp;
	      k++;
	      flag=1;
	     }
	}
      if(flag==0) break;
    }
  for(i=0;i<N;i++)
    {
      if(i>0)printf(" ");
      printf("%d",A[i]);
    }
  printf("\n%d\n",k);
  return 0;
}

