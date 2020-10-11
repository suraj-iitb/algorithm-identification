#include<stdio.h>
int main()
{
  int l,i,j,k,minj,N,a,b=0;
  int A[100];
  scanf("%d",&N);
  if(1<=N && N<=100)
    {
      for(l=0;l<N;l++)
	{
	  scanf("%d",&A[l]);
	}
    }
      for(i=0;i<=N-1;i++)
	{
	  minj=i;
		for(j=i;j<=N-1;j++)
	{
	  if(A[j]<A[minj])
	    {
	      minj=j;
	    }
	
	}
      if(minj!=i)
	b++;
	  a=A[i];
	  A[i]=A[minj];
	  A[minj]=a;
	  
	}
      for(k=0;k<N;k++)
	{
	  printf("%d",A[k]);
	  if(k!=N-1)
	    printf(" ");
	}
	
      
  printf("\n");
  printf("%d",b);
  printf("\n");
  return 0;
}

