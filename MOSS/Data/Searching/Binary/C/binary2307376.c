#include <stdio.h>

int binary(int);

int s[100001], n;

int main(){
  int i, c = 0, q, t[50001];

  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i=0; i<q; i++) scanf("%d", &t[i]);

  for(i=0; i<q; i++) c += binary(t[i]);

  printf("%d\n", c);
  
  return 0;
}

int binary(int key){
  int left = 0, right = n, mid;

  while(left < right){
    mid = (left + right) / 2;
    if(s[mid] == key) return 1;
    else if(key < s[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}
