#include <stdio.h>
#include <stdlib.h>

int search(int *a, int key, int n);

int main(){
  int *s, t, n, q, i, c = 0;

  scanf("%d", &n);
  s = (int *)malloc((n+1) * sizeof(int));
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
  int i = 0;
  s[n] = key;
  while(s[i] != key) i++;
  if(i == n) return -1;
  return i;
}

