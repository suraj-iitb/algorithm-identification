#include<stdio.h>
int main()
{
  int A[100];
  int N;
  int i,j,tmp,cnt=0;
  int flag;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  flag = 1;
  while(flag)
    {
      flag=0;
      for(i=0;i<N-1;i++)
	{
	  for(j=N-1;j>0;j--)
	    {
	      if(A[j]<A[j-1])
		{
		  tmp=A[j-1];
		  A[j-1]=A[j];
		  A[j]=tmp;
		  flag = 1;
		  cnt++;
		}
	    }
	}
    }
  for(i=0;i<N;i++)
    {
      printf("%d",A[i]);
      if(i!=N-1)printf(" ");
    }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}
