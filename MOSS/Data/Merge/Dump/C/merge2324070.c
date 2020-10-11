#include<stdio.h>
#include<stdlib.h>

void merge(int *A, int left, int mid, int right);
void mergeSort(int *A, int left, int right);

int count = 0;

int main(){
  int i,n,left,right;
  int *S;
  
  scanf("%d",&n);
  //printf("a\n");
  
  S = (int *)malloc(sizeof(int) * n);

  for(i = 0 ; i < n ; i++)
    scanf("%d",&S[i]);

  left = 0;
  right = n;

  //printf("a\n");
  
  mergeSort(S, left, right);

  //printf("a\n");
  for(i = 0 ; i < n ; i++){
    printf("%d",S[i]);
    if(i < n-1) printf(" ");
  }

  printf("\n%d\n",count);

  
  
  return 0;
}

void merge(int *A, int left, int mid, int right){
  int n1,n2,i,j,k;
  int *L,*R;

  n1 = mid - left;
  n2 = right - mid;

  L = (int *)malloc(sizeof(int) * (n1+1));
  R = (int *)malloc(sizeof(int) * (n2+1));

  for(i = 0 ; i < n1 ; i++)
    L[i] = A[left + i];
      
  for(i = 0 ; i < n2 ; i++)
    R[i] = A[mid + i];
  
  L[n1] = 1000000000;
  
  R[n2] = 1000000000;

  i = 0;
  j = 0;
  
  for(k = left ; k < right ; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      count++;
      
    }
    else{
      A[k] = R[j];
      j = j + 1;
      count++;
    }
  } 
}

void mergeSort(int *A, int left, int right){
  int mid;

  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
  
}
