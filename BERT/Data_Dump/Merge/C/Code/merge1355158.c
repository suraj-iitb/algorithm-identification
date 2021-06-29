#include<stdio.h>
#define SENTINEL 1000000000
 
int count=0,A[500000];
 
void Merge(int left, int mid, int right){
  int n1 = mid-left;
  int n2 = right-mid;
  int L[n1],R[n2];
  int i,j,k;
  for (i=0;i<=n1-1;i++){
    L[i]=A[left+i];
  }
  for (i=0;i<=n2-1;i++){
    R[i]=A[mid+i];
  }
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;
  /*
  printf("L[");
  for (i=0;i<=n1;i++){
    if (i!=0){
      printf(" ");
    }
    printf("%d",L[i]);
  }
  printf("]\n");
  printf("R[");
  for (i=0;i<=n2;i++){
    if (i!=0){
      printf(" ");
    }
    printf("%d",R[i]);
  }
  printf("]\n");
  */
  for (k=left;k<=right-1;k++){
    count++;
    if (L[i]<=R[j]){
      A[k]=L[i];
      i++;
    } else {
      A[k]=R[j];
      j++;
    }
  }
}
 
void MergeSort(int left, int right){
  int mid;
  if (left+1<right){
    mid = (left+right)/2;
    MergeSort(left,mid);
    MergeSort(mid,right);
    Merge(left,mid,right);
  }
}
 
int main(){
  int i,n;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  MergeSort(0,n);
  for (i=0;i<n;i++){
    if(i!=0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}
