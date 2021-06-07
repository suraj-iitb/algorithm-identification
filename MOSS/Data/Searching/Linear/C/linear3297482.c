#include<stdio.h>

int main(){
  int i, j, S[10000], T[500], n, q, cnt=0;
  scanf("%d", &n);
  if(n > 0 && n <= 10000){
    for(i = 0; i < n; i++)
      scanf("%d", &S[i]);

    scanf("%d", &q);
    if(q > 0 && q <= 500){
      for(i = 0; i < q; i++)
	scanf("%d", &T[i]);

      for(j = 0; j < q; j++){
	i = 0;
	S[n] = T[j];
	while(S[i] != T[j])
	  i++;
	if(i != n)
	  cnt++;
      }
      printf("%d\n", cnt);
    }
  }
  return 0;
}

