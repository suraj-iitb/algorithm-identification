#include <stdio.h>
#define N 500000
#define INFTY 1000000001
void merge(int *,int,int,int);
void mergesort(int *,int,int);
int n1,n2,left,right,count=0,A[N],R[N],L[N];
int main()
{
  int n,i;
  scanf("%d",&n);
  left=0;
  right=n;
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  mergesort(A,left,right);
  for(i=0;i<n;i++)
    {
    printf("%d",A[i]);
    if(i!=n-1)
      printf(" ");
    }
  printf("\n");
  printf("%d",count);
  printf("\n");
  return 0;
}

void merge(int *A,int left,int mid,int right)
{
  int i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<=n1-1;i++)
    L[i]=A[left+i];
  for(i=0;i<=n2-1;i++)
    R[i]=A[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++)
    {
      if(L[i]<=R[j])
        {
          A[k]=L[i];
          i++;
          count++;
        }
      else
        {
          A[k]=R[j];
          j++;
          count++;
        }
    }
}

void mergesort(int *A,int left,int right)
{
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      mergesort(A,left,mid);
      mergesort(A,mid,right);
      merge(A,left,mid,right);
    }
}
