#include<stdio.h>
#define N 100

int main()
{
  int i,j,num,A[N],swap,cnt = 0;

  while(1)
    {
      scanf("%d",&num);
      if(num >= 1 && num <= N) break;
    }

  for(i=0;i<num;i++) scanf("%d",&A[i]);
  
  for(i=0;i<num;i++)
    {
      for(j=num-1;j>=1;j--)
	{
	  if(A[j] < A[j-1])
	    {
		  swap = A[j];
		  A[j] = A[j-1];
		  A[j-1] = swap;
		  cnt++;
	    }
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

