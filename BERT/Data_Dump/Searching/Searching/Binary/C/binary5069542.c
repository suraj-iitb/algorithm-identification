#include <stdio.h>

int binarySearch(int n, int A[], int key){
  int mid;
  int left = 0;
  int right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(key == A[mid]) return mid;
    if(key > A[mid]) left = mid + 1;
    else if(key < A[mid]) right = mid;
  }

  return -1;
}

int main(){
  int i, n, q, A[100000], key, sum = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &A[i]);
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &key);
    if(binarySearch(n, A, key) != -1) sum++;
  }
  printf("%d\n", sum);

  return 0;
}

