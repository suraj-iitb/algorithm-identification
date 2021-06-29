#include <stdio.h>


int main()
{
  int A[100],i,j,flag,N,temp,cnt = 0;
  flag=1;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  
  i=1;
  
  while(flag)
    {
      flag=0;

      for(j=N-1;j>=1;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      temp=A[j];
	      A[j]=A[j-1];
	      A[j-1]=temp;
	     
	      flag=1;
	      i++;
	      cnt++;
	    }	  
	}
    }
  
  for(j=0;j<N;j++)
    {
      if(j>0)printf(" ");
      printf("%d",A[j]);
    }
 
  printf("\n");
  printf("%d\n",cnt);



return 0;
}

