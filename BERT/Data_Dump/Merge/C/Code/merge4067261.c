#include <stdio.h>
#define INFTY 1000000001
#define N 500000
void merge(int,int,int);
void mergeSort(int,int);

int A[N],count=0;
int main()
{
  
  int n,i,left,right;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  left=0;
  right=n;
  mergeSort(left,right);
   for(i=0;i<n-1;i++)
    {
      printf("%d ",A[i]);
    }
   printf("%d\n",A[n-1]);
   printf("%d\n",count);
  return 0;
}

void merge(int left,int mid,int right)
{
  int n1=mid-left,n2=right-mid;
  int L[n1],R[n2],i,j,k;
  for(i=0;i<n1;i++)
    {
      L[i]=A[left+i];
    }
  for(i=0;i<n2;i++)
    {
      R[i]=A[mid+i];
    }
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++)
    {
      if(L[i]<=R[j])
	{
	  A[k]=L[i];
	  i=i+1;
	  count++;
	}
      else
	{
	  A[k]=R[j];
	  j=j+1;
	  count++;
	}
    }
}

void mergeSort(int left,int right)
{
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      mergeSort(left,mid);
      mergeSort(mid,right);
      merge(left,mid,right);
    }
}

