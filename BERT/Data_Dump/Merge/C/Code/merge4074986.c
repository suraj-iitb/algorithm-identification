#include <stdio.h>
#include <stdlib.h>

#define N 500003
#define INFTY 1000000001

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int l;

int main()
{
  int i,j,left,mid,right,n;
  int S[N];

  scanf("%d",&n);
	     
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  left=0;
  right=n;
  
  mergeSort(S,left,right);

  for(i=0;i<n-1;i++) printf("%d ",S[i]);
  printf("%d\n",S[n-1]);
  printf("%d\n",l);

  return 0;
}

void merge(int *S,int left,int mid,int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1],R[n2+1],i,j,k;
  
  for(i=0;i<n1;i++) L[i] = S[left + i];
  for(j=0;j<n2;j++) R[j] = S[mid + j];
    
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
    for(k=left;k<right;k++){
      if(L[i] < R[j]){
	S[k] = L[i];
	i = i + 1;
      }
      else{ 
	S[k] = R[j];
	j = j + 1;
	}
      l++;
    }
}

void  mergeSort(int *S,int left,int right)
{
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(S, left, mid);
     mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
}

