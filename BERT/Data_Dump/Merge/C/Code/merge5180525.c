#include<stdio.h>
#define N 500000
#define INFTY 1000000000

void MergeSort(int*,int, int);
void merge(int*,int,int,int);
int cnt=0;

int main()
{
  int x,i,mid,A[N];
  //input
  scanf("%d",&x);
  for(i=0;i<x;i++) scanf("%d",&A[i]);
  //algo
  MergeSort(A,0,x); //0=left,x=right,A=sequence
  //output
  for(i=0;i<x-1;i++) printf("%d ",A[i]);
  printf("%d\n%d\n",A[i],cnt);
  return 0;
}
void MergeSort(int *A,int left,int right)
{
  int mid;
  if( (left+1) < right )
    {
      mid = (left + right)/2;
      MergeSort(A,left,mid);
      MergeSort(A,mid,right);
      merge(A,left,mid,right);
    }
}
void merge(int *A,int left,int mid,int right)
{
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1],R[n2];
  for(i=0;i<n1;i++) L[i] = A[left + i];
  for(i=0;i<n2;i++) R[i] = A[mid + i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++)
    {
      if(L[i]<=R[j]){
	A[k]=L[i];
	i++;
	cnt++;
      }
      else{
	A[k] = R[j];
	j++;
	cnt++;
      }
    }
}
	 

