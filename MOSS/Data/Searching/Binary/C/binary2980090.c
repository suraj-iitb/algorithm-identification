#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int *A, int n, int key);

int main() {
  
  int n,q;
  int *S, *T;
  int i,j;
  int count = 0;
  
  scanf("%d",&n);
  S = (int *)malloc(n * sizeof(int));
  for (i=0; i<n; i++)
    scanf("%d", &S[i]);

    scanf("%d",&q);
  T = (int *)malloc(q * sizeof(int));
  for (i=0; i<q; i++)
    scanf("%d", &T[i]);

  for(i=0; i<q; i++){
    count += BinarySearch(S, n, T[i]);
  }

  printf("%d\n", count);
  
  return 0;
}

int BinarySearch(int *A, int n, int key){

  int right;
  int left = 0;
  int mid;

  right = n;

  while(left < right){
    mid = (left + right) / 2;
    if(key == A[mid]) return 1;
    if(key > A[mid]) left = mid + 1;
    else if(key < A[mid]) right = mid;
    
  }
  return 0;
}

