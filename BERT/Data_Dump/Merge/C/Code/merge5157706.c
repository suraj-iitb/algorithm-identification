#include <stdio.h>
int n;
int timer=0;

void merge(int[],int,int,int);
void mergesort(int[],int,int);

int main()
{
  int A[500000],right,left,i;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  right=n;
  left=0;
  mergesort(A,left,right);

  for(i=0;i<n;i++)
    {
      if(i!=n-1)
	{
	  printf("%d ",A[i]);
	}
      else printf("%d\n",A[i]);
    }
  printf("%d\n",timer);
  

  return 0;
}

void mergesort(int A[],int left,int right)
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

void merge(int A[],int left,int mid,int right)
{
  int n1,n2,L[500000],R[500000],i,j,k;

  n1=mid-left;
  n2=right-mid;

 

  for(i=0;i<=n1-1;i++)
    {
      L[i]=A[left+i];
    }
  for(i=0;i<=n2;i++)
    {
      R[i]=A[mid+i];
    }
  L[n1]=1000000001;
  R[n2]=1000000001;

  i=0;
  j=0;

  for(k=left;k<=right-1;k++)
    {
      timer++;
      if(L[i]<=R[j])
	{
	  A[k]=L[i];
	  i=i+1;
	}
      else
	{
	  A[k]=R[j];
	  j=j+1;
	}
    }
  
}

