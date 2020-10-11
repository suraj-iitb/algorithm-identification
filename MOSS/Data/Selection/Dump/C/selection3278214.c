#include <stdio.h>

int sen(int *,int);

int main ()
{
  int A[100],N,i,x;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
    scanf("%d",&A[i]);
    }
  x=sen(A,N);
  for(i=0;i<N;i++)
    {
      if(i>0)
	{
	  printf(" ");
	}
      printf("%d",A[i]);
    }
  printf("\n");
  printf("%d\n",x);

  return 0;
}

int sen(int A[],int N)
{
  int i,j,y,x=0,minj;

  for(i=0;i<N-1;i++)
    {
      minj=i;
      for(j=i;j<N;j++)
	{
	  if(A[j]<A[minj])
	    minj=j;
	}
      y=A[i];A[i]=A[minj];A[minj]=y;
      if(i!=minj)
	x++;
    }
      return x;
}
  

