#include <stdio.h>

#define MAX 500000
#define SEN 2000000000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);


int L[MAX/2+2];
int R[MAX/2+2];
int count=0;


int main(){
  int A[MAX];
  int i;
  int n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }


  mergeSort(A,0,n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

void merge(int* A,int left,int mid,int right){
  int i,j=0,k=0;
  int nm1=mid-left;
  int nm2=right-mid;
  for(i=0;i<nm1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<nm2;i++){
    R[i]=A[mid+i];
  }
  L[nm1]=SEN;
  R[nm2]=SEN;
  i=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      A[k]=L[i++];
    }else{
      A[k]=R[j++];
    }
  }
}

void mergeSort(int* A,int left,int right){
  int mid;
  if((left+1)<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
