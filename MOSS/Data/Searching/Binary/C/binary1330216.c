#include <stdio.h>

int n, q;
int binarySearch(int *, int); 

int main(){

  int S[100000], T[50000];
  int i, count=0;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &T[i]);
    if(binarySearch(S, T[i]) == 1) count++;
  }

  printf("%d\n", count);

  return 0;
}

int binarySearch(int *A, int key){
  int right, left, mid;

  left = 0;
  right = n;

  while(left < right){
    mid = (left + right)/2;

    if(key == A[mid]) return 1;

    if(key > A[mid]) left = mid + 1;
    else if(key < A[mid]) right = mid;

  }
    return 0;
}
