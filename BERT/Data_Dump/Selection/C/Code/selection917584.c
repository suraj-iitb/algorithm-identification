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
  int A[N+1],i,j,key,n,count=0,mini,cou;
  scanf("%d",&n);
  for(i=1 ; i<n+1 ; i++)
    {
      scanf("%d",&A[i]); 
    }
  for(i=0 ; i<=n ; i++)
    {
      mini = i;
      cou=0;
      for(j=i ; j<=n ; j++)
	{
	  if(A[j] < A[mini])
	    {
	      mini = j;
	      cou=1;
	    }
	}
      if(cou==1)
	{
	  key = A[i];
	  A[i] = A[mini];
	  A[mini] = key;
	  count++;
	}
    }
  trace(A, n);
  printf("%d\n",count);
  return 0;
}
