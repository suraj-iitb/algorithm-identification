#include<stdio.h>
#define MAX 10000
main(){
  int i, j;
  int n, q;
  int S[MAX], T[MAX],count = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for(i = 0; i < q; i++){

    for(j =0; j < n; j++)
      if(T[i] == S[j]){
        count++;
        break;
      }
  }
  printf("%d\n",count);

return 0;
}