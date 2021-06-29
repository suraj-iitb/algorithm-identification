#include <stdio.h>
#define N 500000
#define INFTY 1000000000

void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int count;

main(){
  int seq[N];
  int i, n;
  
  scanf("%d", &n);
  
  for( i = 0; i < n; i++){
    scanf("%d", &seq[i]);
  }
  
  mergeSort(seq, 0, n);
  
  for( i = 0; i < n; i++){
    if( i == n-1 ) printf("%d\n", seq[i]);
    else printf("%d ", seq[i]);
  }
  
  printf("%d\n", count);
  
  return 0;

}


void merge(int *seq, int left, int mid, int right){
  int n1, n2, i, j, k;
  int L[N], R[N];
  
  n1 = mid - left;
  n2 = right - mid;
  
  for( i = 0; i < n1; i++){
    L[i] = seq[left+i];
  }
  
  for( i = 0; i < n2; i++){
    R[i] = seq[mid+i];
  }
  
  L[n1] = INFTY;
  R[n2] = INFTY;
  
  i = 0;
  j = 0;
  
  for( k = left; k < right; k++){

    if( L[i] <= R[j] ){
      seq[k] = L[i];
      i = i + 1;
    }
    
    else{
      seq[k] = R[j];
      j = j + 1;
    }

    count++;
    
  }
  
}


void mergeSort(int *seq, int left, int right){
  int mid; 
 
  if( left+1 < right ){
    
    mid = ( left + right ) / 2;
    
    mergeSort(seq, left, mid);

    mergeSort(seq, mid, right);

    merge(seq, left, mid, right);
    
  }

}
