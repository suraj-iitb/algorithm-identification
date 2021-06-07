#include <stdio.h>

int main(){
  int n, s[100000], q, t[50000], c = 0, key = 0, left, mid, right, i, j;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &s[i]);
  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &t[i]);

  for(i = 0; i < q; i++){
    key = t[i];
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      if(key == s[mid]){
	c++;
	break;
      }
      else if(key < s[mid]) right = mid;
      else left = mid + 1;
    }
  }
  printf("%d\n", c);

  return 0;
}
