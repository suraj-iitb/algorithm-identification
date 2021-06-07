#include<stdio.h>

#define true 1
#define false 0

int binarySearch(int A[], int key, int l, int n){
  int mid;

  if(l < n){
    mid = (l+n)/2;
    if(A[mid] == key) return true;
    if(A[mid] > key) return binarySearch(A, key, l, mid);
    else if(A[mid] < key) return binarySearch(A, key, mid+1, n);
  }
  return false;
}

int main(){
  int S[1000000];
  int i, n, q, key;
  int count = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &key);
    if(binarySearch(S, key, 0, n) == true) count++;
  }

  printf("%d\n", count);

  return 0;
}

