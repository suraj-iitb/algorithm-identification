#include <stdio.h>

#define N 100

void trace(int A[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(void)
{
  int A[N+1],i,j,key,n,count=0;
  scanf("%d",&n);
  for(i=1 ; i<n+1 ; i++)
    {
      scanf("%d",&A[i]); 
    }
  for(i=1 ; i<n+1 ; i++)
    {
      for(j=n ; j >= i+1 ; j--)
	{
	  if(A[j] < A[j-1])
	    {
	      key = A[j];
	      A[j] = A[j-1];
	      A[j-1] = key;
	      count++;
	    }
	}
    }
  trace(A, n);
  printf("%d\n",count);
  return 0;
}
