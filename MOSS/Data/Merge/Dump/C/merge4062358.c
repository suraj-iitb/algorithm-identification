#include<stdio.h>
#include<math.h>

int A[500000],count=0;

void merge(int,int,int);
void mergeSort(int,int);
  
void merge(int left,int mid,int right){
  int i,j,k,n1,n2,L[500000],R[500000];
  n1 = mid - left;
  n2 = right - mid;
  
  for(i=0;i<n1;i++) L[i] = A[left + i];
  for(i=0;i<n2;i++) R[i] = A[mid + i];
  L[n1] = (int)INFINITY;
  R[n2] = (int)INFINITY;
  i=0;
  j=0;
  
  for(k=left;k<right;k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{ 
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }
}

int main(){
  int i,n,left=0,right;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  right=n;

  mergeSort(left,right);
  
  for(i=0;i<n;i++){
    if(i!=0) printf(" ");
  printf("%d",A[i]);
  }
  printf("\n%d\n",count);

  return 0;
}

