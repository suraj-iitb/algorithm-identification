#include <stdio.h>
#define N 500000
#define INFTY 999999999

void mergesort(int *,int,int);
void merge(int *,int,int,int);

int count = 0;
 
int main()
{
  int n,i,A[N];
 
  scanf("%d",&n);

  for( i = 0; i < n; i++)

    scanf("%d",&A[i]);
 
  mergesort(A,0,n);
 
  for(i = 0; i < n - 1; i++)
      printf("%d ",A[i]);

      printf("%d\n%d\n",A[n - 1],count);
   
  return 0;
}
 
void mergesort(int *A,int left,int right){
  int mid;
 
  if(left + 1 < right)
    {
      mid=(left+right)/2;
      mergesort(A,left,mid);
      mergesort(A,mid,right);
      merge(A,left,mid,right);
    }
}
 
void merge(int *A,int left,int mid,int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  int i,j,k;
  int L[N],R[N];
 
  for(i = 0; i < n1; i++)
    L[i] = A[left + i];

  for(i = 0; i < n2; i++)
    R[i] = A[mid + i];

  L[n1] = INFTY;
  R[n2] = INFTY;

  i=0;
  j=0;

  for(k = left; k < right;k++)
    {
      count++;

    if(L[i] <= R[j])
      {
	A[k] = L[i];
	i++;
      }

    else
      {
	A[k] = R[j];
	j++;
      }
    }
}
