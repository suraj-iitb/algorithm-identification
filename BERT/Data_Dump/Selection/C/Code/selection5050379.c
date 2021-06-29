#include <stdio.h>

int main()
{
  int A[100],i,minj,j,temp,N,cnt=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
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
      
      /*/DEBUG
	  for(i = 0; i < N; i++)printf("%d ",A[i]);
	  printf("\n");

	  //DEBUG*/
      
	      temp=A[i];
	      A[i]=A[minj];
	      A[minj]=temp;
	       if(A[i]!=A[minj])
		{
		  cnt++;
		    }
    }
	      
   

  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

