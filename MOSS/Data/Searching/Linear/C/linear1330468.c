#include <stdio.h>

int main(){
  int i, j, k, n, q, S[100000], T[100000];
  k = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);

  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &T[i]);

  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(T[i] == S[j]){
	k++;
	break;
      }
    }
  }

  printf("%d\n", k);

  return 0;
}
