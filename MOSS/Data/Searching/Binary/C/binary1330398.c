#include<stdio.h>

#define FOUND '1'
#define NOT_FOUND '0'

int binarySearch(int [1000000], int, int);

int main(){
  int i, n, q, count = 0;
  int S[1000000], T[1000000];

  scanf("%d",&n);

  for(i = 0; i < n; i++) scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i = 0; i < q; i++) scanf("%d",&T[i]);
  
  for(i = 0; i < q; i++){
    if(binarySearch(S, T[i], n) == FOUND) count++;
  }
  
  printf("%d\n",count);

  return 0;
}

int binarySearch(int A[], int key, int n){
  int left = 0, right = n, mid;

  while(left < right){
    mid = (left + right) / 2;

    if(A[mid] == key) return FOUND;

    else if(key < A[mid]) right = mid;

    else left = mid + 1;
  }
  
  return NOT_FOUND;    
}
