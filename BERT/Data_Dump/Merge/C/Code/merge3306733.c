#include<stdio.h>
#include<stdlib.h>
void merge(int *,int,int,int);
void mergeSort(int *,int,int);
int count=0;
int main(){
  int n,S[500000],i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

void merge(int *A,int left,int mid,int right){
  int i,j,k,n1,n2,*L,*R;
  n1=mid - left;
  n2=right - mid;

  L=malloc(n1*sizeof(L));
  R=malloc(n2*sizeof(R));
    for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
    for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=2147483647;
  R[n2]=2147483647;
  i=0;
  j=0;

  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      A[k] = L[i];
      i++;

    }
    else {
      A[k] = R[j];
      j++;
    }
  }
}

