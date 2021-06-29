#include<stdio.h>
 
#define N 10000
 
int search(int *,int,int);
 
 
int main(){
   
  int i;
  int n, n2;
  int A[N], key;
  int count = 0;
   
  scanf("%d", &n);
   
  for ( i = 0 ; i < n ; i++ ) {
    scanf("%d", &A[i]);
  }
 
   
  scanf("%d", &n2);
   
  for ( i = 0 ; i < n2 ; i++ ){
    scanf("%d", &key);
    if ( search(A, n, key) ){
      count++;
    }
  }
   
  printf("%d\n", count);
 
 
  return 0;
}
 
 
 
int search(int A[], int n, int key){
   
  int i;
   
  for ( i = 0; i < n; i++ ){
     
    if ( A[i] == key ) {
      return 1;
    }
     
  }
  return 0;
}
