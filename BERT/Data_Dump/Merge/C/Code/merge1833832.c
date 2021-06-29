#include<stdio.h>
#include<stdlib.h>

void mergeSort();
void merge();

int count=0;
 
int main() 
{
  int i,n;
  int S[500000];
  
  scanf("%d",&n);
  
  for(i=0; i<n; i++) 
    scanf("%d",&S[i]);
  
  mergeSort(S,0,n);
  
  for(i=0; i<n; i++) {
    if(i>0) printf(" ");
    printf("%d",S[i]);
  }
  
  printf("\n");
  printf("%d\n",count);
 
  return 0;
}
 
void merge(int A[],int left,int mid,int right) 
{
  int i,j=0;
  int k;
  int n1 = mid-left, n2 = right - mid; 
  int L[n1+1],R[n2+1];
   
  for(i=0; i<n1; i++) 
    L[i] = A[left+i];
  for(i=0; i<n2; i++) 
    R[i] = A[mid+i];
  L[n1] = (1e+9)+1;
  R[n2] = (1e+9)+1;
  i=0;
  for(k=left; k<right; k++) {
    if( L[i] <= R[j])
      A[k] = L[i++];
    else
      A[k] = R[j++];
    count++;
  }
}
 
void mergeSort(int S[],int left,int right) 
{
  int mid;
  
  if(left+1 < right) {
    
    mid = (left+right)/2;
    
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
  
}
