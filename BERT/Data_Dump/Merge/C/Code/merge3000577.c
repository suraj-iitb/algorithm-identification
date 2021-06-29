#include<stdio.h>

void mergeSort(int[],int,int);
void merge(int[],int,int,int);

#define INFTY 1000000001

int cont=0;

int main(){
  int i,x;
  scanf("%d",&x);
  int a[x];
  for(i=0;i<x;i++)scanf("%d",&a[i]);

  mergeSort(a,0,x);
  for(i=0;i<x-1;i++)printf("%d ",a[i]);
  printf("%d\n",a[x-1]);
  printf("%d\n",cont);
  return 0;
}
void merge(int A[],int left,int mid,int right){
  int i,j;
  int n1,n2;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1];
  int R[n2];
//[0...n1], R[0...n2] を生成
  for(i=0;i<=n1-1;i++)L[i] = A[left + i];
  for(i=0;i<=n2-1;i++)R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  int k=0;
			
  for(k=left;k<=right-1;k++){
    if(L[i]<=R[j]){
      A[k] = L[i];
      i = i + 1;
      cont++;
    }
    else{ 
      A[k] = R[j];
       j = j + 1;
      cont++;
    }
  }
}
void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

