#include<stdio.h>
#define K 2000000

void count (int[], int);

int main()
{
  int A[K],n,i;


  scanf("%d",&n);

  for(i=0; i<n; i++)
    {
      scanf("%d",&A[i]);
    }

  count(A,n);

  return 0;
}


void count(int A[], int n)
{
  int i,j,C[K],B[K];

  for(i=0; i<=K; i++)
    {
      C[i]=0;
      B[i]=0;
    }
  for(i=0; i<n; i++)
    {
      C[A[i]]++;
      
    }
  
  for(i=1; i<=K; i++)
    {
      C[i]=C[i]+C[i-1];
      
    }

  for(i=n-1; i>=0; i--)
    {
      B[C[A[i]]]=A[i];
      
      C[A[i]]--;
	     
    }
  for(i=1; i<=n; i++)
    {
      printf("%d",B[i]);
      if(i!=n) printf(" ");
    }
  printf("\n");
}
  

