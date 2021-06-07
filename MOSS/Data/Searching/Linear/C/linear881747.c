#include <stdio.h>

int main(){
  long long  n, q, s[10001], t, c = 0, i;
  scanf("%lld", &n);
  for(i = 0; i < n; ++i) scanf("%lld", s + i);

  scanf("%lld", &q);
  while(q--){
    scanf("%lld", &t);
    for(i = 0; i < n; ++i)
      if(t == s[i]){
        c++;
        break;
      }
  }

  printf("%lld\n", c);
  return 0;
}
