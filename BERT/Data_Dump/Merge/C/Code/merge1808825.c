#include <stdio.h>
#define MAX_DATA 500000
#define N 2000000000

void merge(int[],int,int,int);
void mergeSort(int[],int ,int);
int A[MAX_DATA],count=0;

int main()
{
  int i,n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A,0,n);

  for(i = 0; i <n-1; i++){
    printf("%d ", A[i]);
  }
  printf("%d\n%d\n",A[i],count);
  return 0;
}
void merge(int temp[],int left,int mid,int right){
  int n1, n2, i, j, k, L[MAX_DATA], R[MAX_DATA];

  n1= mid-left;
  n2=right-mid;

  for(i=0;i<n1;i++){
    L[i]=temp[left +i];
  }
  for(j=0;j<n2;j++){
    R[j]=temp[mid+j];
  }
    L[n1]=N;
    R[n2]=N;
    i=0;
    j=0;
   
  for(k=left;k<right;k++){
    count++;
    if(L[i] < R[j]){
      temp[k]=L[i];
      i=i+1;
    }
    else {
      temp[k]=R[j];
      j=j+1;
    }
  }
}
 
void mergeSort(int temp[],int left,int right){
  int mid;
  if(right > left+1){
    mid = (right + left)/2;
    mergeSort(temp, left, mid);
    mergeSort(temp, mid, right);
    merge(temp, left, mid, right);
  }
}
