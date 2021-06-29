#include<stdio.h>

#define MAX 500000
#define INFINITY 2000000000

int cnt;
int L[(MAX/2)+2];
int R[(MAX/2)+2];

void merge(int[],int,int,int);
void mergeSort(int[],int,int);


int main()
{
  int n,A[MAX],i;
  cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  mergeSort(A,0,n);

  for(i=0;i<n-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[i]);

  printf("%d\n",cnt);

  return 0;
}

void merge(int A[],int left,int mid,int right)
{
  int i,j,k,n1,n2;

   n1=mid-left;
   n2=right-mid;
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=INFINITY;
  R[n2]=INFINITY;
  i=0;
  j=0;
  for(k=left;k<right;k++)
    {
      cnt++;
      if(L[i]<=R[j]){
	A[k]=L[i++];
      }
      else {
	A[k]=R[j++];
      }
    }
}

void mergeSort(int A[],int left,int right)
{
  int mid;  
  if(left+1<right){
    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
