#include <stdio.h>
#define SMAX 10000
#define TMAX 500

int main(){
  int n, q;
  int i, j;
  int S[SMAX], T[TMAX];
  int flag, cnt = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);

  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &T[i]);

  for(i = 0; i < q; i++){
    flag = 0;
    for(j = 0; j < n; j++) if(S[j] == T[i]) flag = 1;
    if(flag == 1) cnt++;
  }

  printf("%d\n", cnt);

  return 0;
}

