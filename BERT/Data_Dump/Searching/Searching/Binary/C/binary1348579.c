#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100000
#define Q 50000

int main(){

  int i, n, q, cnt = 0;
  int mid, right, left;
  int s[N], t[Q];
 
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &s[i]);
 
  scanf("%d", &q);
  for(i = 0; i < n; i++) scanf("%d", &t[i]);
  
  for(i = 0; i < q; i++){
    right = n;
    left = 0;
 
    while(left <= right){
      mid = (right + left) / 2;
      if(s[mid] == t[i]) {
	cnt++;
	break;
      }
      else if(s[mid] < t[i]) left = mid + 1;
      else if(s[mid] > t[i]) right = mid - 1;
    }
  }

  printf("%d\n", cnt);
 
  return 0;
}
