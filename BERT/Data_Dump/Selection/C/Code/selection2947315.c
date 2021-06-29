#include<stdio.h>
#define N 100

int main()
{
  int i,j,minj,num,A[N],swap,cnt = 0;

  while(1)
    {
      scanf("%d",&num);
      if(num >= 1 && num <= N) break;
    }

  for(i=0;i<num;i++) scanf("%d",&A[i]);

  for(i=0;i<num;i++)
    {
      minj = i;
      for(j=i;j<num;j++)
	{
	  if(A[j] < A[minj]) minj = j;
	}
      if(i != minj)
	{
	  swap = A[i];
	  A[i] = A[minj];
	  A[minj] = swap;
	  cnt++;
	}
    }

   for(i=0;i<num;i++)
    {
      if(i!=num-1) printf("%d ",A[i]);
      else printf("%d\n",A[i]);
    }

  printf("%d\n",cnt);

  return 0;
}

