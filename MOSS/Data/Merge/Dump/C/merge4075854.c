
    
#include <stdio.h>
#include <math.h>

#define N 500000

int count=0;

void merge(int A[], int left, int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int i,j,k,L[N/2+2],R[N/2+2];

  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<= R[j]){
      A[k]=L[i];
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
    }
  }
}

void mergesort(int A[], int left, int right){
  int mid;
  if(left+1<right){
    mid =(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int i,n,A[500000];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergesort(A,0,n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

