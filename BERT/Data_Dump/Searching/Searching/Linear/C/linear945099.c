#include<stdio.h>

main(){

  int i, j, n, q, count = 0, S[10000], T[500];

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i = 0;i < q;i++){
    scanf("%d", &T[i]);
    for(j = 0;j < n;j++){
      if(T[i] == S[j]){
	count++;
	break;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
