#include<stdio.h>

int main()
{
  int i,j,k,n=0;
  int N,A[100],minj,tmp;

  scanf("%d",&N);
  for(k=0;k<N;k++)
    {
      scanf("%d",&A[k]);
    }
  for(i=0;i<N;i++)
    {
      minj=i;
      for(j=i;j<N;j++)
	{
	  if(A[j]<A[minj])
	    {
	      minj=j;
	    }
	}
      if(A[i]!=A[minj])
	{
	  tmp=A[i];
	  A[i]=A[minj];
	  A[minj]=tmp;
	  n++;
	}
    }
  for(k=0;k<N;k++)
    {
      if(k>0)printf(" ");
      printf("%d",A[k]);
    }
  printf("\n%d\n",n);

  return 0;
}

