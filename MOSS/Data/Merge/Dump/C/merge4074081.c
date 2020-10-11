#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int,int,int);
void mergeSort(int,int);

int *A,count=0;
int main()
{
  
  int n,i,left=0,mid,right;

  scanf("%d",&n);
  A=(int *)malloc(sizeof(int)*n);
  right=n;
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  mergeSort(left,right);

  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",count);

  return 0;
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

void merge(int left,int mid,int right)
{
  int n1,n2,i,j,k;
  int *L,*R;

  n1=mid-left;
  n2=right-mid;

  L=(int *)malloc(sizeof(int)*n1+1);
  R=(int *)malloc(sizeof(int)*n2+1);
  
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1]=(int)INFINITY;
  R[n2]=(int)INFINITY;
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
