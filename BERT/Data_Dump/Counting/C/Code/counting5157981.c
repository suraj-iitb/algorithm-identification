#include <stdio.h>
#include <stdlib.h>

int n;

void countingsort(int *,int *,int);

int main()
{
  int i,*A,k=-1,*B;


  
  scanf("%d",&n);
  A=malloc(sizeof(int)*(n+1));
  B=malloc(sizeof(int)*(n+1));  
  for(i=1;i<=n;i++)
    {
      scanf("%d",&A[i]);
       if(k<A[i])
	 {
	   k=A[i];
	 }
    }
  countingsort(A,B,k);

  for(i=1;i<=n;i++)
    {
    if(i!=n)
      {
	printf("%d ",B[i]);
      }
    else printf("%d\n",B[i]);
    }
  return 0;
}

void countingsort(int *A,int *B,int k)
{
  int i,j,C[2000000];

  for(i=0;i<=k;i++)
    {
      C[i]=0;
    }

  for(j=1;j<=n;j++)
    {
      C[A[j]]++;
    }

  for(i=1;i<=k;i++)
    {
      C[i]=C[i]+C[i-1];
    }

  for(j=n;j>=1;j--)
    {
      B[C[A[j]]]=A[j];
      C[A[j]]--;
    }

}

