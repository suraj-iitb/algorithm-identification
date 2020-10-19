#include<stdio.h>
#define MAX 500000
#define INFTY 1000000000
int L[MAX], R[MAX];
int count;
void merge(int*, int, int, int);
void mergeSort(int*, int, int);
int main(){
  int i;
  int A[MAX], n; 
  count = 0;    
  scanf("%d", &n);
  for (i=0; i<n; i++){
    scanf("%d", &A[i]);
    if (A[i] >= INFTY ){
      return 1;
    }
  }
   
  mergeSort(A, 0, n);
 
  for (i=0; i<n; i++){
    if ( i ) printf(" ");
    printf("%d", A[i]);
    }
  printf("\n"); 
  printf("%d\n", count);
  return 0;
}
 
void merge(int A[], int left, int mid, int right){  
  int i,j,k,n1,n2;
   n1 = mid - left;
   n2 = right - mid;
   for(i=0; i<n1; i++){
     L[i] = A[left + i];
   }    
   for (i=0; i<n2; i++){
     R[i] = A[mid + i];
   }  
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
   
  for (k=left; k<=right-1; k++){    
    count++;   
    if ( L[i] <= R[j] ){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j=j+1;
    }
  }
}
 
void mergeSort(int A[], int left, int right ){
  int mid;  
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}