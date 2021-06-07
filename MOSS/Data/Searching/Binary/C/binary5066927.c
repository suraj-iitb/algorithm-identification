#include <stdio.h>
#include <stdlib.h>

int search(int *a, int key, int n);

int main(){
  int *s, t, n, q, i, c = 0;

  scanf("%d", &n);
  s = (int *)malloc(n * sizeof(int));
  for(i = 0; i < n; i++) scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &t);
    if(search(s, t, n) != -1) c++;
  }

  printf("%d\n", c);

  return 0;
}

int search(int *s, int key, int n){
  int l = 0, r = n, mid;
  while(l < r){
    mid = (l + r) / 2;
    if(s[mid] == key)return mid;
    else if(key < s[mid]) r = mid;
    else l = mid + 1;
  }
  return -1;
}

