#include<stdio.h>

int A[500000],count = 0;

void merge(int left,int mid,int right){
  int i,j,k,n1,n2;

  n1 = mid - left;
  n2 = right - mid;

  int L[n1],R[n2];

  for(i = 0;i < n1;i++) L[i] = A[left + i];
  for(i = 0;i < n2;i++) R[i] = A[mid + i];

  L[n1] = R[n2] = 1000000005;

  i = 0; j = 0;
  for(k = left;k < right;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      count++;
    }
    else {
      A[k] = R[j];
      j++;
      count++;
    }
  }
}

void mergeSort(int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }
}


int main(){
  int n,i,data;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&data);
    A[i] = data;
  }

  mergeSort(0,n);

  for(i = 0;i < n;i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }printf("\n%d\n",count);
  return 0;
}

