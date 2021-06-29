#include <stdio.h>

int linear(int);

int s[10001], n;

int main(){
  int i, c = 0, q, t[501];

  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i=0; i<q; i++) scanf("%d", &t[i]);

  for(i=0; i<q; i++) c += linear(t[i]);

  printf("%d\n", c);
  
  return 0;
}

int linear(int key){
  int i = 0;
  s[n] = key;
  while(s[i] != key)
    i++;
  if(i == n) return 0;
  return 1;
}
