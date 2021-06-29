#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void merge(int [],int,int,int);
void mergesort(int [],int,int);

#define na 500000
#define INFTY 1000000000

int change = 0;

int L[na],R[na];

int main()
{
  int i = 0,A[na],n = 0;

  scanf("%d",&n);
  
  for(i = 0;i < n;i++)
    {
      scanf("%d",&A[i]);
    }
  mergesort(A,0,n);

  for(i = 0;i < n;i++)
    {
      printf("%d",A[i]);
      if( i < n-1 )
	{
	  printf(" ");
	}
    }
      printf("\n%d\n",change);

      return 0;
}
void merge(int A[],int left,int mid,int right)
{
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0;i < n1;i++)
    {
      L[i] = A[left + i];
    }
  for(i = 0;i < n2;i++)
    {
      R[i] = A[mid + i];
    }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k < right;k++)
    {
      change++;
      if(L[i] <= R[j])
	{
	  A[k] = L[i];
	  i += 1;
	}
      else
	{
	  A[k] = R[j];
	  j += 1;
	}
    }
}
void mergesort(int A[],int left,int right)
{
  int mid;
  if( left+1 < right )
    {
      mid = (left + right)/2;
      mergesort(A,left,mid);
      mergesort(A,mid,right);
      merge(A,left,mid,right);
    }
}

