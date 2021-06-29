#include <stdio.h>

int binarySearch();

int main(){
  int n,m,key,A[100001],i,ct=0;
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&A[i]);
  scanf("%d",&m);
  for(i=0; i<m; i++){
    scanf("%d",&key);
    if(binarySearch(A, key, n) != -1) ct++;
  }
  printf("%d\n",ct);
  return 0;
}

int binarySearch(int A[], int key, int n){
  int left = 0, right = n, mid;
  while (left < right){
    mid = (left + right) / 2;
    if (A[mid] == key) return mid;
    else if (key < A[mid]) right = mid;
    else left = mid + 1;
  }
  return -1;
}
