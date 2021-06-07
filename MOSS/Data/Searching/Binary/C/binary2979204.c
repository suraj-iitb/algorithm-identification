#include<stdio.h>

int n,A[100000];

int main() {
  int i,q,key,answer=0;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++) {
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);
  for(i = 0 ; i < q ; i++) {
    scanf("%d",&key);
    if(binarySearch(key))
      answer++;
  }
  printf("%d\n",answer);
  return 0;
}

int binarySearch(int key) {
  int left=0,right=n,mid=0;

  while(left < right) {
    mid = (left + right) / 2;
    if(A[mid] == key) return 1;
    else if(key < A[mid]) right = mid;
    else left = mid +1;
  }
  return 0;
}

