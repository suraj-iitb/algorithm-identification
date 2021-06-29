#include<stdio.h>

int search(int A[], int n, int key){
  int i;
  for ( i = 0; i < n; i++ ){
  if ( A[i] == key )
    return 1;
  }
  return 0;
}

int main(){
  int  n, A[10000], q, key, sum = 0;
  int i= 0;
  int z=0;
  scanf("%d", &n);
  while (i<n){
    scanf("%d", &A[i]);
    i++;
  }

  scanf("%d", &q);
  for ( i = 0; i < q; i++ ){
    scanf("%d", &key);
    if ( search(A, n, key) ) sum++;
  }
  z=i+z;
  printf("%d\n", sum);


  return 0;


}

