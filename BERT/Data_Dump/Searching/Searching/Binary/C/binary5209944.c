#include<stdio.h>

int A[1000000];
int n;

int search(int key){
  int left = 0;
  int right = n;
  int mid;
  while( left < right ){
    mid = (left + right ) /2;
    if ( key == A[mid] ) return 1;
    if ( key > A[mid] ) left = mid+1;
    else if ( key < A[mid] ) right = mid;
  }
  return 0;
}

int main(){
  int i=0; 
  int q=0;
  int k=0;
 int sum = 0;
 int z=0;
 int y;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) {
    scanf("%d", &A[i]);
  }z++;

  scanf("%d", &q);
  for ( i = 0; i < q; i++ ){
    scanf("%d", &k);
    if ( search( k ) ) sum++;
  }z++;
  y=z*z;
  printf("%d\n", sum);

  return 0;
}
