#include <stdio.h>

int main(){
  int n, s[10001], q, t[500], c = 0, key = 0, i, j;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &s[i]);
  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &t[i]);

  for(i = 0; i < q; i++){
    key = t[i];
    j = 0;
    s[n] = key;
    while(key != s[j]) j++;
    if(j == n) continue;
    else c++;
  }
  printf("%d\n", c);

  return 0;
}
