#include <stdio.h>
#define MAX 100000

int S[MAX], n;
int binarySearch(int, int);

int main(){
  int i, q, count = 0, T[MAX];

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
    if(binarySearch(n, T[i]) == 1) count++;
  }
  printf("%d\n",count);

  return 0;
}

int binarySearch(int n, int key){
  int left, right, mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(key == S[mid]) return 1;
    if(key > S[mid]) left = mid + 1;
    else if(key < S[mid]) right = mid;
  }
  return 0;
}
