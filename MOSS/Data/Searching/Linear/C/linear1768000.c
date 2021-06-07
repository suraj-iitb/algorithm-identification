#include<stdio.h>

int search(int[], int, int);


int main(){

  int  S[10000], q, key, count=0,i,n;

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ){ 
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);

  for ( i = 0; i < q; i++ ){
   
    scanf("%d", &key);
    if ( search(S, n, key) == 1 ) count++;
  }
  printf("%d\n", count);


  return 0;
}
int search(int S[], int n, int key){
  int i;

  for ( i = 0; i < n; i++ ){
    if ( S[i] == key ) return 1;
  }
  return 0;
}
