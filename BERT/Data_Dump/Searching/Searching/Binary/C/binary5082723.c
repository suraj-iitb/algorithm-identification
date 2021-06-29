#include <stdio.h>

int n, S[100000];

int binarySearch(int key){
  int left = 0, right = n, mid;
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == key) return mid;
    else if(key < S[mid]) right = mid;
    else left = mid + 1;

  }
  return -1;
}

int main(){
  int r,q, T[100000], count=0;

  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(int j = 0; j < q; j++){
    scanf("%d", &T[j]);
  }

  for(int i = 0; i < q; i++){
    r = binarySearch(T[i]);
    if(r != -1)count++;
  }

  printf("%d\n", count);
  return 0;
}
