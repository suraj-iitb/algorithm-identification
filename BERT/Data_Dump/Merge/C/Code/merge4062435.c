#include <stdio.h>

#define INFTY 1000000001

void merge(int *,int,int,int);

void mergesort(int *,int,int);

int Count;

int main()
{
  int n,i;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++)scanf("%d",&A[i]);

  mergesort(A,0,n);

  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n%d\n",A[n-1],Count);
  return 0;
}

void mergesort(int *A,int L,int R)
{
  int M;
  
  if(L+1<R)
    {
      M=(L+R)/2;
      mergesort(A,L,M);
      mergesort(A,M,R);
      merge(A,L,M,R);
    }
}

void merge(int *A,int L,int M,int R)
{
  int n1,n2,i,j,k;

  n1=M-L;
  n2=R-M;

  int l[n1+1],r[n2+1];

  for(i=0;i<n1;i++) l[i]=A[L+i];
  for(i=0;i<n2;i++) r[i]=A[M+i];

  l[n1]=INFTY;
  r[n2]=INFTY;

  i=0;
  j=0;

  for(k=L;k<R;k++)
    {
      if(l[i]<=r[j])
	{
	  A[k]=l[i];
	  i=i+1;
	}
      else
	{
	  A[k]=r[j];
	  j=j+1;
	}
      Count++;
    }
}

