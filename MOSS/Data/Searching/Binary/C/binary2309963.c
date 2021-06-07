#include<stdio.h>

#define N 100000

int search(int key);

int A[N];
int n;



int main(){
  
  int i, n2;
  int key, count = 0;

  
  scanf("%d", &n);
  
  for ( i = 0; i < n; i++ ) {
    
    scanf("%d", &A[i]);
    
  }

  scanf("%d", &n2);
  
  for ( i = 0; i < n2; i++ ){
    
    scanf("%d", &key);
    
    if ( search( key ) ) {
      
      count++;
      
    }
    
  }
  printf("%d\n", count);

  return 0;
}


int search(int key){
  
  int left = 0;
  int right = n;
  int mid;
  
  while( left < right ){
    
    mid = (left + right ) /2;
    if ( key == A[mid] ) return 1;
    if ( key > A[mid] ) left = mid + 1;
    else if ( key < A[mid] ) right = mid;
    
  }
  
  return 0;
}
