#include<stdio.h>
#define B 100
main()
{
  int N;//要素
  int A[B];//配列
  int i,n,j,temp=0,num=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i=0;i<(N-1);i++)
    {
      for(j=(N-1);j>i;j--)
	{
	  if(A[j-1]>A[j])
	    {
	       temp=A[j-1];
	      A[j-1]=A[j];
	      A[j]=temp;
	      num++;
	    }
	}
    }
    
 for(i=0;i<N-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[N-1]);
 printf("%d\n",num);
  return 0;
}
