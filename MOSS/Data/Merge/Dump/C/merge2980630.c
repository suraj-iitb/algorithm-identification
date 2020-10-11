#include<stdio.h>
#define INFTY 2000000000
#define MAX 600000

int i,j,k,L[MAX/2 + 2],R[MAX/2 + 2],C = 0;

void merge(int A[],int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  for(i = 0 ; i < n1 ; i++){
    L[i] = A[left + i];
  }
  for(i = 0 ; i < n2 ; i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left ; k < right ; k++){
    C++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{ 
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int S[MAX],n;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n);

  for(i = 0 ; i < n ; i++){
    if(i)printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",C);
  
  return 0;
}

