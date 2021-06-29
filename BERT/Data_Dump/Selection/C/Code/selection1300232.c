#include<stdio.h>
#define B 100
main()
{
  int N;//要素
  int A[B];//配列
  int i,n,j,temp=0,num=0,min,k;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i=0;i<N-1;i++)
    {
      min=A[i];
      k=i;
      for(j=i;j<N;j++)
	{
	if(A[j]<min)
	  {
	    min=A[j];
	    k=j;
	   
	  }
    }
  temp=A[i];
  A[i]=A[k];
  A[k]=temp;
  if(i!=k)num++;
 
}


 for(i=0;i<N-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[N-1]);
 printf("%d\n",num);
  return 0;
}
