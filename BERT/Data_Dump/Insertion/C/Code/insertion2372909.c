#include<stdio.h>
int main()
{
  int A[100];
  int i,j,v,N;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  for(i=0;i<N;i++)
    {
      v=A[i];
      j=i-1;
      while((j>=0)&&(A[j]>v))
	{
	  A[j+1]=A[j];
	  j--;
	}
      A[j+1]=v;
      for(j=0;j<N-1;j++) printf("%d ",A[j]);
      printf("%d\n",A[j]);
    }
  return 0;
}
