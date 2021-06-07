#include <stdio.h>

#define MAX 100000

int binarySearch(int *, int, int);

int main(){

  int n, q, t, cnt = 0;
  int s[MAX], i;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i = 0; i < q; i++) {
    scanf("%d", &t);
    if(s[binarySearch(s, n, t)] == t) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}


int binarySearch(int *s, int n, int key){
  int left = 0, right = n, mid;

  while(left < right){
    mid = (left + right)/2;
if(s[mid] == key) return mid;
  else if (key < s[mid]) right = mid;
  else left = mid + 1;
}
return 0;
}

