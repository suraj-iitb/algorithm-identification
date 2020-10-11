#include<stdio.h>
#define N 500000
#define M 2000000000

void merge(int [],int,int,int);
void mergeSort(int [],int,int);

int L[N/2+2],R[N/2+2];
int count=0;


void merge(int A[],int left,int mid,int right){
  int n1;
  int n2;
  int i,j,k;
  n1=mid-left;
  n2=right-mid;

  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1]=R[n2]=M;
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
}

void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);

  }
}

main(){

  int A[N],n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A,0,n);

 for(i=0;i<n-1;i++){
   printf("%d ",A[i]);
 }
 printf("%d\n",A[n-1]);
 printf("%d\n",count);
 return 0;
}
