#include<stdio.h>
int main(void)
{
  int A[100],N,i,temp,j,count=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){scanf("%d",&A[i]);}
  for(j=0;j<N;j++)
    {
  for(i=N-1;i>j;i--)
    {      if(A[i-1]>A[i])
	{
	  temp=A[i-1];
	  A[i-1]=A[i];
	  A[i]=temp;
	  count++;
	}
    }
    }
  for(i=0;i<N;i++){printf("%d",A[i]); if(i != N-1){printf(" ");}}
  printf("\n%d\n",count);
  return 0;
}
