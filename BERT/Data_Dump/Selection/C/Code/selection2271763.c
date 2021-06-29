#include<stdio.h>
int main()
{
  int A[100];
  int N;
  int i,j,tmp,minj;
  int cnt=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i=0;i<N-1;i++)
    {
      minj=i;
      for(j=i;j<N;j++)
	{
	  if(A[j]<A[minj])
	  minj=j;
	}
      tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
      if(A[i]!=A[minj])cnt++;
    }
	  

  for(i=0;i<N;i++)
    {
      printf("%d",A[i]);
      if(i!=N-1) printf(" ");
    }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}
