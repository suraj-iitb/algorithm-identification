#include<stdio.h>

int main()
{
  int i,N,j;
  int minj,tmp,count=0;
  int A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
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
      if(minj!=i){
	tmp=A[i];
	A[i]=A[minj];
	A[minj]=tmp;
	count++;
      }
    }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1)printf(" ");
  }printf("\n");
  printf("%d\n",count);
  return 0;
}
