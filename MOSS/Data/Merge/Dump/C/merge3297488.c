#include<stdio.h>
#include<stdlib.h>
int merge(int *,int,int,int);
int mergeSort(int *,int,int);
int main(){
  int i,n,*A,count;
  scanf("%d",&n);
  A = (int*)malloc(n * sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  count = mergeSort(A,0,n);
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(!(i==n-1)) printf(" ");
      }
  printf("\n%d\n",count);
  return 0;
}

int merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  int *L,*R;
  static int count;
  n1 = mid - left;
  n2 = right - mid;
  L = (int*)malloc((n1+1) * sizeof(int));
  R = (int*)malloc((n2+1) * sizeof(int));
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=2147483647;
  R[n2]=2147483647;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }
  return count;
}

int mergeSort(int *A,int left,int right){
  int count,mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    count = merge(A,left,mid,right);
  }
  return count;
}

