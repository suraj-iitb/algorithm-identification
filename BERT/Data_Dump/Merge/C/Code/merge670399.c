#include<stdio.h>

#define SENTINEL 2000000000

int compare = 0;

int main(){

  int n,i,a[500000];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &a[i]);

  MergeSort(a, 0, n);

  for(i=0; i<n-1; i++)
    printf("%d ", a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n", compare);

  return 0;
  
}

int Merge(int A[], int left, int mid, int right){

  int n1,n2;
  int i,j,k;
    
  n1=mid-left;
  n2=right-mid;

  int L[n1+1],R[n2+1];

  for(i=0;i<=n1-1;i++)
    L[i]=A[left+i];
  for(i=0;i<=n2-1;i++)
    R[i]=A[mid+i];
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left; k<=right-1; k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
      compare++;
    }
    else {
      A[k]=R[j];
      j=j+1;
      compare++;
    }
  }
}

int MergeSort(int A[], int left, int right){

  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    MergeSort(A, left, mid);
    MergeSort(A,mid, right);
    Merge(A, left, mid, right);
  }

}
