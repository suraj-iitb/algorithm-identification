#include <stdio.h>

int main() {
  int n, q, C = 0;
  int S[10000], T[500];
  int i, j;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", S+i);
    
  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", T+i);

  for(i = 0; i < q; i++) {
    for(j = 0; j < n; j++) {
      if(T[i] == S[j]) {
	C++;
	break;
      }
    }
  }

  printf("%d\n", C);
  
  return 0;
}
