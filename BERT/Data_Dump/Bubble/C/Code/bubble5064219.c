#include <stdio.h>

int main()
{
  int N,A[100],b,j,cnt=0,flag,i;

  flag=1;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&(A[i]));
  }
  
  while(flag)
    {
      flag=0;
      for(j = N-1 ;j >= 1; j--)
	{
	  if(A[j]<A[j-1])
	    {
	    b=A[j-1];
	  A[j-1]=A[j];
	  A[j]=b;
	  flag=1;
	  cnt++;
	    }
	}
      
    }
  printf("%d",A[0]);
  for(i=1;i<N;i++)
    {
      printf(" %d",A[i]);
    }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

