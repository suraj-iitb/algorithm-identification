#include<stdio.h>
int main()
{
  int l,j,N,flag,a,k,i,b;
  int A[100];
  scanf("%d",&N);
  if(N>=1 && N<=100)
    {
      for(l=0;l<N;l++)
	{
	  scanf("%d",&A[l]);
	}
      flag=1;
      i=0;
      while(flag)
	{
	  flag=0;
	  for(j=N-1;j>=i+1;j--)
	    {
	      if(A[j]<A[j-1])
		{
		  a=A[j];
		  A[j]=A[j-1];
		  A[j-1]=a;
		  b++;
		  flag=1;
        
	        }
	    }
	  i++;
	}
		  for(k=0;k<N;k++)
		    {
		      printf("%d",A[k]);
		      if(k<N-1)
			printf(" ");
		    }
		  
    }
		  
  printf("\n");
  printf("%d",b);
  printf("\n");

  return 0;
}

