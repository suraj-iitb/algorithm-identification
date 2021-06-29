#include <stdio.h>
#include <math.h>

#define N 500000
#define INFINITY 2000000000

void merge(int,int,int);
void mergeSort(int,int);

int A[N],cnt=0;
int main(){
  int n,i;
  int left=0,mid,right;

  scanf("%d",&n);
  right=n;
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(left,right);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",cnt);
  return 0;
}

void merge(int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  n1=mid-left;
  n2=right-mid;
  int L[n1],R[n2];
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=INFINITY;
  R[n2]=INFINITY;
  i = 0;
  j = 0;
  for(k = left;k<right;k++){
    cnt++;
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }else{ 
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int left,int right){
  int mid;
  if(left+1<right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}
