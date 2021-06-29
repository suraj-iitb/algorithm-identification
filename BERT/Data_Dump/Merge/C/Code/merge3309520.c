#include <stdio.h>
#include <stdlib.h>
#define MAX 500000
#define INFITY 1000000001

void merge(int [],int,int,int);
void mergeSort(int [] ,int ,int);

int counter=0;

int main(){
  int A[MAX],n,  j;

  scanf("%d",&n);

  for(j=0;j<n;j++){
    scanf("%d",&A[j]);
  }

  mergeSort(A,0,n);
  for(j=0;j<n;j++){
    printf("%d",A[j]);
    if(j<n-1) printf(" ");
  }
  printf("\n%d\n",counter);

  return 0;
}

void merge(int A[],int left,int mid,int right)
{
  int n1,n2,i,j,k,*L,*R;

  n1 = mid - left;
  n2 = right - mid;
  L=malloc((n1+1)*sizeof(int));
  R=malloc((n2+1)*sizeof(int));
  for(i=0;i<=n1-1;i++){
    L[i] = A[left + i];
  }
  for(i=0;i<=n2-1;i++){
    R[i] = A[mid  + i];
  }

  L[n1]=INFITY;
  R[n2] = INFITY;

  i=j=0;
  for(k=left;k<right;k++){

    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      counter++;
    }
    else{
      A[k] = R[j];
      j = j + 1;
      counter++;
    }
  }
  free(L);
  free(R);
}

void mergeSort(int A[],int left, int right){
  if(left+1 < right){
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
