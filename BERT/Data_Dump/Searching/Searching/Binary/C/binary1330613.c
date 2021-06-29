#include <stdio.h>

main(){
  int i, r, l, m, rs, rt, S[100000], T[50000],c = 0;

  scanf("%d", &rs);
  for(i = 0;i < rs;i++) scanf("%d", &S[i]);

  scanf("%d", &rt);
  for(i = 0;i < rt;i++) scanf("%d", &T[i]);

  for(i = 0;i < rt;i++){
    r = rs + 1;
    l = 0;
    while(l < r){
      m = (r + l - 1) / 2;
      if(T[i] < S[m]) r = m;
      else if(T[i] > S[m]) l = m + 1;
      else if(T[i] == S[m]){
	c++;
	break;
      }
    }
  }
  printf("%d\n", c);
  return 0;
}
