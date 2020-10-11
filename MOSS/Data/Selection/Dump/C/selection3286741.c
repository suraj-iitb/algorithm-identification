#include<stdio.h>

int main(){

  int N = 0,A[100],i = 0,j = 0,k = 0,l = 0,m = 0,flag = 0,mink = 0;

  scanf("%d",&N);

  for(i = 0;i < N;i++)
    {
      scanf("%d",&A[i]);
    }
  for(j = 0;j <= N-1;j++)
    {
      mink = j;
      for(k = j;k <= N-1;k++)
	{
	  if(A[k] < A[mink])
	    {
	      mink = k;
	    }
	}
      if(A[j] != A[mink])
	{
	  flag += 1;
	}
	  l  = A[mink];
	  A[mink] = A[j];
	  A[j] = l;
    }
  for(m = 0;m < N;m++)
  {
    if(m == N-1)
      {
	  printf("%d\n",A[m]);
	}
      else if(m < N-1)
	{
      printf("%d ",A[m]);
	}
    }
  printf("%d\n",flag);
  return 0;
}

