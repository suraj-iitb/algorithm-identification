#include<stdio.h>

int n,A[500000],count=0;

void merge(left,mid,right){
  int n1,n2,k;
  int i=0,j=0;
  n1 = mid -left;
  n2 = right - mid;
  int L[n1+1],R[n2+1];

  for(i=0;i<n1;i++){
    L[i] = A[left+i];
  }

  for(i=0;i<n2;i++){
    R[i] = A[mid+i];
  }

  L[n1] = 2000000000;
  R[n2] = 2000000000;

  i=0;
  j=0;
  
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k] = L[i];
      i = i + 1;
      count++;
    }
    else {
      A[k] = R[j];
      j = j+1;
      count++;
    }
  }
}


int mergeSort(left, right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
  return count;
}
  

int main() {

  int i,left,right,mid;

  scanf("%d",&n);

  left = 0;
  right = n;

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(left,right);

  for(i=0;i<n;i++){
    if(i==0){
      printf("%d",A[i]);
    }
    else printf(" %d",A[i]);
  }

  printf("\n%d\n",count);

  return 0;
}

  

  
    

  
  

  
  
  


  
    
  
  

