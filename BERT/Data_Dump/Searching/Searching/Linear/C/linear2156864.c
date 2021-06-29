#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i, j, n, *s, q, *t, c = 0;

  scanf("%d", &n);
  s = (int *)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }
  scanf("%d", &q);
  t = (int *)malloc(sizeof(int) * q);
  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);
  }

  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(t[i] == s[j]){
	c++;
	break;
      }
    }
  }
  printf("%d\n", c);
  free(s);
  free(t);
  return 0;
}
