#include<stdio.h>
#include<math.h>

#define N 500000

void merge(int*,int,int,int);
void mergeSort(int*,int,int);

int count=0;

int main(){
  int i,j,a,A[N];

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A,0,a);

  printf("%d",A[0]);
  for(i=1;i<a;i++){
    printf(" %d",A[i]);
  }

  printf("\n%d\n",count);

  return 0;
}

void merge(int *A,int left,int mid,int right){
  int n1,n2,i=0,k,j=0;
  n1=mid-left;
  n2=right-mid;
  int L[n1],R[n2];

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
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
      count++;
    }
    else{
      A[k]=R[j];
      j=j+1;
      count++;
    }
  }

  return;
}
  
void mergeSort(int *A,int left,int right){
  int mid;
  
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }

  return;
}

