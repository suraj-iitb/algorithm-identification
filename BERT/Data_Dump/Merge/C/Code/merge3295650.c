#include<stdio.h>
#define N 1e9

int count=0;

void merge(int*, int, int, int);
void mergesort(int*, int, int);

void merge(int A[], int left, int mid, int right){

  int i, j, k, n1=mid-left, n2=right-mid;

  int L[n1+1], R[n2+1];

  for(i=0;i<n1;i++) L[i]=A[left+i];

  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1]=N; R[n2]=N;

  i=0; j=0;

  for(i=0,j=0,k=left;k<right;k++){

    count++;

    if(L[i]<=R[j]){

      A[k]=L[i];

      i++;

    }else{

      A[k]=R[j];

      j++;

    }

  }return ;

}

void mergesort(int A[], int left, int right){

  if(left+1<right){

    int mid=(left+right)/2;

    mergesort(A, left, mid);

    mergesort(A, mid, right);

    merge(A, left, mid, right);

  }return;

}

int main(){

  int i, j, n;

  scanf("%d", &n);

  int A[n];

  for(i=0;i<n;i++) scanf("%d", &A[i]);

  mergesort(A, 0, n);

  for(i=0;i<n;i++){

    if(i==0) printf("%d", A[i]);

    else printf(" %d", A[i]);

  }printf("\n");

  printf("%d\n", count);

  return 0;

}

  

