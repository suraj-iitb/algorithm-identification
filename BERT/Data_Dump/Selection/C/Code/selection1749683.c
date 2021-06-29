#include<stdio.h>
int main()
{
  int N,A[100],i,h=0,minj=0,j,x=0;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  for(i=0;i<=N-1;i++)
    {
      minj=i;
      for(j=i;j<=N-1;j++)
	{
	  if(A[j]<A[minj])
	    minj=j;	  
	}
      x=A[i];
      A[i]=A[minj];
      A[minj]=x;
      if(minj!=i)h++;
    }
    
  for(i=0;i<N;i++)
    {
    if(i>0)printf(" ");
  printf("%d",A[i]);
    }
  printf("\n%d\n",h);
  return 0;
}
