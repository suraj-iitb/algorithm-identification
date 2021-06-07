#include <stdio.h>

int main(){
  int n, s[100000], q, t;
  int i, j, c = 0;
  int l, m, r;

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &s[i]);
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &t);

    l = 0;
    r = n;
    while(l < r){
      m = (l + r) / 2;
      if(t == s[m]){
        c++;
        break;
      }
      if(t > s[m])
        l = m + 1;
      else if(t < s[m])
        r = m;
    }
  }

  printf("%d\n", c);

  return 0;
}

