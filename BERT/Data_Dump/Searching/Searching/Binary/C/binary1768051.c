#include<stdio.h>

int search(int);

int  S[100000], q, key, count=0,i,n,mid;
int main(){

 

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ){ 
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);

  for ( i = 0; i < q; i++ ){
   
    scanf("%d", &key);
    if ( search(key)) count++;
  }
  printf("%d\n", count);


  return 0;
}
int search(int key){
  int left =0;
  int right = n;

  while(left < right){
    mid = (left + right)/ 2;
    if( S[mid]== key) return 1;
      
    else if(key < S[mid]){
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return 0;
}
