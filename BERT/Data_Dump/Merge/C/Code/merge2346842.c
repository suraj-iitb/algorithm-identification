#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void mergeSort(int, int);
void merge(int, int, int);

int n, c=0;
int S[500000];

int main(){
  int i;

  scanf("%d",&n);
  if( n<1 || 500000<n ) exit(1);

  for( i=0 ; i<n ; i++ ){
    scanf("%d",&S[i]);
    if( S[i]<0 || 1000000000<S[i] ) exit(2);
  }

  mergeSort(0, n);
  
  for( i=0 ; i<n ; i++ ){
    if(i == n-1){
      printf("%d\n",S[i]);
    }
    else{
      printf("%d ",S[i]);
    }
  }
  printf("%d\n",c);


  return 0;
}

void mergeSort(int left, int right){
  int mid;
  
  if( left+1 < right ){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

void merge(int left, int mid, int right){
  int i,j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1];
  int R[n2+1];

  for( i=0 ; i<n1 ; i++ ){
    L[i] = S[left+i];
  }
  for( i=0 ; i<n2 ; i++ ){
    R[i] = S[mid+i];
  }

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  i=0;
  j=0;
  
  for( k=left ; k<right ; k++ ){
    if(L[i] < R[j]){
      S[k] = L[i];
      i++;
    }
    else{
      S[k] = R[j];
      j++;
    }
    c++;
  }
}
