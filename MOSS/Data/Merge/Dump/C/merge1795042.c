

#include<stdio.h>
#define N 2000000000
#define Q 500000
void merge(int*,int,int,int);
void mergeSort(int*,int,int);

int count,n;

int main(){
  int i;
  int s[Q];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  count=0;
  mergeSort(s,0,n);
  printf("%d",s[0]);
  for(i=1;i<n;i++) printf(" %d",s[i]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}

void merge(int *A,int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1+1],R[n2+1];
  for(i=0;i<n1;i++) L[i] = A[left + i];
  for(j=0;j<n2;j++) R[j] = A[mid + j];
  L[n1] = N;
  R[n2] = N;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      count++;
    }else{
      A[k] = R[j];
      j++;
      count++;
    }
  }
}

void mergeSort(int *A,int left, int right){
  int mid,i;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
